#include <ros/ros.h>
#include <std_msgs/String.h>
#include <gazebo/gazebo_client.hh>
#include <gazebo/transport/transport.hh>

class CheckCollision
{
  private:
  // ros NodeHandle and loop rate
  ros::NodeHandle n;

  // parameters
  std::string world_name;
  std::string robot_name;

  // subscribers
  gazebo::transport::SubscriberPtr sub_contacts;

  // publisher
  ros::Publisher collision = n.advertise<std_msgs::String>("collision", 1000);

public:
  CheckCollision(){

    // gazebo transport node initialization
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();

    // parameters
    n.getParam("hera_check_collision/world_name", world_name);
    n.getParam("hera_check_collision/robot_name", robot_name);

    // subscribers
    sub_contacts = node->Subscribe("/gazebo/"+world_name+"/physics/contacts", &CheckCollision::contactsCallback, this);

  }

  ~CheckCollision()
  {
    gazebo::client::shutdown();
  }

  void start()
  {
    ROS_INFO_STREAM("world_name: " << world_name);
    ROS_INFO_STREAM("robot_name: " << robot_name);
    ros::spin();
  }


  void contactsCallback(ConstContactsPtr &_msg)
  {
    std::string collision_obj_1 = "";
    std::string collision_obj_2 = "";
    std_msgs::String collision_msg;
    collision_msg.data = "";

    for (size_t i = 0; i < _msg->contact_size() ; i++)
    {
      collision_obj_1 = _msg->contact(i).collision1();
      collision_obj_2 = _msg->contact(i).collision2();

      if (collision_obj_1.rfind("ground_plane", 0) == 0 or
          collision_obj_2.rfind("ground_plane", 0) == 0)
      {
        continue;
      }

      if (collision_obj_1.rfind(this->robot_name, 0) == 0)
      {
        collision_msg.data = collision_obj_2;
        break;
      }
      if (collision_obj_2.rfind(this->robot_name, 0) == 0)
      {
        collision_msg.data = collision_obj_1;
        break;
      }
    }

    if(collision_msg.data != ""){
      this->collision.publish(collision_msg);
    }
  }

};


int main(int argc, char **argv){

  // init gazebo and ros
  ros::init(argc, argv, "hera_check_collision");
  gazebo::client::setup(argc, argv);

  // start node
  CheckCollision* c = new CheckCollision();
  c->start();

  return 0;
}
