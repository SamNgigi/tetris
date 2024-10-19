#ifndef _BLOCK_HPP
#define _BLOCK_HPP

#include "colors.hpp"

#include <raylib.h>
#include <array>
#include <unordered_map>

class Block{
public:
  Block(): cellSize(30), rotationState(0), colors(Colors::CellColors), rowOffset(0), colOffset(0){Move(0,3);}
  struct Position{
    Position(): row(0), col(0) {}
    Position(int row, int col): row(row), col(col){}
    int col, row;
  };
  void Draw(int offsetX, int offsetY);
  void Move(int row, int col);
  std::array<Position, 4> GetCellPositions();
  void Rotate();
  void UndoRotation();
  int id;
  std::unordered_map<int, std::array<Position, 4>> cellsMap;

private:
  int cellSize;
  int rotationState;
  std::array<Color, 8> colors;
  int rowOffset;
  int colOffset;
};

#endif // _BLOCK_HPP
