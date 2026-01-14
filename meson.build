# --------------------------------------------------
# Meson Build File for CUDS Library
# --------------------------------------------------
project(
    'cuds',
    'c',
    version : '0.1.0',
    license: ['MIT'],
    meson_version : '>=0.60.0',
    default_options : [
        'c_std=c99',
        'warning_level=3',
        'default_library=both',
        'buildtype=release'
    ]
)


# --------------------------------------------------
# Build options
# --------------------------------------------------
cc = meson.get_compiler('c')

cuds_c_args = [
    '-Wshadow',
    '-Wconversion',
    '-Wsign-conversion',
    '-Wstrict-prototypes'
]

if get_option('buildtype') == 'release'
    cuds_c_args += ['-DNDEBUG']
elif get_option('buildtype') == 'debug' or get_option('buildtype') == 'debugoptimized' 
    cuds_c_args += ['-DDEBUG']
endif

add_project_arguments(
    cc.get_supported_arguments(cuds_c_args),
    language : 'c'
)

# --------------------------------------------------
# Source files
# --------------------------------------------------
subdir('include')
subdir('src')

# --------------------------------------------------
# Libraries
# --------------------------------------------------
cuds_lib = library(
    meson.project_name(),
    cuds_sources,
    version : meson.project_version(),
    include_directories : cuds_includedir,
    install : true
)

# --------------------------------------------------
# Tests
# --------------------------------------------------
subdir('tests')
