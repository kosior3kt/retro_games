#include "pong.hpp"

void game_loop::run_game()
{

#ifndef __NO_GUI__
   InitWindow(GENERAL::WIDTH, GENERAL::HEIGHT, "dupa");
#endif

   SetTargetFPS(60);

   Ball ball(GENERAL::WIDTH / 2, GENERAL::HEIGHT / 2, 20.0f);
   Paddle right_paddle(
       GENERAL::WIDTH - PONG::GAP - PONG::PADDLE_WIDTH, 20, PONG::PADDLE_WIDTH,
       PONG::PADDLE_HEIGHT, RED, 4
   );
   Paddle left_paddle(
       PONG::GAP, 20, PONG::PADDLE_WIDTH, PONG::PADDLE_HEIGHT, GREEN, 4
   );
   left_paddle.change_controls(KEY_LEFT, KEY_RIGHT);

   std::vector<base_object *> game_objects{ &ball, &right_paddle,
                                            &left_paddle };

   Score current_score;
   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(BLACK);

      DrawLine(
          GENERAL::WIDTH / 2, 0, GENERAL::WIDTH / 2, GENERAL::HEIGHT, WHITE
      ); // for now can be here

      current_score.draw();
      ball.update(left_paddle, right_paddle);

      for(const auto dupa : game_objects)
      {
         dupa->update();
         dupa->draw();
      }

      EndDrawing();
   }

#ifndef __NO_GUI__
   CloseWindow();
#endif
}
