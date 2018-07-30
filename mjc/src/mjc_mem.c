#include "mjc.h"

void *mjc_malloc(size_t malloc_size)
{
    void *mjc_ram = malloc(malloc_size);
    if(mjc_ram == NULL)
    {
        printf("malloc error!\n");
    }
    return mjc_ram;
}

void *mjc_free(void *mjc_ptr)
{
    if(mjc_ptr != NULL)
    {
        free(mjc_ptr);
    }
    return NULL;
}