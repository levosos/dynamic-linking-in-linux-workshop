// BUILD:   gcc executable/3.c -o exe -lcommon -L.
// RUN:     LD_LIBRARY_PATH=. ./exe

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern int foo();

void main()
{
    const int fooed = foo();
    printf("[exe] foo() returned %d\n", fooed);

    char command[30] = { 0 };
    sprintf(command, "cat /proc/%d/maps", getpid());
    system(command);
}
