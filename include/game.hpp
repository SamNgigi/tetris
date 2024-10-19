#ifndef _GAME_HPP
#define _GAME_HPP

#include "grid.hpp"
#include "block.hpp"
#include "tetromino.cpp"

#include <vector>

class Game {
public:
  Game(): 
    tetrominoes(GetAllTetrominoes()), 
    currentTetromino(GetRandomTetromino()), 
    nextTetromino(GetRandomTetromino()), 
    gameOver(false), 
    score(0){};
  void Draw();
  void HandleInput();
  void MoveTetrominoDown();
  bool gameOver;
  int score;

private:
  std::vector<Block> GetAllTetrominoes();
  Block GetRandomTetromino();
  bool IsBlockOutside();
  void MoveTetrominoLeft();
  void MoveTetrominoRight();
  void RotateTetromino();
  void LockBlock();
  bool CollisionDetected();
  Grid grid;
  std::vector<Block> tetrominoes;
  Block currentTetromino;
  Block nextTetromino;

  

};

#endif // _GAME_HPP
