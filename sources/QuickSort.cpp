#include "../headers/library.h"
#include "../headers/QuickSort.h"
#include "../headers/partition.h"
#include "../headers/custom_strcmp.h"

int QuickSort(void* ptr_void, size_t amount, size_t elem_size, int (*comparator)(void* a, void* b) )
{
    line_ptr_begin_end* ptr = (line_ptr_begin_end* )ptr_void;
    if(amount <= 1)
    {
        printf(RED "Too small array\n\n" DELETE_COLOR);
        return 0;
    }
    else
    {
        size_t q = partition(ptr, amount, elem_size, comparator);

        QuickSort(ptr, q, sizeof(char* ), comparator);  // до q - 1
        QuickSort(ptr + q + 1, amount - q - 1, sizeof(char* ), comparator);  // от q + 1
    }

    return 0;
}
