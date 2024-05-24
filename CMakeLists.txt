cmake_minimum_required(VERSION 3.27)
project(dupa)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(raylib REQUIRED)
find_package(OPENGL REQUIRED) #not needed?
find_package(GLFW3 3.3 REQUIRED)
find_package(imgui REQUIRED) 
find_package(fltk REQUIRED)

add_subdirectory(pong)
add_subdirectory(src)
add_subdirectory(snake)
#add_subdirectory(rlImGui)

target_link_libraries(${PROJECT_NAME}
  PONG
  OpenGL::GL
  imgui::imgui
  glfw 
  fltk::fltk
  #rlImGui
  )
