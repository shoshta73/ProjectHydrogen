cmake_minimum_required(VERSION 3.16)

project(
	"ProjectHydrogen"
	VERSION 0.0.1
	DESCRIPTION "Game from scratch in C++."
	LANGUAGES C CXX
)

if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(vendor/glfw)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cc" "src/*.cpp" "src/*.cxx" "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.hh" "src/*.hpp" "src/*.hxx" "src/*.h")

add_executable(
	${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
)

set(PROJECT_HYDROGEN_LINK_LIBRARIES
	glfw
	opengl32.lib
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_HYDROGEN_LINK_LIBRARIES}
)
