#include "colors.hpp"
#include "game.hpp"

#include <print>
#include <raylib.h>
#include <iostream>


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
    if(EventTriggered(0.42)){
      game.MoveTetrominoDown();
    }
    BeginDrawing();
      ClearBackground(darkBlue);
      DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);

      char score_text[10];
      sprintf(score_text, "%d", game.score);
      Vector2 textSize = MeasureTextEx(font, score_text, 38, 2);
      DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, Colors::lightBlue);
      DrawTextEx(font, score_text, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
      
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
