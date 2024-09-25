#include "../headers/library.h"

#include "../headers/create_line_ptr.h"
#include "../headers/custom_strcmp.h"
#include "../headers/delete_slash.h.h"
#include "../headers/MySort.h"
#include "../headers/output.h"
#include "../headers/swap.h"
#include "../headers/QuickSort.h"
#include "../headers/partition.h"

int main()
{
    FILE* poem_file = fopen("Onegin.txt", "rw");

    struct stat file_info = {};

    stat("Onegin.txt", &file_info);

    unsigned long int size_of_input = (unsigned long int)file_info.st_size;

    char* char_input_ptr = (char*)calloc(size_of_input, sizeof(char));
    // printf("%ld \n", ftell(poem_file));
    char* char_input_ptr_copy = (char*)calloc(size_of_input, sizeof(char));

    fread(char_input_ptr, sizeof(char), size_of_input, poem_file);

    fseek(poem_file, sizeof(char) * 0L, SEEK_SET);
    fread(char_input_ptr_copy, sizeof(char), size_of_input, poem_file);

    int lines_amount = 0;

    delete_slash_nulls_count_lines(char_input_ptr, size_of_input, &lines_amount); // for both sorts

    struct line_ptr_begin_end* Bubble_sorted_begin = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));
    struct line_ptr_begin_end* Bubble_sorted_end = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));

    struct line_ptr_begin_end* Qsort_sorted_begin = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));
    struct line_ptr_begin_end* Qsort_sorted_end = (line_ptr_begin_end* )calloc((unsigned long int)lines_amount + 1, sizeof(line_ptr_begin_end));


    for(int i = 0; i < lines_amount; i++)
    {
        (*(Bubble_sorted_begin + i)).begin = NULL;
        (*(Bubble_sorted_begin + i)).end = NULL;
        (*(Bubble_sorted_end + i)).begin = NULL;
        (*(Bubble_sorted_end + i)).end = NULL;

        (*(Qsort_sorted_begin + i)).begin = NULL;
        (*(Qsort_sorted_begin + i)).end = NULL;
        (*(Qsort_sorted_end + i)).begin = NULL;
        (*(Qsort_sorted_end + i)).end = NULL;
    }

    printf("Lines amount: %d\n", lines_amount);

    /********** Pointers to Bubble sorted lines **********/
    create_line_ptr(char_input_ptr, Bubble_sorted_begin, lines_amount, size_of_input); //for sorting from beginning
    create_line_ptr(char_input_ptr, Bubble_sorted_end, lines_amount, size_of_input); //for sorting from end

    /********** Pointers to Qsort sorted lines **********/
    create_line_ptr(char_input_ptr, Qsort_sorted_begin, lines_amount, size_of_input); //for sorting from beginning
    create_line_ptr(char_input_ptr, Qsort_sorted_end, lines_amount, size_of_input); //for sorting from end

    /********** Different Sortings and Outputtings **********/
    MySort(Bubble_sorted_begin, lines_amount, sizeof(char* ), custom_strcmp_begin); //BubbleSort from beginning
    MySort(Bubble_sorted_end, lines_amount, sizeof(char* ), custom_strcmp_end); //BubbleSort from end

    QuickSort(Qsort_sorted_begin, lines_amount, sizeof(char* ), custom_strcmp_begin); //QuickSort from beginning
    QuickSort(Qsort_sorted_end, lines_amount, sizeof(char* ), custom_strcmp_end); //QuickSort from end

    /****** Different Outputtings ******/
    printf(PURPLE "Bubble-sorted from beginning:\n" DELETE_COLOR);
    output(Bubble_sorted_begin, lines_amount); //for sorting from begining

    printf(PURPLE "Bubble-sorted from end:\n" DELETE_COLOR);
    output(Bubble_sorted_end, lines_amount); //for sorting from end

    printf(PURPLE "QuickSort sorted from beginning:\n" DELETE_COLOR);
    output(Qsort_sorted_begin, lines_amount);

    printf(PURPLE "QuickSort sorted from end:\n" DELETE_COLOR);
    output(Qsort_sorted_end, lines_amount);

    printf(YELLOW "Original:\n" DELETE_COLOR);
    fwrite(char_input_ptr_copy, sizeof(char), size_of_input / sizeof(char), stdout);

    /****** Cleaning dynamic memory and Closing file ******/
    free(char_input_ptr);
    free(char_input_ptr_copy);

    free(Bubble_sorted_begin);
    free(Bubble_sorted_end);

    free(Qsort_sorted_begin);
    free(Qsort_sorted_end);

    fclose(poem_file);
    return 0;
}

