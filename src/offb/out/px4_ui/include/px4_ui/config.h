#ifndef CONFIG_H
#define CONFIG_H

#include <string>
enum fly_mode{
  OFFBOARD,
  LOITER,
  LAND,
  RETURN,
  TAKEOFF,
  MANUAL
};

const std::string mode_string[6] = {"OFFBOARD", "AUTO.LOITER", "AUTO.LAND", "AUTO.RTL", "AUTO.TAKEOFF", "MANUAL"};

#endif // CONFIG_H
