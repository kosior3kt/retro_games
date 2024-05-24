#include "snake.h"

#include "game_objects.h"

#include <unistd.h>

void snake::run()
{
#ifndef __NO_GUI__
   InitWindow(GENERAL::WIDTH, GENERAL::HEIGHT, "dupa");
#endif

   SetTargetFPS(60);
   while(!WindowShouldClose())
   {
      sleep(1000); // this is for waiting between moves
      BeginDrawing();
      ClearBackground(BLACK);
      /// bulk of code goes here
      // creating objects here
      Snake snake{};
      Food food{};
      std::vector<game_object> GO{ food, snake };
      for(auto &obj : GO)
      {
         obj.update();
         obj.draw();
      }
      EndDrawing();
   }

#ifndef __NO_GUI__
   CloseWindow();
#endif
}
