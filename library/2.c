// gcc library/2.c -shared -fPIC -o libcommon.so

#include <stdio.h>

int foo()
{
    puts("[lib] in foo()");
    return 217;
}
