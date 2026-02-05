#include <stdio.h>
#include <cuds/version.h>
#include "hello.h"

void hello(void)
{
    printf("Welcome to CUDS %s !\n", CUDS_VERSION_STRING);
    printf("Version  : %08X\n", cuds_version());
    printf("Revision : %s\n", CUDS_REVISION);
}
