#include "colors.hpp"
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
      DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, Colors::lightBlue);
      DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
      DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, Colors::lightBlue);
      if(game.gameOver){
        DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
      }
      game.Draw();
    EndDrawing();
  }
  CloseWindow();

}
