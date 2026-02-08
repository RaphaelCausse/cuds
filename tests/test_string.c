#include <stdio.h>
#include <stdlib.h>
#include "cuds/string.h"

int main(void)
{
    cuds_string_t str = cuds_string_new("Hello world !");
    cuds_string_t str_empty = cuds_string_new("");
    cuds_string_t str_null = cuds_string_new(NULL);

    printf("Cuds str: %s | %p | %zu\n", str, str, cuds_string_len(str));
    printf("Cuds str_empty: %s | %p | %zu\n", str_empty, str_empty, cuds_string_len(str_empty));
    printf("Cuds str_null: %s | %p | %zu\n", str_null, str_null, cuds_string_len(str_null));

    cuds_string_free(str);
    cuds_string_free(str_empty);
    cuds_string_free(str_null);

    printf("Cuds str: %s | %p\n", str, str);
    printf("Cuds str_empty: %s | %p\n", str_empty, str_empty);
    printf("Cuds str_null: %s | %p\n", str_null, str_null);

    return EXIT_SUCCESS;
}
