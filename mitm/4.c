// gcc mitm/4.c -shared -fPIC -o mitm.so

#include <stdio.h>

int foo()
{
    puts("[mitm] in foo(). muhaha.");
    return 42;
}
