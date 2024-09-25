#include "../headers/library.h"

#include "../headers/create_line_ptr.h"
#include "../headers/custom_strcmp.h"
#include "../headers/delete_slash.h.h"
#include "../headers/MySort.h"
#include "../headers/output.h"
#include "../headers/swap.h"

int main()
{
    FILE* poem_file = fopen("Onegin.txt", "rw");

    struct stat file_info = {};

    stat("Onegin.txt", &file_info);

    unsigned long int size_of_input = (unsigned long int)file_info.st_size;

    char* char_input_ptr = (char*)calloc(size_of_input, sizeof(char));
    printf("%ld \n", ftell(poem_file));
    char* char_input_ptr_copy = (char*)calloc(size_of_input, sizeof(char));

    fread(char_input_ptr, sizeof(char), size_of_input, poem_file);

    fseek(poem_file, sizeof(char) * 0L, SEEK_SET);
    fread(char_input_ptr_copy, sizeof(char), size_of_input, poem_file);

    int lines_amount = 0;

    delete_slash_nulls_count_lines(char_input_ptr, size_of_input, &lines_amount); // for both sorts

    struct line_ptr_begin_end* sorted_lines_from_begin = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));
    struct line_ptr_begin_end* sorted_lines_from_end = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));

    for(int i = 0; i < lines_amount; i++)
    {
        (*(sorted_lines_from_begin + i)).begin = NULL;
        (*(sorted_lines_from_begin + i)).end = NULL;
        (*(sorted_lines_from_end + i)).begin = NULL;
        (*(sorted_lines_from_end + i)).end = NULL;
    }

    printf("Lines amount: %d\n", lines_amount);

    create_line_ptr(char_input_ptr, sorted_lines_from_begin, lines_amount, size_of_input); //for sorting from begining
    create_line_ptr(char_input_ptr, sorted_lines_from_end, lines_amount, size_of_input); //for sorting from end

    MySort(sorted_lines_from_begin, lines_amount, sizeof(char* ), custom_strcmp_begin); //for sorting from begining
    MySort(sorted_lines_from_end, lines_amount, sizeof(char* ), custom_strcmp_end); //for sorting from end

    output(sorted_lines_from_begin, lines_amount); //for sorting from begining
    output(sorted_lines_from_end, lines_amount); //for sorting from end
    printf(YELLOW "Original:\n" DELETE_COLOR);
    fwrite(char_input_ptr_copy, sizeof(char), size_of_input / sizeof(char), stdout);

    free(char_input_ptr);
    free(char_input_ptr_copy);
    free(sorted_lines_from_begin);
    free(sorted_lines_from_end);
    fclose(poem_file);
    return 0;
}

