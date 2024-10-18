#include "game.hpp"
#include "raylib.h"

#include <random>
#include <chrono>
#include <array>

std::vector<Block> Game::GetAllTetrominoes(){
  return {IBlock(), OBlock(), TBlock(), JBlock(), LBlock(), SBlock(), ZBlock()};
}

Block Game::GetRandomTetromino(){
  if(tetrominoes.empty()){
    tetrominoes = GetAllTetrominoes();
  }
  static std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<> dis(0, tetrominoes.size()-1);
  int randIdx = dis(gen);
  Block tetromino = tetrominoes[randIdx];
  tetrominoes.erase(tetrominoes.begin() + randIdx);
  return tetromino;
}

void Game::Draw(){
  grid.Draw();
  currentTetromino.Draw();
}

void Game::HandleInput(){
  int keyPressed = GetKeyPressed(); // From raylib
  switch(keyPressed){
    case KEY_DOWN:
      MoveTetrominoDown();
      break;
    case KEY_LEFT:
      MoveTetrominoLeft();
      break;
    case KEY_RIGHT:
      MoveTetrominoRight();
      break;

  }
}

bool Game::IsBlockOutside(){
  const std::array<Block::Position, 4>& tiles = currentTetromino.GetCellPositions();
  for(Block::Position tile : tiles){
    if(grid.IsCellOutside(tile.row, tile.col)){
      return true;
    }
  }
  return false;
}

void Game::MoveTetrominoDown(){
  if(!gameOver){
    currentTetromino.Move(1, 0);
    if(IsBlockOutside()){
      currentTetromino.Move(-1, 0);
    }
  }
}

void Game::MoveTetrominoLeft(){
  if(!gameOver){
    currentTetromino.Move(0, -1);
    if(IsBlockOutside()){
      currentTetromino.Move(0, 1);
    }
  }
}

void Game::MoveTetrominoRight(){
  if(!gameOver){
    currentTetromino.Move(0, 1);
    if(IsBlockOutside()){
      currentTetromino.Move(0, -1);
    }
  }
}

