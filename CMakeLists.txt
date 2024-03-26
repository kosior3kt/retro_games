cmake_minimum_required(VERSION 3.20)
project(dupa)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

find_package(raylib REQUIRED)
find_package(OPENGL REQUIRED) #not needed?

#find_package(imgui REQUIRED) #will do this later

add_subdirectory(pong)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}
  PONG
  )
