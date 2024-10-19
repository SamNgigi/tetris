#include "game.hpp"

#include <print>
#include <raylib.h>


double lastUpdateTime = 0;

bool EventTriggered(double interval){

  double currentTime = GetTime(); // from raylib
  if(currentTime - lastUpdateTime >= interval){
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main(){
  
  Color darkBlue = {44, 44, 127, 255};
  InitWindow(500, 620, "raylib Tetris");
  SetTargetFPS(60);

  Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);// From raylib

  Game game; 


  while(!WindowShouldClose()){
    game.HandleInput();
    if(EventTriggered(0.02)){
      game.MoveTetrominoDown();
    }
    BeginDrawing();
      ClearBackground(darkBlue);
      DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
      game.Draw();
    EndDrawing();
  }
  CloseWindow();

}
