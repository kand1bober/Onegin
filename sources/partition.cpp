#include "../headers/library.h"
#include "../headers/QuickSort.h"
#include "../headers/partition.h"
#include "../headers/custom_strcmp.h"

size_t partition(void* ptr_void, size_t amount, size_t elem_size, int(*comparator)(void*a, void* b) )
{
    /*** cast to (char**) ***/
    line_ptr_begin_end* ptr = (line_ptr_begin_end* )ptr_void;   !!!!!!!!!!!!!

    printf("Partition:\n");

    // int p = 0;
    printf("amount: %ld\n", amount );
    int i = -1;

    /*
    printf("ARRAY IN PARTITION (BEFORE):\n");
    for(int g = 0; g < amount; g++)
    {
        printf("%d ", *(ptr + g) );
    }
    printf("\n\n");
    */

    for(size_t j = 0; j < amount - 1; j++)
    {
        if( comparator( (ptr + j), (ptr + amount - 1) ) <= 0 )
        {
            i++;
            (size_t)i;

            // ****CHANGING j-element and i-element****
            // printf(YELLOW "CHANGING i-element and j-element\n" DELETE_COLOR);
            // printf(GREEN "Before changing: %d -- i-element, %d -- j-element, i -- %d, j -- %d \n" DELETE_COLOR, *(ptr + i), *(ptr + j), i, j );

            line_ptr_begin_end buf_main = *(ptr + j);
            *(ptr + j) = *(ptr + i);
            *(ptr + i) = buf_main;

            // printf(BLUE "After changing: %d -- i-element, %d -- j-element, i -- %d, j -- %d \n" DELETE_COLOR, *(ptr + i), *(ptr + j), i, j );
        }
        else
            continue;
    }

    // printf(PURPLE "MAKING NEW PIVOT\n" DELETE_COLOR);
    i++;
    line_ptr_begin_end buf_last = *(ptr + amount - 1);
    *(ptr + amount - 1) = *(ptr + i);
    *(ptr + i) = buf_last;
    // printf(PURPLE "NEXT PIVOT: number: %d, Value: %d\n" DELETE_COLOR, i, *(ptr + i) );
    // printf("\n");

    /*
    printf("ARRAY IN PARTITION (AFTER):\n");
    for(int g = 0; g < amount; g++)
    {
        printf("%d ", *(ptr + g) );
    }
    printf("\n\n");
    */

    return i;
}
