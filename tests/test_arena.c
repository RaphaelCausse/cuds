#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cuds/cuds.h>

#define ARENA_SIZE ((size_t)4)

int main(void)
{
    cuds_arena_t *p_arena = cuds_arena_create(ARENA_SIZE);
    if (p_arena == NULL)
    {
        printf("Error %d: Failed to created arena of capacity %zu bytes: %s.\n", errno, ARENA_SIZE, strerror(errno));
        return EXIT_FAILURE;
    }
    printf("Created arena of capacity %zu bytes (@0x%p).\n", ARENA_SIZE, (void *)p_arena);

    uint32_t *x1 = cuds_arena_alloc(p_arena, sizeof(uint32_t));
    if (x1 == NULL)
    {
        printf("Error %d: Failed to allocated %zu bytes: %s.\n", errno, sizeof(*x1), strerror(errno));
    }
    else
    {
        printf("Allocated %zu bytes (@0x%p).\n", sizeof(*x1), (void *)x1);
        printf("Remaining %zu bytes in arena.\n", cuds_arena_remaining(p_arena));
    }

    uint64_t *x2 = cuds_arena_alloc(p_arena, sizeof(*x2));
    if (x2 == NULL)
    {
        printf("Error %d: Failed to allocated %zu bytes: %s.\n", errno, sizeof(*x2), strerror(errno));
    }
    else
    {
        printf("Allocated %zu bytes (@0x%p).\n", sizeof(*x2), (void *)x2);
        printf("Remaining %zu bytes in arena.\n", cuds_arena_remaining(p_arena));
    }

    p_arena = cuds_arena_destroy(p_arena);
    printf("Destroyed arena (@0x%p).\n", (void *)p_arena);

    return EXIT_SUCCESS;
}