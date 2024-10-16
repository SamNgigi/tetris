#include "grid.hpp"
#include "tetromino.cpp"

#include <print>
#include <raylib.h>

int main(){
  
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Grid grid;
  LBlock lblock;
  lblock.Move(0,3);
  JBlock jblock;
  jblock.Move(3,0);
  IBlock iblock;
  iblock.Move(3,3);
  OBlock oblock;
  oblock.Move(6,0);
  SBlock sblock;
  sblock.Move(6,3);
  ZBlock zblock;
  zblock.Move(9,0);
  TBlock tblock;
  tblock.Move(9,3);



  while(!WindowShouldClose()){
    BeginDrawing();
      ClearBackground(darkBlue);
      grid.Draw();
      lblock.Draw();
      jblock.Draw();
      iblock.Draw();
      oblock.Draw();
      sblock.Draw();
      zblock.Draw();
      tblock.Draw();
    EndDrawing();
  }
  CloseWindow();

}
