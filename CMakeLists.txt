cmake_minimum_required(VERSION 3.16)
project(mi_app_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_CLANG_TIDY "Run clang-tidy during build" OFF)

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY
            ${CLANG_TIDY_EXE};
            -header-filter=.;
            -warnings-as-errors=*)
    endif()
endif()

add_library(core src/suma.cpp)
target_include_directories(core PUBLIC include)

add_executable(mi_app src/main.cpp)
target_link_libraries(mi_app PRIVATE core)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests tests/test_suma.cpp)
target_link_libraries(unit_tests PRIVATE core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)