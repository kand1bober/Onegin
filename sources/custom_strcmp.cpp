#include "../headers/library.h"
#include "../headers/custom_strcmp.h"


int custom_strcmp_begin(void* a, void* b)  // compares from begining (from left to right)
{
    char* first = (char* )( (*(line_ptr_begin_end* )a).begin);
    char* second = (char* )( (*(line_ptr_begin_end* )b).begin);
    printf("Comparing: \n");
    printf(GREEN "1: %s\n" DELETE_COLOR, first);
    printf(GREEN "2: %s\n" DELETE_COLOR, second);

    unsigned long int min_size_of_line = 0;
    unsigned long int size_first = strlen( first );
    unsigned long int size_second = strlen( second );

    if(size_first > size_second)
        min_size_of_line = size_second;
    if(size_first < size_second)
        min_size_of_line = size_first;
    else
        min_size_of_line = size_first;

    printf("minimum length: %ld\n", min_size_of_line);

    int diff = 0;
    for(unsigned long int num_in_line_1 = 0, num_in_line_2 = 0; (num_in_line_1 < min_size_of_line) && (num_in_line_2 < min_size_of_line); )
    {
        printf(YELLOW "nums of symbols in line %ld %ld\n" DELETE_COLOR, num_in_line_1, num_in_line_2);

        if( (!isalpha(*(first + num_in_line_1)) ) && (!isalpha(*(second + num_in_line_2)) ) )
        {
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(first + num_in_line_1));
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(second + num_in_line_2));
            num_in_line_1++;
            num_in_line_2++;
            continue;
        }
        else if( !isalpha(*(first+ num_in_line_1)) )
        {
            printf(RED " %c --- not a number\n" DELETE_COLOR, *(first + num_in_line_1));
            num_in_line_1++;
            continue;
        }
        else if( !isalpha(*(second + num_in_line_2)) )
        {
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(second + num_in_line_2));
            num_in_line_2++;
            continue;
        }
        else
        {
            diff = ( toupper( *(first + num_in_line_1) )  - toupper( *(second + num_in_line_2) ) );
            printf("difference between %c and %c: %d\n",toupper( *( first + num_in_line_1 ) ), toupper( *( second + num_in_line_2) ), diff);
            return diff;
        }
    }
    printf("End of comparing!\n");
    return -1;
}



int custom_strcmp_end(void* a, void* b)
{
    // char* first = (char* )( (*(line_ptr_begin_end* )a).begin);
    char* first_end = (char* )( (*(line_ptr_begin_end* )a).end);
    // char* second = (char* )( (*(line_ptr_begin_end* )b).begin);
    char* second_end = (char* )( (*(line_ptr_begin_end* )b).end);   // comparing copies of lines, but it doesn't matter since we dont want their adresses

    printf("Comparing: \n");
    unsigned long int min_size_of_line = 0;
    unsigned long int size_first = strlen( (char* )( (*(line_ptr_begin_end* )a).begin) );
    unsigned long int size_second = strlen( (char* )( (*(line_ptr_begin_end* )b).begin) );

    if(size_first > size_second)
        min_size_of_line = size_second;
    if(size_first < size_second)
        min_size_of_line = size_first;
    else
        min_size_of_line = size_first;

    // printf("minimum length: %ld\n", min_size_of_line);

    int diff = 0;
    for(unsigned long int num_in_line_1 = 0, num_in_line_2 = 0; num_in_line_1 < min_size_of_line, num_in_line_2 < min_size_of_line;)
    {
        printf(YELLOW "nums of symbols in line %ld %ld\n" DELETE_COLOR, num_in_line_1, num_in_line_2);

        if( (!isalpha(*(first_end - num_in_line_1)) ) && (!isalpha(*(second_end - num_in_line_2)) ) )
        {
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(first_end - num_in_line_1));
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(second_end - num_in_line_2));
            num_in_line_1++;
            num_in_line_2++;
            continue;
        }
        else if( !isalpha(*(first_end - num_in_line_1)) )
        {
            printf(RED " %c --- not a number\n" DELETE_COLOR, *(first_end - num_in_line_1));
            num_in_line_1++;
            continue;
        }
        else if( !isalpha(*(second_end - num_in_line_2)) )
        {
            printf(RED "%c --- not a number\n" DELETE_COLOR, *(second_end - num_in_line_2));
            num_in_line_2++;
            continue;
        }
        else
        {
            int diff = ( toupper( *( first_end - num_in_line_1 ) ) - toupper( *( second_end - num_in_line_2) ) );
            printf("difference between %c and %c: %d\n", toupper( *( first_end - num_in_line_1 ) ), toupper( *( second_end - num_in_line_2) ), diff);
            return ( diff = ( toupper( *(first_end - num_in_line_1) )  - toupper( *(second_end - num_in_line_2) ) ) );
        }
    }
    printf("End of comparing!\n");
    return -1;
}
