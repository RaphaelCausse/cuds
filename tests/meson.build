cuds_tests = {
    'test_version': ['test_version.c'],
}

foreach test_name, src_list : cuds_tests
    test_sources = files(src_list)

    test_exe = executable(
        test_name,
        test_sources,
        include_directories: cuds_includedir,
        link_with: cuds_lib,
        install: false,
        build_by_default: false,
    )

    test(test_name, test_exe)
endforeach
