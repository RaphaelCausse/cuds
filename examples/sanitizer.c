#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cuds/cuds.h>

int main(void)
{
    if (!CUDS_CHECK_VERSION())
    {
        fprintf(stderr, "Incompatible CUDS library (%s)\n", cuds_version_string());
        return 1;
    }

    printf("Hello cuds %s !\n", cuds_version_string());

    /* 1. Trigger UBSan: signed integer overflow */
    int max = INT_MAX;
    int overflow = max + 1;
    printf("UBSan test : %d\n", overflow);

    /* 2. Trigger ASan: heap buffer overflow */
    int *arr = malloc(3 * sizeof(int));
    if (arr != NULL)
    {
        arr[3] = 42;
        printf("ASan test : %d\n", arr[3]);
        free(arr);
    }

    return 0;
}
