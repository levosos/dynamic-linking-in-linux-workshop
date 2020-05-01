// BUILD:   gcc executable/2.c -o exe -lcommon -L.
// RUN:     LD_LIBRARY_PATH=. ./exe

#include <stdio.h>

extern int foo();

void main()
{
    const int fooed = foo();
    printf("[exe] foo() returned %d\n", fooed);
}
