// Generated by gencpp from file offb_msgs/MultiDetectionInfo.msg
// DO NOT EDIT!


#ifndef OFFB_MSGS_MESSAGE_MULTIDETECTIONINFO_H
#define OFFB_MSGS_MESSAGE_MULTIDETECTIONINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <offb_msgs/DetectionInfo.h>

namespace offb_msgs
{
template <class ContainerAllocator>
struct MultiDetectionInfo_
{
  typedef MultiDetectionInfo_<ContainerAllocator> Type;

  MultiDetectionInfo_()
    : header()
    , num_objs(0)
    , detection_infos()  {
    }
  MultiDetectionInfo_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , num_objs(0)
    , detection_infos(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _num_objs_type;
  _num_objs_type num_objs;

   typedef std::vector< ::offb_msgs::DetectionInfo_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::offb_msgs::DetectionInfo_<ContainerAllocator> >::other >  _detection_infos_type;
  _detection_infos_type detection_infos;





  typedef boost::shared_ptr< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> const> ConstPtr;

}; // struct MultiDetectionInfo_

typedef ::offb_msgs::MultiDetectionInfo_<std::allocator<void> > MultiDetectionInfo;

typedef boost::shared_ptr< ::offb_msgs::MultiDetectionInfo > MultiDetectionInfoPtr;
typedef boost::shared_ptr< ::offb_msgs::MultiDetectionInfo const> MultiDetectionInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator1> & lhs, const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.num_objs == rhs.num_objs &&
    lhs.detection_infos == rhs.detection_infos;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator1> & lhs, const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace offb_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bc6aead57058b498c6b06cb8ab93293c";
  }

  static const char* value(const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbc6aead57058b498ULL;
  static const uint64_t static_value2 = 0xc6b06cb8ab93293cULL;
};

template<class ContainerAllocator>
struct DataType< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "offb_msgs/MultiDetectionInfo";
  }

  static const char* value(const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"\n"
"## 检测到的目标数量\n"
"int32 num_objs\n"
"\n"
"## 每个目标的检测结果\n"
"DetectionInfo[] detection_infos\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: offb_msgs/DetectionInfo\n"
"std_msgs/Header header\n"
"\n"
"## 目标类别名称\n"
"string object_name\n"
"\n"
"## 是否检测到目标\n"
"bool detected\n"
"\n"
"## 0表示相机坐标系, 1表示机体坐标系, 2表示惯性坐标系\n"
"int32 frame\n"
"\n"
"## 目标位置[相机系下：右方x为正，下方y为正，前方z为正]\n"
"float32[3] position\n"
"\n"
"## 目标姿态-欧拉角-(z,y,x)\n"
"float32[3] attitude\n"
"\n"
"## 目标姿态-四元数-(qx,qy,qz,qw)\n"
"float32[4] attitude_q\n"
"\n"
"## 视线角度[相机系下：右方x角度为正，下方y角度为正]\n"
"float32[2] sight_angle\n"
"\n"
"## 偏航角误差\n"
"float32 yaw_error\n"
"\n"
"## 类别\n"
"int32 category\n"
"\n"
;
  }

  static const char* value(const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.num_objs);
      stream.next(m.detection_infos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MultiDetectionInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::offb_msgs::MultiDetectionInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::offb_msgs::MultiDetectionInfo_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "num_objs: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num_objs);
    s << indent << "detection_infos[]" << std::endl;
    for (size_t i = 0; i < v.detection_infos.size(); ++i)
    {
      s << indent << "  detection_infos[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::offb_msgs::DetectionInfo_<ContainerAllocator> >::stream(s, indent + "    ", v.detection_infos[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // OFFB_MSGS_MESSAGE_MULTIDETECTIONINFO_H
