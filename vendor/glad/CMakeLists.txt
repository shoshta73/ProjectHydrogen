project("glad" LANGUAGES C)

add_library(${PROJECT_NAME} STATIC "src/glad.c" "include/glad/glad.h" "include/KHR/khrplatform.h")
target_include_directories(${PROJECT_NAME} PUBLIC "include")
