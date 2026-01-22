cuds_sources = files(
    'cuds.c',
)

# Dictionary containing for each module the list of its source files
cuds_modules = {
    'value' : ['value.c']
}

foreach module, source_list : cuds_modules
    cuds_sources += files(join_paths(module, source_list))
endforeach
