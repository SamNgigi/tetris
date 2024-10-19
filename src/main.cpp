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
  InitWindow(300, 600, "raylib Tetris");
  SetTargetFPS(60);

  Game game; 


  while(!WindowShouldClose()){
    game.HandleInput();
    if(EventTriggered(0.5)){
      game.MoveTetrominoDown();
    }
    BeginDrawing();
      ClearBackground(darkBlue);
      game.Draw();
    EndDrawing();
  }
  CloseWindow();

}
