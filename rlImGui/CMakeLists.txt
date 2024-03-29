add_library(rlImGui
  rlImGui.h
  rlImGui.cpp
  rlImGuiColors.h
  imgui_impl_raylib.h
  )

target_link_libraries(rlImGui
  imgui::imgui
  glfw
  OpenGL::GL
  raylib
  )

target_include_directories(rlImGui PUBLIC ${APP_ROOT}/pong)
