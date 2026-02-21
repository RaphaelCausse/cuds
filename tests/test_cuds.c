#include <stdio.h>
#include <stdlib.h>
#include <cuds/cuds.h>

int main(void)
{
    const size_t nb_kb = 4;
    const size_t nb_mb = 64;
    const size_t nb_gb = 1;

    const size_t kb = CUDS_KB(nb_kb);
    const size_t mb = CUDS_MB(nb_mb);
    const size_t gb = CUDS_GB(nb_gb);

    printf("%zu KB = %zu bytes\n", nb_kb, kb);
    printf("%zu MB = %zu bytes\n", nb_mb, mb);
    printf("%zu GB = %zu bytes\n", nb_gb, gb);

    return EXIT_SUCCESS;
}
