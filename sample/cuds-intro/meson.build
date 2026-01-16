project(
    'cuds-intro',
    'c',
    version : '1.0.0',
    meson_version : '>=0.60.0',
    default_options : [
        'c_std=c99',
        'warning_level=3',
        'buildtype=release'
    ]
)

cc = meson.get_compiler('c')

source_files = files(
    'src/main.c',
    'src/hello.c',
)

cuds_prefix = get_option('prefix')

cuds_inc_dir = include_directories(join_paths(cuds_prefix, 'include'))
cuds_lib_dir = join_paths(cuds_prefix, 'lib')

cuds_lib = cc.find_library(
    'cuds',
    dirs : cuds_lib_dir,
    required : true
)

executable(
    meson.project_name(),
    source_files,
    include_directories : cuds_inc_dir,
    dependencies : cuds_lib,
    install : false
)
