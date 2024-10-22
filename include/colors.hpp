#ifndef _COLORS_HPP
#define _COLORS_HPP

#include <raylib.h>
#include <array>

namespace Colors{

  inline const Color darkGrey = {26, 31, 40, 255};
  inline const Color green = {12, 202, 74, 255}; // replaced
  inline const Color red = {208, 0, 0, 255}; // replaced
  inline const Color orange = {255, 159, 28, 255}; // replaced
  inline const Color yellow = {255, 186, 8, 255}; // replaced
  inline const Color purple = {255, 60, 199, 255};
  inline const Color cyan = {38, 255, 230, 255}; // replaced
  inline const Color aquamarine = {24, 242, 178, 255}; // replaced
  inline const Color sandyBrown = {135, 160, 178, 255};
  inline const Color crayola = {82, 79, 105, 255};

  inline const std::array<Color, 8> CellColors = 
    {darkGrey, green, red, orange, yellow, purple, cyan, aquamarine};
}


#endif //_COLORS_HPP
