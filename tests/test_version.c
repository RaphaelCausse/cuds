#include <stdio.h>
#include <stdlib.h>
#include "cuds/version.h"

int main(void)
{
    int version = cuds_version_get();

    printf("CUDS version: %d.%d.%d\n", CUDS_VERSIONNUM_MAJOR(version), CUDS_VERSIONNUM_MINOR(version), CUDS_VERSIONNUM_PATCH(version));
    printf("CUDS version: %d.%d.%d\n", CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH);

    if (version != CUDS_VERSION)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
