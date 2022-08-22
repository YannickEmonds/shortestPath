cmake_minimum_required(VERSION 3.11)
project( shortest_path LANGUAGES CXX )

add_executable( ${PROJECT_NAME} src/main.cpp )
target_include_directories( ${PROJECT_NAME}
                            PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
                            )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
