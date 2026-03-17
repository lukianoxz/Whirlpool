cmake_minimum_required(VERSION 3.10)
project(Whirlpool)

set(SOURCES
    Whirlpool/Math/Vector2/Vector2.cpp
)

set(HEADERS
    Whirlpool/Math/Vector2/Vector2.hpp
)

add_library(Whirlpool STATIC ${SOURCES} ${HEADERS})

target_include_directories(Whirlpool PUBLIC
    .
    Whirlpool
    Whirlpool/Window
    Whirlpool/Math/Vector2
    Whirlpool/Math/FRect
    Whirlpool/Math/Point
    Whirlpool/Input
    Whirlpool/Graphics/SimpleRender2D
    Whirlpool/Graphics/Color
    Whirlpool/Sound/
)

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/SDL3/include)
    link_directories(${CMAKE_SOURCE_DIR}/SDL3/lib)
else()
    find_package(SDL3 REQUIRED)
endif()

target_link_libraries(Whirlpool PUBLIC SDL3::SDL3)

option(BUILD_EXAMPLES "Compile examples" OFF)
if(BUILD_EXAMPLES)
    add_subdirectory(Examples)
endif()