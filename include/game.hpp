#ifndef _GAME_HPP
#define _GAME_HPP

#include "grid.hpp"
#include "block.hpp"
#include "tetromino.cpp"

#include <vector>

class Game {
public:
  Game();
  ~Game();
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
  bool BlockFits();
  void Reset();
  void UpdateScore(int linesCleared, int movedDownPoints);
  Grid grid;
  std::vector<Block> tetrominoes;
  Block currentTetromino;
  Block nextTetromino;
  Sound rotateSound;
  Sound clearSound;
  Sound downSound;
  

};

#endif // _GAME_HPP
