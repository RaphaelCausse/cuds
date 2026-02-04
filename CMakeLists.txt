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
# Standard & build type
# --------------------------------------------------

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# --------------------------------------------------
# Options
# --------------------------------------------------

option(CUDS_BUILD_SHARED "Build shared library" ON)
option(CUDS_BUILD_STATIC "Build static library" ON)
option(CUDS_BUILD_TESTS  "Build tests"          ON)

# --------------------------------------------------
# Subdirectories
# --------------------------------------------------

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
    ${CMAKE_SOURCE_DIR}/cmake/cudsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cudsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cuds
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cudsConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cudsConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cuds
)

# --------------------------------------------------
# pkg-config
# --------------------------------------------------

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/cuds.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/cuds.pc
    @ONLY
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/cuds.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
