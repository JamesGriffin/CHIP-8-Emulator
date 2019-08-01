cmake_minimum_required(VERSION 2.8.4)
project(chip8)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/chip8.cpp)

include(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS})
    add_definitions(${SDL2_CFLAGS_OTHER})
    set(LIBRARIES ${LIBRARIES} ${SDL2_LIBRARIES})
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
