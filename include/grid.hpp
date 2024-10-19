#ifndef _GRID_HPP
#define _GRID_HPP

#include "colors.hpp"

#include <raylib.h>
#include <array>


class Grid{

public:
  Grid(): numRows(20), numCols(10), cellSize(30), colors(Colors::CellColors){Initialize();}
  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int column);
  bool IsCellEmpty(int row, int column);
  int ClearFullRows();
  int grid[20][10];

private:
  bool IsRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int numRows);
  int numRows;
  int numCols;
  int cellSize;
  std::array<Color, 8> colors;
};

#endif // _GRID_HPP
