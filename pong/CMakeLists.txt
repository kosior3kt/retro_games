
add_library(PONG
  pong.cpp
  pong.hpp
  game_objects.h
  game_objects.cpp
  )

target_link_libraries(PONG raylib)

target_include_directories(PONG PUBLIC ${APP_ROOT}/resources)
