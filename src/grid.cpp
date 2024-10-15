#include "grid.hpp"

#include <print>
#include <raylib.h>

void Grid::Initialize(){
  for(int row = 0; row < numRows; ++row){
    for(int col = 0; col < numCols; ++col){
      grid[row][col] = 0;
    }
  }
}

void Grid::Print(){
  for(int row = 0; row < numRows; ++row){
    for(int col = 0; col < numCols; ++col){
      std::print("{0} ", grid[row][col]);
    }
    std::println();
  }
}

void Grid::Draw(){
  for(int row = 0; row<numRows; ++row){
    for(int col = 0; col<numCols; ++col){
      int cellVal = grid[row][col];
      DrawRectangle(
        col * cellSize + 1, // int posX
        row * cellSize + 1, // int posY
        cellSize - 1, // int width
        cellSize - 1, // int height
        colors[cellVal] // Color color
      );
    }
  }
}

