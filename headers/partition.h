#ifndef PARTITION_HEADER
#define PARTITION_HEADER

#include "library.h"

size_t partition(void* ptr_void, size_t amount, size_t elem_size, int(*comparator)(void*a, void* b) );

#endif
