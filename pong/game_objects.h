#ifndef __PONG_GO__
#define __PONG_GO__

#include "consts.h"

#include <raylib.h>
#include <string>

class Score
{
      int left_score;
      int right_score;

   public:
      Score(int _left_score = 0, int _right_score = 0);
      void update_left(int _score);
      void update_right(int _score);
      void increment_left();
      void increment_right();
      void draw();
      void reset(); /// dead code for now;
};

class base_object
{
   protected:
      struct Position
      {
            int x;
            int y;
      };

      int speed;

   public:
      virtual void draw() const {};
      virtual void update(){};
      virtual ~base_object(){};
};

class Paddle : public base_object
{
   private:
      Position pos_{};
      KeyboardKey _local_down, _local_up;

      struct Dimentions
      {
            int width;
            int height;
      } local_dimensions_;

      int speed_{};
      Color colour_;

   public:
      Paddle(
          int _x, int _y, int _width, int _height, Color _col = WHITE,
          int _speed = 4, KeyboardKey _key_up = KEY_UP,
          KeyboardKey _key_down = KEY_DOWN
      );
      // size n dimentions

      void draw() const;
      void update();
      void change_controls(KeyboardKey _down, KeyboardKey _up);
      int get_y_pos();
      // 2 ways to handle this, one can be pumping coordinates of paddle,
      // other can be passing paddle itself. we shall see
};

class Ball : public base_object
{
   private:
      Score score_;
      Position pos_{};
      bool inside_vertical_space(int _vert_pos);
      bool inside_horizontal_space(int _vert_pos);

      struct Dimensions
      {
            int r;
      } local_dimensions_;

      struct Speed
      {
            int y;
            int x;
      } speed_{};

   public:
      Ball(
          int _x, int _y, float _r, Color _col = WHITE, int _speed_y = 4,
          int _speed_x = 4
      );

      void draw() const;
      void update(Paddle left_paddle, Paddle right_paddle);
      bool collides_with_paddle(Paddle _paddle);
      // 2 ways to handle this, one can be pumping coordinates of paddle,
      // other can be passing paddle itself. we shall see
};

#endif // !__dupa__
