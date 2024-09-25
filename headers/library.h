#ifndef LIBRARY_HEADER
#define LIBRARY_HEADER

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#define DELETE_COLOR "\u001b[0m"
#define GREEN "\u001b[32;1m"
#define RED "\u001b[31;1m"
#define YELLOW "\u001b[33;1m"
#define PURPLE "\u001b[35;1m"
#define WHITE "\u001b[37;1m"
#define BLUE "\u001b[36;1m"
#define SINIY "\u001b[34;1m"

struct line_ptr_begin_end
{
    char* begin;
    char* end;
};

#endif
