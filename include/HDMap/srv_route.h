// Generated by gencpp from file HDMap/srv_route.msg
// DO NOT EDIT!


#ifndef HDMAP_MESSAGE_SRV_ROUTE_H
#define HDMAP_MESSAGE_SRV_ROUTE_H

#include <ros/service_traits.h>


#include <HDMap/srv_routeRequest.h>
#include <HDMap/srv_routeResponse.h>


namespace HDMap
{

struct srv_route
{

typedef srv_routeRequest Request;
typedef srv_routeResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct srv_route
} // namespace HDMap


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::HDMap::srv_route > {
  static const char* value()
  {
    return "bc949e1cd0e6a6576c735b1aa4dfaa58";
  }

  static const char* value(const ::HDMap::srv_route&) { return value(); }
};

template<>
struct DataType< ::HDMap::srv_route > {
  static const char* value()
  {
    return "HDMap/srv_route";
  }

  static const char* value(const ::HDMap::srv_route&) { return value(); }
};


// service_traits::MD5Sum< ::HDMap::srv_routeRequest> should match 
// service_traits::MD5Sum< ::HDMap::srv_route > 
template<>
struct MD5Sum< ::HDMap::srv_routeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::HDMap::srv_route >::value();
  }
  static const char* value(const ::HDMap::srv_routeRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::HDMap::srv_routeRequest> should match 
// service_traits::DataType< ::HDMap::srv_route > 
template<>
struct DataType< ::HDMap::srv_routeRequest>
{
  static const char* value()
  {
    return DataType< ::HDMap::srv_route >::value();
  }
  static const char* value(const ::HDMap::srv_routeRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::HDMap::srv_routeResponse> should match 
// service_traits::MD5Sum< ::HDMap::srv_route > 
template<>
struct MD5Sum< ::HDMap::srv_routeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::HDMap::srv_route >::value();
  }
  static const char* value(const ::HDMap::srv_routeResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::HDMap::srv_routeResponse> should match 
// service_traits::DataType< ::HDMap::srv_route > 
template<>
struct DataType< ::HDMap::srv_routeResponse>
{
  static const char* value()
  {
    return DataType< ::HDMap::srv_route >::value();
  }
  static const char* value(const ::HDMap::srv_routeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HDMAP_MESSAGE_SRV_ROUTE_H