# --------------------------------------------------
# Public headers
# --------------------------------------------------

set(CUDS_PUBLIC_HEADERS
    # Main public header
    cuds/cuds.h
    # Public headers
    cuds/cuds_api.h
    cuds/cuds_common.h
    cuds/cuds_platform_defines.h
    cuds/cuds_platform.h
    cuds/cuds_types.h
    cuds/cuds_units.h
    cuds/cuds_version.h
)

install(
    FILES ${CUDS_PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
