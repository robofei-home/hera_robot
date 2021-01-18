from __future__ import division
import math
import rospy
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Point

class Head():

    def __init__(self):
        self.goal = Float32MultiArray()
        self.goal.data.append(0)
        self.goal.data.append(0)
        
        self.goalPub = rospy.Publisher("/head_topic/goal_pos", Float32MultiArray, queue_size=1)

    def reset(self, timeout = 0):
        zero_pos = Point(0.0, 0.0, 0.0)
        self.look_at_point(zero_pos, timeout)
    
    def look_to_left(self, timeout = 0):
        z = math.tan(self.goal.data[1])
        left = Point(0.0, 1.0, z)
        self.look_at_point(left, timeout)
    
    def look_to_right(self, timeout = 0):
        z = math.tan(self.goal.data[1])
        right = Point(0.0, -1.0, z)
        self.look_at_point(right, timeout)

    def look_up(self, timeout = 0):
        y = math.tan(self.goal.data[0])
        up = Point(1.0, y, 0)
        self.look_at_point(up, timeout)
    
    def look_down(self, timeout = 0):
        y = math.tan(self.goal.data[0])
        z = math.tan((math.pi/3) * math.sqrt(1 + y**2))
        down = Point(1.0, y, z)
        self.look_at_point(down, timeout)
        
    def look_at_point(self, point, timeout = 0):
        #look at point with reference on tilt_frame
        assert isinstance(point, Point)
        self.goal.data[0] = math.atan2(point.y, point.x)
        self.goal.data[1] = math.atan2(point.z, math.sqrt(point.x**2 + point.y**2))
        rospy.sleep(0.25)
        self.goalPub.publish(self.goal)
        self.wait_for_motion(timeout)
    
    def go_to_position(self, pan_angle, tilt_angle, timeout = 0):
        #move to specified position
        self.goal.data[0] = pan_angle
        self.goal.data[1] = tilt_angle
        rospy.sleep(0.25)
        self.goalPub.publish(self.goal)
        self.wait_for_motion(timeout)
            
    def wait_for_motion(self, timeout = 3.0):
        time = rospy.Time.now()
        if timeout != 0:
            rospy.loginfo("Waiting %0.2f seconds for the movement be done ..."%timeout)
            while (rospy.Time.now() - time) < rospy.Duration(timeout):
                rospy.sleep(0.1)
