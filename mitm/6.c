// gcc mitm/6.c -shared -fPIC -o mitm.so

#include <stdio.h>

void bar()
{
    printf("[mitm] i wish i was called\n");
}
