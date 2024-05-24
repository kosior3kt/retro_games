add_executable(${PROJECT_NAME}
  main.cpp
  )

target_include_directories(${PROJECT_NAME} PUBLIC ${APP_ROOT}/pong)
target_include_directories(${PROJECT_NAME} PUBLIC ${APP_ROOT}/rlImGui)
target_include_directories(${PROJECT_NAME} PUBLIC ${APP_ROOT}/resources)
target_include_directories(${PROJECT_NAME} PUBLIC ${FLTK_DIR})

#will do that later
