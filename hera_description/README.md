# hera_description

This package contains the URDF Description model and simulation of the [HERA robot (2020 version)](http://robofei.aquinno.com/athome/wp-content/uploads/2020/01/TDP2020ROBOFEI.pdf), developed by the [RoboFEI@home Team](http://robofei.aquinno.com/athome/) in the [FEI University Center](https://portal.fei.edu.br/).

<figure align="center">
<img src=doc/HERA.png>
<p>O Robô HERA.</p>
</figure>

# Dependencies:
* [ROS](https://www.ros.org/) ([Melodic Morenia](http://wiki.ros.org/melodic))
  * [gazebo_ros](http://wiki.ros.org/gazebo_ros)
  * [roslaunch](http://wiki.ros.org/roslaunch)
  * [rviz](http://wiki.ros.org/rviz)
  * [robot_state_publisher](http://wiki.ros.org/robot_state_publisher)
  * [joint_state_publisher](http://wiki.ros.org/joint_state_publisher)
  * [joint_state_publisher_gui](http://wiki.ros.org/joint_state_publisher)
  * [controller_manager](http://wiki.ros.org/controller_manager)
  * [urdf](http://wiki.ros.org/urdf)
  * [xacro](http://wiki.ros.org/xacro)

# Launch:
There are a folder called ```launch```, that contains files used to launch the robot using roslaunch in the ROS ecosystem.

```
  |-- launch
    |-- load_description.launch
    |-- vizualize_model.launch
```

* **load_description**: Used to load the robot model in ROS and Gazebo. Parameters:
  * **robot_model**: (string, default: hera_full) - Robot used. Available into 'robots' folder.
  * **robot_name**: (string, default: robot) - Robot name used as reference in simulation.
  * **init_pos_x**: (double, default: 0.0) - Position x of the robot in simulation.
  * **init_pos_y**: (double, default: 0.0) - Position y of the robot in simulation.
  * **init_pos_z**: (double, default: 0.0) - Position z of the robot in simulation.
  * **init_yaw**: (double, default: 0.0) - yaw of the robot in simulation.
  * **use_jsp_gui**: (boolean, default: false) - Start joint_state_publisher gui
* **vizualize_model**: Used to visualize the robot. Init gazebo, rviz and call **load_description**. Parameters:
  * **robot_model**: (string, default: hera_full) - Same as **load_description**.
  * **enable_rviz**: (bool, default:true) - Start rviz.
  * **enable_gazebo**: (bool, default:true) - Start gazebo.

# Meshes:
There are a folder called ```meshes```, that contains all meshes used to composite the robot visualization. The robot visual parts were modeled by
[William Yaguiu](mailto:williamyaguiu@gmail.com) with [Solidworks 2018](https://www.solidworks.com/) and [SolidWorks to URDF Exporter](http://wiki.ros.org/sw_urdf_exporter) plugin and the sensors were exported from [GrabCAD Community](https://grabcad.com/).

```
  |-- meshes
    |--asus_xtion.stl
    |--base.stl
    |--head.stl
    |--hokuyo_urg.dae
    |--hokuyo_utm.stl
    |--kinect_one.stl
    |--torso.stl
    |--torso_sensor_plat.stl
    |--wheelB.stl
    |--wheelF.stl

```

<figure align="center">
<img src="doc/asus_xtion.png" width="250">
<img src="doc/base.png" width="250">
<br/>
<img src="doc/head.png" width="250">
<img src="doc/hokuyo_urg.png" width="250">
<br/>
<img src="doc/hokuyo_utm.png" width="250">
<img src="doc/kinect_one.png" width="250">
<br/>
<img src="doc/torso.png" width="250">
<img src="doc/torso_sensor_plat.png" width="250">
<br/>
<img src="doc/wheelB.png" width="250">
<img src="doc/wheelF.png" width="250">
<p>Meshes used to compose the robot.</p>
</figure>

# Robots:
Different robot versions are available.

```
  |-- robots
    |--hera_1.urdf.xacro
    |--hera_2.urdf.xacro
    |--hera_3.urdf.xacro
    |--hera_4.urdf.xacro
    |--hera_full.urdf.xacro
```

* **hera_1**: base
  * Links and Joints: [hera_1](doc/hera_1.pdf).

<figure align="center">
<img src="doc/1-1-collision.png" width="250">
<img src="doc/1-1-visual.png" width="250">
<br/>
<img src="doc/1-2-collision.png" width="250">
<img src="doc/1-2-visual.png" width="250">
<p>Collision mode (left) and visual mode (right).</p>
</figure>

* **hera_2**: base + torso
  * Links and Joints: [hera_2](doc/hera_2.pdf).

<figure align="center">
<img src="doc/2-1-collision.png" width="250">
<img src="doc/2-1-visual.png" width="250">
<br/>
<img src="doc/2-2-collision.png" width="250">
<img src="doc/2-2-visual.png" width="250">
<p>Collision mode (left) and visual mode (right).</p>
</figure>

* **hera_3**: base + torso + head
  * Links and Joints: [hera_3](doc/hera_3.pdf).

<figure align="center">
<img src="doc/3-1-collision.png" width="250">
<img src="doc/3-1-visual.png" width="250">
<br/>
<img src="doc/3-2-collision.png" width="250">
<img src="doc/3-2-visual.png" width="250">
<p>Collision mode (left) and visual mode (right).</p>
</figure>

* **hera_4**: base + torso + manipulator (**Not done yet - same as hera_3**)
<br/><br/>

* **hera_full**: base + torso + head + manipulator (**Not done yet - same as hera_3**)

# URDF
There are a folder called ```urdf```, that contains all urdf code used to model the robot.

```
  |-- urdf
    |--actuators
      |--base.urdf.xacro
      |--head.urdf.xacro
      |--manipulator.urdf.xacro
      |--torso.urdf.xacro
    |--sensors
      |--asus_xtion.urdf.xacro
      |--hokuyo_urg.urdf.xacro
      |--hokuyo_utm.urdf.xacro
      |--kinect_one.urdf.xacro
    |--simulation
      |--colors.gazebo.xacro
      |--control.gazebo.xacro
      |--base.gazebo.xacro
      |--asus_xtion.gazebo.xacro
      |--hokuyo_urg.gazebo.xacro
      |--hokuyo_utm.gazebo.xacro
      |--kinect_one.gazebo.xacro
    |--commons.urdf.xacro
```

* **colors**: Colors used on gazebo.
* **actuators**: Code used in actuators.
* **sensors**: Code used in sensors.
* **simulation**: Gazebo plugins used for simulation.
* **commons**: Macros used in all files.

---

# How to use this repository

1. Make sure do you have a [ROS environment](http://wiki.ros.org/melodic/Installation/Ubuntu) installed and ready.
2. [Create your catkin workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
3. Create a ```src``` folder in your catkin workspace (if it doesn't exist).
```bash
cd <catkin_workspace>/
mkdir src
```
4. Git clone this repository and install all dependencies.
```bash
cd src
git clone https://gitlab.com/fpimentel/hera/hera_description.git
sudo ./hera_description/install_dependencies.sh
```
5. Compile you catkin workspace.
```bash
cd <catkin_workspace>/
catkin_make
source devel/setup.bash
```
6. Now you are ready to run one of the launch files. Try this one:
```bash
roslaunch hera_description vizualize_model.launch
```

You will be able to see this interface for rviz:
<figure align="center">
<img src="doc/rviz.png" width="250">
<p>RViz interface.</p>
</figure>

And this interface for gazebo:
<figure align="center">
<img src="doc/gazebo.png" width="250">
<p>Gazebo interface.</p>
</figure>

## Tools:

* **xacro**: Used to convert xacro file to urdf file. ex:
```
  $ rosrun xacro xacro `rospack find hera_description`/robots/hera_full.urdf.xacro > hera.urdf
```
* **check_urdf**: Used to check the urdf consistency. ex:
```
  $ check_urdf hera.urdf
```
* **urdf_to_graphiz**: Used to generate a pdf with robot links and joints. ex:
```
  $ urdf_to_graphiz hera.urdf
```
