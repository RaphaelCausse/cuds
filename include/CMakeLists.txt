# --------------------------------------------------
# Public headers
# --------------------------------------------------

set(CUDS_PUBLIC_HEADERS
    cuds/cuds.h
    cuds/export.h
    cuds/value.h
    cuds/version.h
)

install(
    FILES ${CUDS_PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cuds
)
