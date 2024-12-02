cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(
	"ProjectHydrogen"
	VERSION 0.0.3
	DESCRIPTION "Game from scratch in C++."
	LANGUAGES C
)

if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(
	${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
)

set(PROJECT_HYDROGEN_INCLUDE_DIRS
	src
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_HYDROGEN_INCLUDE_DIRS}
)

# Common libraries
set(PROJECT_HYDROGEN_LINK_LIBRARIES
	glad
	glfw
)

# Check for Windows
if(WIN32)
	list(APPEND PROJECT_HYDROGEN_LINK_LIBRARIES opengl32.lib)
# Check for Linux
elseif(UNIX AND NOT APPLE)
	set(GLFW_BUILD_WAYLAND ON)
	set(GLFW_BUILD_X11 OFF)
	list(APPEND PROJECT_HYDROGEN_LINK_LIBRARIES GL)
# Check for macOS
elseif(APPLE)
else()
    message(FATAL_ERROR "Unsupported platform. Only Windows, Linux, and macOS are supported.")
endif()

if()
	list(APPEND PROJECT_HYDROGEN_LINK_LIBRARIES opengl32.lib)
endif()

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	${PROJECT_HYDROGEN_LINK_LIBRARIES}
)
