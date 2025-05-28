#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "cuds/version.h"
#include "cuds/main.h"

int main(int argc, char *argv[])
{
    printf("cuds v%s\n", CUDS_VERSION_STRING);

    t_type m;

    m.a = 10;
    m.b = true;

    uint32_t a = main_get_a(&m);
    bool b = main_get_b(&m);

    assert(a == m.a);
    assert(b == m.b);

    return EXIT_SUCCESS;
}