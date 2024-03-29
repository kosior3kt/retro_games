#ifdef __1__
#include "../rlImGui/imgui_impl_raylib.h"
#include "imgui.h"
// #include "imgui_impl_raylib.h" //shuold be fine in a moment
#include "pong.hpp"
#include "raylib.h"

int main()
{
#define __NO_GUI__
   //  Setup raylib window
   SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
   InitWindow(1280, 720, "Dear ImGui Raylib(OpenGL) example");

   // Setup Dear ImGui context
   ImGui::CreateContext();
   ImGuiIO &io = ImGui::GetIO();
   (void)io;
   io.ConfigFlags
       |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
   io.ConfigFlags
       |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

   // Setup Dear ImGui style
   ImGui::StyleColorsDark();
   // ImGui::StyleColorsLight();

   // Setup Platform/Renderer backends
   ImGui_ImplRaylib_Init();

   // Load Fonts
   // - If no fonts are loaded, dear imgui will use the default font. You can
   // also load multiple fonts and use ImGui::PushFont()/PopFont() to select
   // them.
   // - AddFontFromFileTTF() will return the ImFont* so you can store it if you
   // need to select the font among multiple.
   // - If the file cannot be loaded, the function will return a nullptr.
   // Please handle those errors in your application (e.g. use an assertion, or
   // display an error and quit).
   // - The fonts will be rasterized at a given size (w/ oversampling) and
   // stored into a texture when calling
   // ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame
   // below will call.
   // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use
   // Freetype for higher quality font rendering.
   // - Read 'docs/FONTS.md' for more instructions and details.
   // - Remember that in C/C++ if you want to include a backslash \ in a string
   // literal you need to write a double backslash \\ !
   io.Fonts->AddFontDefault();
   // io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
   // io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
   // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
   // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
   ImFont *font = io.Fonts->AddFontFromFileTTF(
       "resources/driusstraight.ttf", 18.0f, nullptr,
       io.Fonts->GetGlyphRangesJapanese()
   );
   IM_ASSERT(font != nullptr);

   // required to be called to cache the font texture with raylib
   Imgui_ImplRaylib_BuildFontAtlas();

   // Our state
   bool show_demo_window    = true;
   bool show_another_window = false;
   ImVec4 clear_color       = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

   // Main loop
   bool done = false;
   while(!done)
   {
      // Poll and handle events (inputs, window resize, etc.)
      // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to
      // tell if dear imgui wants to use your inputs.
      // - When io.WantCaptureMouse is true, do not dispatch mouse input data
      // to your main application, or clear/overwrite your copy of the mouse
      // data.
      // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input
      // data to your main application, or clear/overwrite your copy of the
      // keyboard data. Generally you may always pass all inputs to dear imgui,
      // and hide them from your application based on those two flags.
      ImGui_ImplRaylib_ProcessEvents();

      // Start the Dear ImGui frame
      ImGui_ImplRaylib_NewFrame();

      ImGui::NewFrame();

      {
         ImGui::Begin("Another Window", &show_another_window);
         ImGui::Text("press to open game or sth");
         if(ImGui::Button("dupa"))
         {
            game_loop::run_game();
         }
         ImGui::End();
      }

      // Rendering
      ImGui::Render();
      BeginDrawing();
      ClearBackground(Color{ (unsigned char)(clear_color.x * 255),
                             (unsigned char)(clear_color.y * 255),
                             (unsigned char)(clear_color.z * 255),
                             (unsigned char)(clear_color.w * 255) });
      ImGui_ImplRaylib_RenderDrawData(ImGui::GetDrawData());
      EndDrawing();

      done = WindowShouldClose();
   }
   // Cleanup
   ImGui_ImplRaylib_Shutdown();
   ImGui::DestroyContext();

   CloseWindow();

   return 0;
}
#endif
#define __2__
#ifdef __2__
#include "pong.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Window.H>

void butt_cb(Fl_Widget *butt, void *data)
{
   game_loop::run_game();
}

int main(int argc, char **argv)
{

   Fl_Window *win = new Fl_Window(160, 75, "dupa"); // create window

   Fl_Button *but1
       = new Fl_Button(10, 10, 140, 25, "PONG"); // create regular button
   but1->align(
       FL_ALIGN_IMAGE_BACKDROP | but1->align()
   ); // use image as a 'backdrop'

   Fl_Button *but2 = new Fl_Button(
       10, 40, 140, 25, "SNAKE"
   ); // create second instance of button
   but2->align(
       FL_ALIGN_IMAGE_BACKDROP | but2->align()
   ); // use image as a 'backdrop'
      //
   but2->callback(butt_cb);
   but1->callback(butt_cb);

   win->end();
   win->show(argc, argv);
   return (Fl::run());
}
#endif
