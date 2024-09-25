#include "../headers/library.h"
#include "../headers/MySort.h"
#include "../headers/custom_strcmp.h"
#include "../headers/swap.h"

void MySort(void* ptr, size_t lines_amount, size_t el_size, int(*comparator)(void* a, void* b))
{
    assert(ptr);
    assert(isfinite(lines_amount));
    assert(isfinite(el_size));
    assert(comparator);

    printf(PURPLE " MySort begins:\n" DELETE_COLOR);

    for(size_t count = 0; count < lines_amount - 1; count++)
    {
        printf(SINIY "ITERATION  %ld\n" DELETE_COLOR, count);
        for(size_t count_line = 0; count_line < lines_amount - 1; count_line++)
        {
            if( (comparator( (line_ptr_begin_end* )ptr + count_line, (line_ptr_begin_end* )ptr + count_line + 1 ) ) > 0)
            {
                swap( (line_ptr_begin_end* )ptr + count_line,  (line_ptr_begin_end* )ptr + count_line + 1, sizeof( (*((line_ptr_begin_end* )ptr + count_line )).begin ) );
            }
            else
                continue;
        }
    }
}
