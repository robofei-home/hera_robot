#!/usr/bin/env python

from __future__ import division
from head import Head
import math
import rospy
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Point

if __name__ == '__main__':
    rospy.init_node('head_test', anonymous = True)
    
    try:
        robot_head = Head()
        robot_head.look_down(3)
        robot_head.look_to_left(3)
        robot_head.look_up(3)
        robot_head.look_to_right(5)
        robot_head.reset()
    except rospy.ROSInterruptException:
        pass