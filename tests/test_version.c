#include <stdio.h>
#include <stdlib.h>
#include <cuds/cuds.h>

int main(void)
{
    const uint32_t version_linked = cuds_version();

    printf("CUDS version (linked)   : %d.%d.%d (0x%08X)\n", CUDS_VERSIONNUM_MAJOR(version_linked), CUDS_VERSIONNUM_MINOR(version_linked), CUDS_VERSIONNUM_PATCH(version_linked), version_linked);
    printf("CUDS version (included) : %d.%d.%d (0x%08X)\n", CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH, CUDS_VERSION);
    printf("CUDS version (string)   : '%s'\n", CUDS_VERSION_STRING);
    printf("CUDS revision (linked)  : %s\n", cuds_revision());

    if (version_linked != CUDS_VERSION)
    {
        printf("Versions are different, between linked and included.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
