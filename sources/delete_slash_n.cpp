#include "../headers/library.h"
#include "../headers/delete_slash.h.h"

void delete_slash_nulls_count_lines(char* ptr, unsigned long int size, int* lines_amount_ptr)
{
    printf("Deleting slash_n's: \n");
    for(unsigned long int i = 0; i < size; i++)
    {
        if(ptr[i] == '\n')
        {
            ptr[i] = '\0';
            (*lines_amount_ptr)++;
        }
    }
    *(lines_amount_ptr)++;
}
