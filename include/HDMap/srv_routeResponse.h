// Generated by gencpp from file HDMap/srv_routeResponse.msg
// DO NOT EDIT!


#ifndef HDMAP_MESSAGE_SRV_ROUTERESPONSE_H
#define HDMAP_MESSAGE_SRV_ROUTERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace HDMap
{
template <class ContainerAllocator>
struct srv_routeResponse_
{
  typedef srv_routeResponse_<ContainerAllocator> Type;

  srv_routeResponse_()
    : route()  {
    }
  srv_routeResponse_(const ContainerAllocator& _alloc)
    : route(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _route_type;
  _route_type route;





  typedef boost::shared_ptr< ::HDMap::srv_routeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::HDMap::srv_routeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct srv_routeResponse_

typedef ::HDMap::srv_routeResponse_<std::allocator<void> > srv_routeResponse;

typedef boost::shared_ptr< ::HDMap::srv_routeResponse > srv_routeResponsePtr;
typedef boost::shared_ptr< ::HDMap::srv_routeResponse const> srv_routeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::HDMap::srv_routeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::HDMap::srv_routeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace HDMap

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/lunar/share/geometry_msgs/cmake/../msg'], 'HDMap': ['/media/vincent/DATA/Ubuntu/Project/catkin_ws/src/HDMap/msg'], 'std_msgs': ['/opt/ros/lunar/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::HDMap::srv_routeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::HDMap::srv_routeResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::HDMap::srv_routeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::HDMap::srv_routeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::HDMap::srv_routeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::HDMap::srv_routeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::HDMap::srv_routeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "725e82caed0e69c1381233096c51d46d";
  }

  static const char* value(const ::HDMap::srv_routeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x725e82caed0e69c1ULL;
  static const uint64_t static_value2 = 0x381233096c51d46dULL;
};

template<class ContainerAllocator>
struct DataType< ::HDMap::srv_routeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "HDMap/srv_routeResponse";
  }

  static const char* value(const ::HDMap::srv_routeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::HDMap::srv_routeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string route\n\
";
  }

  static const char* value(const ::HDMap::srv_routeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::HDMap::srv_routeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.route);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct srv_routeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::HDMap::srv_routeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::HDMap::srv_routeResponse_<ContainerAllocator>& v)
  {
    s << indent << "route: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.route);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HDMAP_MESSAGE_SRV_ROUTERESPONSE_H
