// gcc library/8.c -shared -fPIC -o libcommon.so

#include <stdio.h>

extern void bar();

int foo()
{
    puts("[lib] in foo(). calling bar()");
    bar();
    return 217;
}
