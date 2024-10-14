#include "ball.hpp"

#include <print>
#include <raylib.h>

int main(){
  
  // std::println("Hello World!");

  const Color darkGreen = {20, 160, 133, 255};

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 600;

  Ball ball;

  InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    ball.Update();

    BeginDrawing();
      ClearBackground(darkGreen);
      ball.Draw();
    EndDrawing();
  }

  CloseWindow();
}
