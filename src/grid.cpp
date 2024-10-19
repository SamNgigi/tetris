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
        col * cellSize + 11, // int posX
        row * cellSize + 11, // int posY
        cellSize - 1, // int width
        cellSize - 1, // int height
        colors[cellVal] // Color color
      );
    }
  }
}

bool Grid::IsCellOutside(int row, int col){
  return row < 0 || row >= numRows || col < 0 || col >= numCols;
}

bool Grid::IsCellEmpty(int row, int column){
  return grid[row][column] == 0;
}

bool Grid::IsRowFull(int row){
  for(int col = 0; col < numCols; ++col){
    if(grid[row][col] == 0){
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row){
  for(int col = 0; col < numCols; ++col){
    grid[row][col] = 0;
  }
}

void Grid::MoveRowDown(int row, int nRows){
  for(int col = 0; col < numCols; ++col){
    grid[row + nRows][col] = grid[row][col];
    grid[row][col] = 0;
  }
}

int Grid::ClearFullRows(){
  int completed = 0;
  for(int row = numRows - 1; row >= 0; --row){
    if(IsRowFull(row)){
      ClearRow(row);
      completed++;
    } else if(completed > 0){
      MoveRowDown(row, completed);
    }
  }
  return completed;
}
