#include "../headers/library.h"
#include "../headers/create_line_ptr.h"

void create_line_ptr(char* ptr_line, struct line_ptr_begin_end* ptr, int lines_amount, unsigned long int size)
{
    assert(ptr);
    assert(ptr_line);
    assert(isfinite(lines_amount));
    assert(isfinite(size));

    printf("Creating line pointers\n");

    (*(ptr + 0)).begin = &ptr_line[0];

    int lines_count = 0;

    for(unsigned long int i = 0; (i < size) && (lines_count < lines_amount); i++)
    {
        if(ptr_line[i] == '\0')
        {
            (*(ptr + lines_count)).end = (ptr_line + i - 1);
            (*(ptr + lines_count + 1)).begin = (ptr_line + i + 1);
            printf("line %d: %s\n", lines_count, (*(ptr + lines_count )).begin);
            lines_count++;
        }
    }
    (*(ptr + lines_count)).begin = NULL;
    (*(ptr + lines_count)).end = NULL;
}
