cmake_minimum_required(VERSION 3.10.0)
project(Figures VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRC_FILES "src/**/*.cpp")
add_library(core ${SRC_FILES})
target_include_directories(core PUBLIC src)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE core)

file(GLOB_RECURSE TEST_FILES "tests/*.cpp")
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE core)

# enable_testing()
# add_subdirectory(tests)