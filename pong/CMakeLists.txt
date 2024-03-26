
add_library(PONG
  pong.cpp
  pong.hpp
  game_objects.h
  game_objects.cpp
  consts.h)

target_link_libraries(PONG raylib)
