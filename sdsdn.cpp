int main()
{

    int (*curr      compare)( const void* a, const void* b) = NULL

    if( strcmp ( argv[1], "forward") == 0)  currCompare =         LineCmpForwadrd;
    else ... currCompare = LineCmpBack

    Compare_func currCompare = ( strmcp( argv[1], "forward") == 0 )? LineCmpForward : LineCmpBack;

    ...

    qsort(data, ... , currCompare)





}


struct Onegin

    typedef struct {
        int ...
        char* ...
    } Onegin;
