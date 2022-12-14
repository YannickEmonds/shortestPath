cmake_minimum_required(VERSION 3.16)
project( shortest_path LANGUAGES CXX )

add_executable( ${PROJECT_NAME} src/main.cpp 
                                src/dijkstra.cpp
                                src/graph.cpp)
target_include_directories( ${PROJECT_NAME}
                            PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
                            )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)


# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/8d51ffdfab10b3fba636ae69bc03da4b54f8c235.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
set(TEST_EXECS
    test_graph
    test_priority_queue
    test_dijkstra
    )

include(GoogleTest)
foreach(exe IN LISTS TEST_EXECS)
    add_executable( ${exe} "tests/${exe}.cpp" )
    target_include_directories( ${exe} PRIVATE inc )
    target_link_libraries( ${exe} gtest_main gmock gmock_main )
    set_target_properties( ${exe} PROPERTIES CXX_STANDARD 20 )
    gtest_discover_tests( ${exe} )
endforeach()
