#include <stdio.h>
#include <stdlib.h>
#include "cuds/version.h"

int main(void)
{
    int version = cuds_version();

    printf("CUDS version (link)    : %d.%d.%d (%08X)\n", CUDS_VERSIONNUM_MAJOR(version), CUDS_VERSIONNUM_MINOR(version), CUDS_VERSIONNUM_PATCH(version), version);
    printf("CUDS version (include) : %d.%d.%d (%08X)\n", CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH, CUDS_VERSION);
    printf("CUDS version (string)  : %s\n", CUDS_VERSION_STRING);
    printf("CUDS revision (git)    : %s\n", CUDS_REVISION);

    if (version != CUDS_VERSION)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
