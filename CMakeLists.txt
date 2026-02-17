cmake_minimum_required(VERSION 3.16)

# --------------------------------------------------
# Project
# --------------------------------------------------

project(
    cuds
    VERSION 0.0.0
    LANGUAGES C
    DESCRIPTION "C Utilities and Data Structures library"
)

# --------------------------------------------------
# Options
# --------------------------------------------------

option(CUDS_BUILD_SHARED "Build shared library" ON)
option(CUDS_BUILD_STATIC "Build static library" ON)
option(CUDS_BUILD_TESTS  "Build tests"          ON)

# --------------------------------------------------
# Compiler flags
# --------------------------------------------------

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG" CACHE STRING "" FORCE)

set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE STRING "" FORCE)

# --------------------------------------------------
# Subdirectories
# --------------------------------------------------

include(GNUInstallDirs)

add_subdirectory(include)
add_subdirectory(src)

if(CUDS_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# --------------------------------------------------
# CMake package config
# --------------------------------------------------

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cudsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/templates/cudsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cudsConfig.cmake
    INSTALL_DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/cuds
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cudsConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cudsConfigVersion.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/cuds
)

# --------------------------------------------------
# pkg-config
# --------------------------------------------------

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/templates/cuds.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/cuds.pc
    @ONLY
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cuds.pc
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
