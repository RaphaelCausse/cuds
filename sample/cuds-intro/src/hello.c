#include <stdio.h>
#include "hello.h"
#include "cuds/version.h"

void hello(void)
{
    printf("Welcome to CUDS %d.%d.%d !\n", CUDS_VERSION_MAJOR, CUDS_VERSION_MINOR, CUDS_VERSION_PATCH);
}
