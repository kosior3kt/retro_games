#include "pong.hpp"

void game_loop::run_game()
{
   InitWindow(WIDTH, HEIGHT, "dupa");
   SetTargetFPS(60);

   Ball ball(WIDTH / 2, HEIGHT / 2, 20.0f);
   Paddle right_paddle(
       WIDTH - GAP - PADDLE_WIDTH, 20, PADDLE_WIDTH, PADDLE_HEIGHT, RED, 4
   );
   Paddle left_paddle(GAP, 20, PADDLE_WIDTH, PADDLE_HEIGHT, GREEN, 4);
   left_paddle.change_controls(KEY_LEFT, KEY_RIGHT);

   std::vector<base_object *> game_objects{ &ball, &right_paddle,
                                            &left_paddle };

   Score current_score;
   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(BLACK);

      DrawLine(WIDTH / 2, 0, WIDTH / 2, HEIGHT, WHITE); // for now can be here

      current_score.draw();
      ball.update(left_paddle, right_paddle);

      for(const auto dupa : game_objects)
      {
         dupa->update();
         dupa->draw();
      }

      EndDrawing();
   }
   CloseWindow();
}
