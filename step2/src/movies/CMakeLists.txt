cmake_minimum_required(VERSION 3.14)

project(movies LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(movies
  main.cpp
  Interpreter.cpp
)
add_executable(movies_tests
  movies_tests.cc
)

target_link_libraries(
  movies_tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(movies_tests)

target_link_libraries(movies Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS movies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
