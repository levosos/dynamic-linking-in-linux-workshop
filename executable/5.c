// BUILD:   gcc executable/5.c -o exe -lcommon -L.
// RUN:     LD_LIBRARY_PATH=. ./exe

#include <stdio.h>

extern int foo();

void bar()
{
    printf("[exe] in bar()\n");
}

void main()
{
    printf("[exe] calling foo()\n");
    const int fooed = foo();
    printf("[exe] foo() returned %d\n", fooed);
}
