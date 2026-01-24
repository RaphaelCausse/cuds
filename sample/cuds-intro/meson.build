# --------------------------------------------------
# Meson Build file for sample project cuds-intro
# --------------------------------------------------
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

# --------------------------------------------------
# Build options
# --------------------------------------------------
cc = meson.get_compiler('c')

c_args = []

if get_option('buildtype') == 'release'
    c_args += ['-DNDEBUG']
else
    c_args += ['-DDEBUG']
endif

add_project_arguments(
    cc.get_supported_arguments(c_args),
    language : 'c'
)

# --------------------------------------------------
# Source files
# --------------------------------------------------
source_files = files(
    'src/main.c',
    'src/hello.c',
)

# --------------------------------------------------
# Dependencies
# --------------------------------------------------
cuds_lib = dependency('cuds', required : true)

# --------------------------------------------------
# Executable
# --------------------------------------------------
executable(
    meson.project_name(),
    source_files,
    dependencies : cuds_lib,
    install : false
)
