// gcc library/7.c -shared -fPIC -o libcommon.so

#include <stdio.h>

int foo()
{
    puts("[lib] in foo()");
    return 217;
}
