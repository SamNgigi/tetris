#include "block.hpp"

#include <raylib.h>
#include <array>

void Block::Draw(){
  const std::array<Position, 4>& tiles = GetCellPositions();
  for(auto tile : tiles){
    DrawRectangle(tile.col * cellSize + 1, tile.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
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

