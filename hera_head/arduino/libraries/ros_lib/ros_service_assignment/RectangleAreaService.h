#ifndef _ROS_SERVICE_RectangleAreaService_h
#define _ROS_SERVICE_RectangleAreaService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_service_assignment
{

static const char RECTANGLEAREASERVICE[] = "ros_service_assignment/RectangleAreaService";

  class RectangleAreaServiceRequest : public ros::Msg
  {
    public:
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;

    RectangleAreaServiceRequest():
      width(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
     return offset;
    }

    const char * getType(){ return RECTANGLEAREASERVICE; };
    const char * getMD5(){ return "ed3043f094c99bdd8118bc5b0ddb14ba"; };

  };

  class RectangleAreaServiceResponse : public ros::Msg
  {
    public:
      typedef float _area_type;
      _area_type area;

    RectangleAreaServiceResponse():
      area(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_area;
      u_area.real = this->area;
      *(outbuffer + offset + 0) = (u_area.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_area.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_area.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_area.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->area);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_area;
      u_area.base = 0;
      u_area.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_area.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_area.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_area.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->area = u_area.real;
      offset += sizeof(this->area);
     return offset;
    }

    const char * getType(){ return RECTANGLEAREASERVICE; };
    const char * getMD5(){ return "ba46cd039de682077b3eaa09c3500c5c"; };

  };

  class RectangleAreaService {
    public:
    typedef RectangleAreaServiceRequest Request;
    typedef RectangleAreaServiceResponse Response;
  };

}
#endif
