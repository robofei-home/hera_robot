#ifndef _ROS_SERVICE_AddTwoInts_h
#define _ROS_SERVICE_AddTwoInts_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_basics
{

static const char ADDTWOINTS[] = "ros_basics/AddTwoInts";

  class AddTwoIntsRequest : public ros::Msg
  {
    public:
      typedef int64_t _x_type;
      _x_type x;
      typedef int64_t _y_type;
      _y_type y;

    AddTwoIntsRequest():
      x(0),
      y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int64_t real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int64_t real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
     return offset;
    }

    const char * getType(){ return ADDTWOINTS; };
    const char * getMD5(){ return "3b834ede922a0fff22c43585c533b49f"; };

  };

  class AddTwoIntsResponse : public ros::Msg
  {
    public:
      typedef int64_t _sum_type;
      _sum_type sum;

    AddTwoIntsResponse():
      sum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_sum;
      u_sum.real = this->sum;
      *(outbuffer + offset + 0) = (u_sum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sum.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sum.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sum.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sum.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sum.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_sum;
      u_sum.base = 0;
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sum.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sum = u_sum.real;
      offset += sizeof(this->sum);
     return offset;
    }

    const char * getType(){ return ADDTWOINTS; };
    const char * getMD5(){ return "b88405221c77b1878a3cbbfff53428d7"; };

  };

  class AddTwoInts {
    public:
    typedef AddTwoIntsRequest Request;
    typedef AddTwoIntsResponse Response;
  };

}
#endif
