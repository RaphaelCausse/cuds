#include <stdio.h>
#include <stdlib.h>
#include <cuds/cuds.h>

#define ARENA_SIZE (CUDS_KB(1))

typedef struct
{
    float64_t x;
    float64_t y;
    float64_t z;
} vec3_t;

int main(void)
{
    cuds_arena_t *p_arena = cuds_arena_create(ARENA_SIZE);
    if (p_arena == NULL)
    {
        printf("Failed to created arena of capacity %zu bytes.\n", ARENA_SIZE);
        return EXIT_FAILURE;
    }
    printf("Created arena of capacity %zu bytes @0x%p.\n", ARENA_SIZE, (void *)p_arena);

    uint32_t *x1 = cuds_arena_alloc(p_arena, sizeof(uint32_t));
    if (x1 == NULL)
    {
        printf("Failed to allocated %zu bytes.\n", sizeof(*x1));
    }
    printf("Allocated %zu bytes @0x%p.\n", sizeof(*x1), (void *)x1);

    printf("Remaining %zu bytes in arena.\n", cuds_arena_remaining(p_arena));

    size_t count = 0;
    while (true)
    {
        vec3_t *vec = cuds_arena_alloc(p_arena, sizeof(vec3_t));
        if (vec == NULL)
        {
            printf("Failed to allocated %zu bytes (remaining %zu).\n", sizeof(*vec), cuds_arena_remaining(p_arena));
            break;
        }
        printf("[%zu] Allocated %zu bytes @0x%p.\n", count, sizeof(*vec), (void *)vec);
        printf("[%zu] Remaining %zu bytes in arena.\n", count, cuds_arena_remaining(p_arena));

        count++;
    }

    p_arena = cuds_arena_destroy(p_arena);
    printf("Destroyed arena (@0x%p).\n", (void *)p_arena);

    return EXIT_SUCCESS;
}