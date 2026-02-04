# --------------------------------------------------
# CUDS source modules
# --------------------------------------------------

set(CUDS_MODULES
    value
    version
)

set(CUDS_SOURCES)

foreach(module IN LISTS CUDS_MODULES)
    file(GLOB module_sources CONFIGURE_DEPENDS ${module}/*.c)
    list(APPEND CUDS_SOURCES ${module_sources})
endforeach()

# --------------------------------------------------
# Git revision generation
# --------------------------------------------------

find_package(Git QUIET)

if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE CUDS_GIT_REVISION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(CUDS_GIT_REVISION "unknown")
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version/revision.c.in
    ${CMAKE_CURRENT_BINARY_DIR}/cuds_revision.c
    @ONLY
)

list(APPEND CUDS_SOURCES
    ${CMAKE_CURRENT_BINARY_DIR}/cuds_revision.c
)

# --------------------------------------------------
# Libraries
# --------------------------------------------------

# Shared library
if(CUDS_BUILD_SHARED)
    add_library(cuds_shared SHARED ${CUDS_SOURCES})

    target_compile_definitions(cuds_shared
        PRIVATE
            CUDS_SHARED
            CUDS_BUILD
    )

    set_target_properties(cuds_shared PROPERTIES
        OUTPUT_NAME cuds
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )
endif()

# Static library
if(CUDS_BUILD_STATIC)
    add_library(cuds_static STATIC ${CUDS_SOURCES})

    target_compile_definitions(cuds_static
        PRIVATE
            CUDS_STATIC
    )

    set_target_properties(cuds_static PROPERTIES
        OUTPUT_NAME cuds
    )
endif()

# --------------------------------------------------
# Common configuration
# --------------------------------------------------

foreach(target cuds_shared cuds_static)
    if(TARGET ${target})
        target_include_directories(${target}
            PUBLIC
                $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

        install(
            TARGETS ${target}
            EXPORT cudsTargets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()
endforeach()

# --------------------------------------------------
# Export targets
# --------------------------------------------------

# Export the targets
install(
    EXPORT cudsTargets
    FILE cudsTargets.cmake
    NAMESPACE cuds::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cuds
)