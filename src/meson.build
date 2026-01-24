cuds_sources = files()

cuds_modules = {
    'value': ['value.c'],
    'version': ['version.c'],
}

foreach module, source_list : cuds_modules
    cuds_sources += files(join_paths(module, source_list))
endforeach

# Git revision generation
cuds_sources += vcs_tag(
    command: ['git', 'rev-parse', 'HEAD'],
    input: 'version/revision.c.in',
    output: 'cuds_revision.c',
)
