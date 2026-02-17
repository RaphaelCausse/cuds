# --------------------------------------------------
# Tests
# --------------------------------------------------

set(CUDS_TESTS
    test_version
)

foreach(test_name IN LISTS CUDS_TESTS)
    add_executable(${test_name} ${test_name}.c)

    target_link_libraries(${test_name} PRIVATE cuds_static)

    target_include_directories(${test_name} PRIVATE ${CUDS_INCLUDE_DIR})

    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
