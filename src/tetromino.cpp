#include "block.hpp"

class LBlock : public Block {
public:
  LBlock(){
    id = 1;
    cellsMap[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(0, 2)}; // ___|
    cellsMap[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    cellsMap[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    cellsMap[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
  }
};

class JBlock : public Block {
public:
  JBlock(){
    id = 2;
    cellsMap[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)}; // |___
    cellsMap[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    cellsMap[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    cellsMap[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
  }
};


class IBlock : public Block {
public:
  IBlock(){
    id = 3;
    cellsMap[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)}; // ----
    cellsMap[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    cellsMap[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    cellsMap[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
    Move(-1, 0);
  }
};

class OBlock : public Block {
public:
  OBlock(){
    id = 4;
    cellsMap[0] = {Position(0,0), Position(0,1), Position(1, 0), Position(1, 1)}; // ++
    Move(0, 1);
  }
};

class TBlock : public Block {
public:
  TBlock(){
    id = 5;
    cellsMap[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1,2)}; // __|__
    cellsMap[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2,1)};
    cellsMap[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2,1)};
    cellsMap[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2,1)};
  }
};


class SBlock : public Block {
public:
  SBlock(){
    id = 6;
    cellsMap[0] = {Position(1, 0), Position(1, 1), Position(0, 1), Position(0, 2)};
    cellsMap[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    cellsMap[2] = {Position(2, 0), Position(2, 1), Position(1, 1), Position(1, 2)};
    cellsMap[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
  }
};

class ZBlock : public Block {
public:
  ZBlock(){
    id = 7;
    cellsMap[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    cellsMap[1] = {Position(0, 2), Position(1, 2), Position(1, 1), Position(2, 1)};
    cellsMap[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    cellsMap[3] = {Position(0, 1), Position(1, 1), Position(1, 0), Position(2, 0)};
  }
};
