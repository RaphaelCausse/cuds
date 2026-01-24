#include <stdio.h>
#include "hello.h"
#include "cuds/version.h"

void hello(void)
{
    printf("Welcome to CUDS %s !\n", CUDS_VERSION_STRING);
    printf("Version  : %d\n", cuds_version());
    printf("Revision : %s\n", CUDS_REVISION);
}
