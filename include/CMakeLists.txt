# --------------------------------------------------
# Public headers
# --------------------------------------------------

set(CUDS_PUBLIC_HEADERS
    # Main public header
    cuds/cuds.h
    # Public headers
    cuds/algorithm.h
    cuds/export.h
    cuds/platform.h
    cuds/types.h
    cuds/units.h
    cuds/version.h
)

install(
    FILES ${CUDS_PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
