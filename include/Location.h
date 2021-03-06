// Generated by gencpp from file HDMap/Location.msg
// DO NOT EDIT!


#ifndef HDMAP_MESSAGE_LOCATION_H
#define HDMAP_MESSAGE_LOCATION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace HDMap
{
template <class ContainerAllocator>
struct Location_
{
  typedef Location_<ContainerAllocator> Type;

  Location_()
    : header()
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)  {
    }
  Location_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef double _roll_type;
  _roll_type roll;





  typedef boost::shared_ptr< ::HDMap::Location_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::HDMap::Location_<ContainerAllocator> const> ConstPtr;

}; // struct Location_

typedef ::HDMap::Location_<std::allocator<void> > Location;

typedef boost::shared_ptr< ::HDMap::Location > LocationPtr;
typedef boost::shared_ptr< ::HDMap::Location const> LocationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::HDMap::Location_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::HDMap::Location_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace HDMap

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/lunar/share/geometry_msgs/cmake/../msg'], 'HDMap': ['/media/vincent/DATA/Ubuntu/Project/catkin_ws/src/HDMap/msg'], 'std_msgs': ['/opt/ros/lunar/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::HDMap::Location_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::HDMap::Location_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::HDMap::Location_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::HDMap::Location_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::HDMap::Location_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::HDMap::Location_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::HDMap::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a817d49d0d7220129c42d1fc2319ee7";
  }

  static const char* value(const ::HDMap::Location_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a817d49d0d72201ULL;
  static const uint64_t static_value2 = 0x29c42d1fc2319ee7ULL;
};

template<class ContainerAllocator>
struct DataType< ::HDMap::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "HDMap/Location";
  }

  static const char* value(const ::HDMap::Location_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::HDMap::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 yaw\n\
float64 pitch\n\
float64 roll\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::HDMap::Location_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::HDMap::Location_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.roll);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Location_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::HDMap::Location_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::HDMap::Location_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "roll: ";
    Printer<double>::stream(s, indent + "  ", v.roll);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HDMAP_MESSAGE_LOCATION_H
