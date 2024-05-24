add_library(SNAKE
  snake.cpp
  snake.h
  )

target_link_libraries(
  SNAKE
  raylib
  )

target_include_directories(SNAKE PUBLIC ${APP_ROOT}/resources)
