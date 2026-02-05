cmake_minimum_required(VERSION 3.16)

project(cuds_intro LANGUAGES C)

find_package(cuds REQUIRED)

set(SOURCES
    src/main.c
    src/hello.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE cuds::cuds_shared)
