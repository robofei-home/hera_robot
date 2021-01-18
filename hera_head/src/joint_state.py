#!/usr/bin/env python

# Author: Lucas Iervolino Gazignato

import rospy

from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import JointState

rospy.init_node('head_joint_state', anonymous=True)

def callback(data):
    joint_states = JointState()

    joint_states.header.stamp = rospy.Time.now()

    pan = data.data[0]
    tilt = data.data[1]

    joint_states.name.append('head_joint') 
    joint_states.position.append(pan)

    joint_states.name.append('kinect_joint')
    joint_states.position.append(tilt)

    pub.publish(joint_states)

sub = rospy.Subscriber('/head_topic/current_pos', Float32MultiArray, callback)
pub = rospy.Publisher('/head/joint_state', JointState, queue_size=20)

rospy.spin()
