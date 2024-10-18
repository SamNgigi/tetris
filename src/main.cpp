#include "grid.hpp"
#include "tetromino.cpp"

#include <print>
#include <raylib.h>

int main(){
  
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid grid;
  OBlock lblock;


  while(!WindowShouldClose()){
    BeginDrawing();
      ClearBackground(darkBlue);
      grid.Draw();
      lblock.Draw();
   EndDrawing();
  }
  CloseWindow();

}
