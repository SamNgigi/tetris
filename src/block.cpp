#include "block.hpp"

#include <raylib.h>
#include <array>

void Block::Draw(int offsetX, int offsetY){
  const std::array<Position, 4>& tiles = GetCellPositions();
  for(auto tile : tiles){
    DrawRectangle(tile.col * cellSize + offsetX, tile.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::Move(int row, int col){
  rowOffset += row;
  colOffset += col;
}

std::array<Block::Position, 4> Block::GetCellPositions(){
  const std::array<Position, 4>& tiles = cellsMap[rotationState];
  std::array<Position, 4> movedTiles;
  int item = 0;
  for(Position tile: tiles){
    Position newPosition = Position(tile.row + rowOffset, tile.col + colOffset);
    movedTiles[item] = newPosition;
    item++;
  }
  return movedTiles;
}

void Block::Rotate(){
  int len = (int) cellsMap.size();
  rotationState = (rotationState + 1) % len;
}

void Block::UndoRotation(){
  int len = (int) cellsMap.size();
  rotationState = (rotationState + (len - 1)) % len;
}
