#ifndef _BALL_HPP
#define _BALL_HPP

class Ball{
public:
  Ball();
  void Update();
  void Draw() const;

private:
  int x, y, speedX, speedY, radius;
};

#endif // _BALL_HPP
