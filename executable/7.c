// BUILD:   gcc executable/7.c -o exe -lcommon -L.
// RUN:     LD_LIBRARY_PATH=. ./exe

#include <stdio.h>

extern int foo();

void main()
{
    (void) foo();
}
