#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cuds/cuds.h>

#define ARENA_SIZE ((size_t)32)

int main(void)
{
    int status = EXIT_SUCCESS;

    cuds_arena_t *p_arena = cuds_arena_create(ARENA_SIZE);
    if (p_arena == NULL)
    {
        printf("Error %d: Failed to created arena of capacity %zu bytes: %s.\n", errno, ARENA_SIZE, strerror(errno));
        return EXIT_FAILURE;
    }
    printf("Created arena of capacity %zu bytes (@0x%p).\n", ARENA_SIZE, (void *)p_arena);

    uint32_t *x1 = cuds_arena_alloc(p_arena, sizeof(*x1));
    if (x1 == NULL)
    {
        printf("Error %d: Failed to allocated %zu bytes: %s.\n", errno, sizeof(*x1), strerror(errno));
        status = EXIT_FAILURE;
    }
    else
    {
        printf(" Allocated %zu bytes (@0x%p), remaining %zu bytes.\n", sizeof(*x1), (void *)x1, cuds_arena_remaining(p_arena));
        *x1 = 1024;
        printf(" *x1 = %u\n", *x1);
    }

    uint64_t *x2 = cuds_arena_alloc(p_arena, sizeof(*x2));
    if (x2 == NULL)
    {
        printf("Error %d: Failed to allocated %zu bytes: %s.\n", errno, sizeof(*x2), strerror(errno));
        status = EXIT_FAILURE;
    }
    else
    {
        printf(" Allocated %zu bytes (@0x%p), remaining %zu bytes.\n", sizeof(*x2), (void *)x2, cuds_arena_remaining(p_arena));
        *x2 = 2048;
        printf(" *x2 = %llu\n", *x2);
    }

    p_arena = cuds_arena_destroy(p_arena);
    printf("Destroyed arena (@0x%p).\n", (void *)p_arena);

    return status;
}