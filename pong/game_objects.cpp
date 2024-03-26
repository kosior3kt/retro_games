#include "game_objects.h"

#include "consts.h"

#include <raylib.h>

/// definitions of the Score
Score::Score(int _left_score, int _right_score)
{
   this->left_score  = 0;
   this->right_score = 0;
}

void Score::update_left(int _score)
{
   this->left_score = _score;
}

void Score::update_right(int _score)
{
   this->right_score = _score;
}

void Score::increment_left()
{
   left_score++;
}

void Score::increment_right()
{
   right_score++;
}

void Score::draw()
{
   DrawCircle(WIDTH / 4, HEIGHT / 2, 200, BLACK);
   DrawText(
       std::to_string(left_score).c_str(), WIDTH / 4, HEIGHT / 2, 100, PINK
   );
   DrawCircle((WIDTH / 4) * 3, HEIGHT / 2, 200, BLACK);
   DrawText(
       std::to_string(right_score).c_str(), 3 * (WIDTH / 4), HEIGHT / 2, 100,
       PINK
   );
}

/// definitions of the ball

Ball::Ball(int _x, int _y, float _r, Color _col, int _speed_y, int _speed_x)
{
   this->pos_.x              = _x;
   this->pos_.y              = _y;
   this->local_dimensions_.r = _r;
   this->speed_.y            = _speed_y;
   this->speed_.x            = _speed_x;
}

void Ball::draw() const
{
   DrawCircle(pos_.x, pos_.y, this->local_dimensions_.r, WHITE);
}

void Ball::update(Paddle left_paddle, Paddle right_paddle)
{
   if(!inside_vertical_space(this->pos_.y))
   {
      this->speed_.y = this->speed_.y * -1;
   }

   if(!inside_horizontal_space(this->pos_.x))
   {
      if(this->pos_.x <= WIDTH / 2)
      {
         this->score_.increment_right();
      }
      else
      {
         this->score_.increment_left();
      }

      this->pos_.x   = WIDTH / 2;
      this->pos_.y   = HEIGHT / 2;
      this->speed_.x = this->speed_.x * -1;
      /// update counter here, after checking which side won, or sth

      /*
      while(GetKeyPressed() != KEY_UP || GetKeyPressed() != KEY_DOWN
            || GetKeyPressed() != KEY_LEFT || GetKeyPressed() != KEY_RIGHT)
      {
         // wait here
      }
      */
      /// wil figure this out later
   }
   this->score_.draw();

   if(this->pos_.x >= WIDTH / 2) /// on the right side
   {
      if((this->pos_.x + this->local_dimensions_.r
          == WIDTH - PADDLE_WIDTH - GAP)
         && (this->pos_.y
                 > right_paddle.get_y_pos() - this->local_dimensions_.r
             && this->pos_.y < right_paddle.get_y_pos()
                                   + this->local_dimensions_.r
                                   + PADDLE_HEIGHT))
      {
         this->speed_.x = this->speed_.x * -1;
      }
      /*
      else if((this->pos_.x - this->local_dimensions_.r == WIDTH - PADDLE_WIDTH
      - GAP) && this->pos_.y > right_paddle.get_y_pos() -
      this->local_dimensions_.r && this->pos_.y < right_paddle.get_y_pos() +
      this->local_dimensions_.r + PADDLE_HEIGHT)
      {
         this->speed_.x = (this->speed_.x * -1) / 2;
      }
      */
   }
   else /// on the left side
   {
      if((this->pos_.x - this->local_dimensions_.r == PADDLE_WIDTH + GAP)
         && (this->pos_.y > left_paddle.get_y_pos() - this->local_dimensions_.r
             && this->pos_.y < left_paddle.get_y_pos()
                                   + this->local_dimensions_.r
                                   + PADDLE_HEIGHT))
      {
         this->speed_.x = this->speed_.x * -1;
      }
      /*
      else if((this->pos_.x - this->local_dimensions_.r == PADDLE_WIDTH + GAP)
      && this->pos_.y > left_paddle.get_y_pos() - this->local_dimensions_.r &&
      this->pos_.y < left_paddle.get_y_pos() + this->local_dimensions_.r +
      PADDLE_HEIGHT)
      {
         this->speed_.x = (this->speed_.x * -1) / 2;
      }
      */
   }
   // if(!inside_horizontal_space(this->pos_.x) ||
   // ball.collides_with_paddle(pad_r))
   /// this is still needed for some reason
   if(!inside_horizontal_space(this->pos_.x)
      || this->collides_with_paddle(right_paddle
      )) /// there will be collision with paddle
   {
      this->speed_.x = this->speed_.x * -1;
   }

   this->pos_.x += this->speed_.x;
   this->pos_.y += this->speed_.y;
}

bool Ball::collides_with_paddle(Paddle _paddle)
{
   return false;
}

bool Ball::inside_vertical_space(int _vert_pos)
{
   return (
       _vert_pos - this->local_dimensions_.r > 0
       && _vert_pos + this->local_dimensions_.r < HEIGHT
   );
}

bool Ball::inside_horizontal_space(int _horizontal_pos)
{
   return (_horizontal_pos > 0 && _horizontal_pos < WIDTH);
}

/// definitions of the paddle

Paddle::Paddle(
    int _x, int _y, int _width, int _height, Color _col, int _speed,
    KeyboardKey _key_down, KeyboardKey _key_up
)
{
   this->pos_.x                   = _x;
   this->pos_.y                   = _y;
   this->local_dimensions_.height = _height;
   this->local_dimensions_.width  = _width;
   this->speed                    = _speed;
   this->colour_                  = _col;
   this->_local_down              = _key_down;
   this->_local_up                = _key_up;
   /// TODO: maybe add later possiblility to change keys in constructor?
};

void Paddle::draw() const
{
   DrawRectangle(
       this->pos_.x, this->pos_.y, this->local_dimensions_.width,
       this->local_dimensions_.height, this->colour_
   );
}

void Paddle::update()
{
   if(IsKeyDown(this->_local_down))
   {
      if(this->pos_.y + this->local_dimensions_.height < HEIGHT)
         this->pos_.y = this->pos_.y + 4;
   }
   else if(IsKeyDown(this->_local_up))
   {
      if(this->pos_.y > 0)
         this->pos_.y = this->pos_.y - 4;
   }
}

void Paddle::change_controls(KeyboardKey _down, KeyboardKey _up)
{
   this->_local_up   = _up;
   this->_local_down = _down;
}

int Paddle::get_y_pos()
{
   return this->pos_.y;
};
