#include "../headers/library.h"
#include "../headers/output.h"


void output(line_ptr_begin_end* ptr, int size)
{
    printf("\n");
    printf(YELLOW "Outputing:\n" DELETE_COLOR);
    for(int i = 0; i < size; i++)
    {
        fprintf(stdout, "%s\n", (*(ptr + i)).begin );
    }
    printf("\n");
}
