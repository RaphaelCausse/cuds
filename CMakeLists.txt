cmake_minimum_required(VERSION 3.16)

# --------------------------------------------------
# Project
# --------------------------------------------------

project(
    cuds
    VERSION 0.1.0
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
# Standard & build type
# --------------------------------------------------

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(GNUInstallDirs)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

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
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

# --------------------------------------------------
# pkg-config
# --------------------------------------------------

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/${PROJECT_NAME}.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
    @ONLY
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
