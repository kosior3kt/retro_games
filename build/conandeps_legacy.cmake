message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(raylib)
find_package(imgui)
find_package(glfw3)
find_package(fltk)

set(CONANDEPS_LEGACY  raylib  imgui::imgui  glfw  fltk::fltk )