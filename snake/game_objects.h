#ifndef __SNAKE_GO__
#define __SNAKE_GO__

#include "consts.h"

#include <iostream>
#include <random>
#include <raylib.h>

/// renormalized space (I assume, that one square takes aprox 10 pixels. might
/// change it later)
namespace LOCAL
{
   constexpr int HEIGHT = GENERAL::HEIGHT / 10;
   constexpr int WIDTH  = GENERAL::WIDTH / 10;

   namespace helper
   {
      int random_number_from_scope(int _scope);
   }
}

enum class Directions
{
   RIGHT,
   LEFT,
   TOP,
   DOWN
};

class Position_coordinates
{
   protected:
      struct Position
      {
            int x;
            int y;
      };
};

class Score
{
      int score_{};

   public:
      Score(int _left_score = 0, int _right_score = 0);
      void update(int _score);
      void increment();
      void draw();
      void reset(); /// dead code for now;
};

class Square : public Position_coordinates
{
   protected:
      Position pos_;

   public:
      Square();
      void draw(Color _col = GREEN);
      void move(Position _pos);
};

class game_object : public Square
{
   public:
      void update();
};

class Food : public game_object
{
   public:
      Food();
};

class Snake : public game_object
{
      std::vector<Square> body_{}; /// make this circullar buffer?
      Directions directions_;

   public:
      Snake(Position _pos);
      Snake();
      void feed();
      void update(Food);
      void draw();
};

#endif
