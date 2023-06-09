// Generated by gencpp from file offb/Circle.msg
// DO NOT EDIT!


#ifndef OFFB_MESSAGE_CIRCLE_H
#define OFFB_MESSAGE_CIRCLE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace offb
{
template <class ContainerAllocator>
struct Circle_
{
  typedef Circle_<ContainerAllocator> Type;

  Circle_()
    : circle_x(0.0)
    , circle_y(0.0)  {
    }
  Circle_(const ContainerAllocator& _alloc)
    : circle_x(0.0)
    , circle_y(0.0)  {
  (void)_alloc;
    }



   typedef float _circle_x_type;
  _circle_x_type circle_x;

   typedef float _circle_y_type;
  _circle_y_type circle_y;





  typedef boost::shared_ptr< ::offb::Circle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::offb::Circle_<ContainerAllocator> const> ConstPtr;

}; // struct Circle_

typedef ::offb::Circle_<std::allocator<void> > Circle;

typedef boost::shared_ptr< ::offb::Circle > CirclePtr;
typedef boost::shared_ptr< ::offb::Circle const> CircleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::offb::Circle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::offb::Circle_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::offb::Circle_<ContainerAllocator1> & lhs, const ::offb::Circle_<ContainerAllocator2> & rhs)
{
  return lhs.circle_x == rhs.circle_x &&
    lhs.circle_y == rhs.circle_y;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::offb::Circle_<ContainerAllocator1> & lhs, const ::offb::Circle_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace offb

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::offb::Circle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::offb::Circle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb::Circle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb::Circle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb::Circle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb::Circle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::offb::Circle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aab94b94318d02875f549111ac08c6be";
  }

  static const char* value(const ::offb::Circle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaab94b94318d0287ULL;
  static const uint64_t static_value2 = 0x5f549111ac08c6beULL;
};

template<class ContainerAllocator>
struct DataType< ::offb::Circle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "offb/Circle";
  }

  static const char* value(const ::offb::Circle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::offb::Circle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 circle_x \n"
"float32 circle_y\n"
;
  }

  static const char* value(const ::offb::Circle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::offb::Circle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.circle_x);
      stream.next(m.circle_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Circle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::offb::Circle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::offb::Circle_<ContainerAllocator>& v)
  {
    s << indent << "circle_x: ";
    Printer<float>::stream(s, indent + "  ", v.circle_x);
    s << indent << "circle_y: ";
    Printer<float>::stream(s, indent + "  ", v.circle_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OFFB_MESSAGE_CIRCLE_H
