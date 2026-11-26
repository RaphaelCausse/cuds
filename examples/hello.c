#include <stdio.h>
#include <cuds/cuds.h>

int main(void)
{
    if (!CUDS_CHECK_VERSION())
    {
        fprintf(stderr, "Incompatible CUDS library (%s)\n", cuds_version_string());
        return 1;
    }

    printf(     
        "Hello cuds %s !\nBuilt with %s for %s (%s %s)%s",
        cuds_version_string(),
        cuds_compiler(),
        cuds_platform(),
        CUDS_PLATFORM_FAMILY,
        cuds_arch(),
#if defined(_CUDS_DEBUG)
        ", in debug mode.\n"
#elif defined(_CUDS_RELEASE)
        ", in release mode.\n"
#else
        "\n"
#endif
    );

#if defined (__STDC_VERSION__)
    printf("ISO C: %lu\n", __STDC_VERSION__);
#endif

    return 0;
}
