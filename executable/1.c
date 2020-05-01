// BUILD:   gcc executable/1.c -o exe
// RUN:     ./exe

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char command[30] = { 0 };
    sprintf(command, "cat /proc/%d/maps", getpid());
    system(command);
}
