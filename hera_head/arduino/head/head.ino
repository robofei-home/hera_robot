#include <VarSpeedServo.h>
#include <ros.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Float32MultiArray.h>

int panServo_pin = 2;
int tiltServo_pin = 4;
int tilt_offset = 0;

VarSpeedServo panServo;
VarSpeedServo tiltServo;

ros::NodeHandle nh;

std_msgs::Float32MultiArray head_pos;
ros::Publisher pub("/head_topic/current_pos", &head_pos);

int ConvertToDeg(float rad) {
  float deg = abs(((rad * 4068) / 71) + 90);
  return (int) round(deg);
}

float ConvertToRad(int deg) {
  float rad = (deg * 71 - 6390) / 4068.0;
  return rad;
}

void stop_movement() {
  panServo.stop();
  tiltServo.stop();
}

void moveHead(int pan_pos, int tilt_pos) {
  pan_pos = constrain(pan_pos, 0, 180);
  tilt_pos = constrain(tilt_pos, 0, 90);
  panServo.write(pan_pos, 20, false);
  tiltServo.write(tilt_pos+tilt_offset, 20, false);
}

void head_callback(const std_msgs::Float32MultiArray& angles)
{
  float pan = angles.data[0];
  float tilt = angles.data[1];
  stop_movement();
  moveHead(ConvertToDeg(pan), ConvertToDeg(tilt-(6390/4068.0)));
}

ros::Subscriber<std_msgs::Float32MultiArray> sub("head_topic/goal_pos", head_callback);

void getCurrentPos() {
  head_pos.data[0] = ConvertToRad(panServo.read());
  head_pos.data[1] = ConvertToRad(tiltServo.read() + 90 - tilt_offset);
}

void setup() {
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(pub);

  panServo.write(90);
  tiltServo.write(0+tilt_offset);
  panServo.attach(panServo_pin);
  tiltServo.attach(tiltServo_pin);

  head_pos.data = (float *)malloc(sizeof(float) * 2);
  head_pos.data_length = 2;
}

void loop() {
  getCurrentPos();
  pub.publish(&head_pos);
  nh.spinOnce();
  delay(100);
}
