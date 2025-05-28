#ifndef _CUDS_MAIN_H
#define _CUDS_MAIN_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t a;
    bool b;
} t_type;

extern uint32_t main_get_a(t_type *self);
extern bool main_get_b(t_type *self);

#endif // _CUDS_MAIN_H