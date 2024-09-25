#include "../headers/library.h"
#include "../headers/swap.h"

void swap(void* a, void* b, size_t elem)
{
    // char** first = (char** )a;
    // char** second = (char** )b;

    printf(RED "Swaping:\n" DELETE_COLOR);

    // char* buf = *((char** )a);
    // *((char** )a) = *((char** )b);
    // *((char** )b) = buf;

    line_ptr_begin_end buf = *(line_ptr_begin_end* )a;
    *(line_ptr_begin_end* )a = *(line_ptr_begin_end* )b;
    *(line_ptr_begin_end* )b = buf;

    printf("\n");
}
