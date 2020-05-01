// BUILD:   gcc executable/8.c -o exe -lcommon -ldl -L.
// RUN:     LD_LIBRARY_PATH=. ./exe

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <dlfcn.h>

#include <stddef.h>
#include <sys/mman.h>

extern int foo();

void bar()
{
    printf("[exe] in original bar()\n");
}

void mitm_bar()
{
    printf("[exe] in MITM bar(). muhaha.\n");
}

void main()
{
    Dl_info i;

    if (dladdr(main, /* out */ &i) == 0)
    {
        printf("ERROR: dladdr() failed\n");
        exit(1);
    }

    printf("[exe] executable was loaded to %p\n", i.dli_fbase);

    void * const h = dlopen("libcommon.so", RTLD_NOW); // better use RTLD_NOLOAD
    if (h == NULL)
    {
        printf("ERROR: dlopen() failed\n");
        exit(1);
    }

    void * const proc = dlsym(h, "foo");
    if (proc == NULL)
    {
        printf("ERROR: dlsym() failed\n");
        exit(1);
    }

    if (dladdr(proc, /* out */ &i) == 0)
    {
        printf("ERROR: dladdr() failed\n");
        exit(1);
    }

    printf("[exe] libcommon.so was loaded to %p\n", i.dli_fbase);

    // this is the offset of the relocation entry for 'bar' in .rela.plt
    // this could be retrieved from the information within the ELF, of course,
    // although it is a bit of hard work and we just copy it from "readelf --all --wide libcommon.so | less"
    //
    const size_t offset = 0x201020;

    void ** const at = (void ** const)((size_t)i.dli_fbase + offset);

    printf("[exe] exe!bar() is at %p\n", bar);
    printf("[exe] exe!foo() is at %p\n", foo); // plt stub probably
    printf("[exe] lib!foo() is at %p\n", proc);
    printf("[exe] rela bar() is %p (used at %p)\n", *at, at);

    // this is here just for backup
    //
    // if (mprotect(0x601000, 4096, PROT_READ | PROT_WRITE) == -1)
    // {
    //     printf("ERROR: could not mprotect()\n");
    //     exit(1);
    // }

    *at = mitm_bar;

    printf("[exe] now, rela bar() will be at %p\n", *at);

    printf("[exe] calling foo()\n");
    const int fooed = foo();
    printf("[exe] foo() returned %d\n", fooed);
}
