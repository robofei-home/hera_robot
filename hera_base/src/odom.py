#!/usr/bin/env python

# Author: Lucas Iervolino Gazignato

import rospy
import tf

from std_msgs.msg import Int32MultiArray
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3

import math
from math import sin, cos, pi

class Odom():
    DISTANCE_PER_COUNT = math.pi * 0.2032 / 2765 # PI * D / COUNTS_PER_REVOLUTION
    WHEEL_DISTANCE_X = 0.2045335 # Half of the distance between front wheels
    WHEEL_DISTANCE_Y = 0.206375 # Half of the distance between front wheels and the rear wheels

    def __init__(self):
        self.x = 0
        self.y = 0
        self.th = 0

        self.odom_broadcaster = tf.TransformBroadcaster()

        topic = rospy.get_param('~topic', '/odom')
        self.odom_pub = rospy.Publisher(topic, Odometry, queue_size=50)

        rospy.Subscriber('/robot_base/encoders', Int32MultiArray, self.enc_cb)

        rospy.loginfo('Computing odom data...')

    def computeOdom(self, vx, vy, vth, dt):
        current_time = rospy.Time.now()

        delta_x = (vx * cos(self.th) - vy * sin(self.th)) * dt
        delta_y = (vx * sin(self.th) + vy * cos(self.th)) * dt
        delta_th = vth * dt

        self.x += delta_x
        self.y += delta_y
        self.th += delta_th

        odom_quat = tf.transformations.quaternion_from_euler(0, 0, self.th)

        self.odom_broadcaster.sendTransform(
            (self.x, self.y, 0.0),
            odom_quat,
            current_time,
            'base_footprint',
            'odom'
        )

        odom = Odometry()
        odom.header.stamp = current_time
        odom.header.frame_id = 'odom'

        odom.pose.pose = Pose(Point(self.x, self.y, 0.0), Quaternion(*odom_quat))

        odom.child_frame_id = 'base_footprint'
        odom.twist.twist = Twist(Vector3(vx, vy, 0), Vector3(0, 0, vth))

        self.odom_pub.publish(odom)

    def enc_cb(self, enc_msg):
        deltaTime = 50.0 / 1000 # 50 ms (ODOM_PERIOD)

        v1 = enc_msg.data[0] * Odom.DISTANCE_PER_COUNT / deltaTime
        v2 = enc_msg.data[1] * Odom.DISTANCE_PER_COUNT / deltaTime
        v3 = enc_msg.data[2] * Odom.DISTANCE_PER_COUNT / deltaTime
        v4 = enc_msg.data[3] * Odom.DISTANCE_PER_COUNT / deltaTime

        # Mecanum Inverse Kinematics
        vx = (v1 + v2 + v3 + v4) / 4
        vy = (- v1 + v2 + v3 - v4) / 4
        vth = (- v1 + v2 - v3 + v4) / (4 * (Odom.WHEEL_DISTANCE_X + Odom.WHEEL_DISTANCE_Y))

        # Error Correction
        if abs(vx) < 0.015: vx = 0
        if abs(vy) < 0.015: vy = 0
        if abs(vth) < 0.015: vth = 0

        self.computeOdom(vx, vy, vth, deltaTime)

if __name__ == '__main__':
    rospy.init_node('robot_base_odom', log_level=rospy.INFO)
    Odom()

    try:
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
