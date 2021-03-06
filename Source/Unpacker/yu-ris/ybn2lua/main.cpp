#pragma comment(linker,"/ENTRY:main")
#pragma comment(linker,"/SECTION:.text,ERW /MERGE:.rdata=.text /MERGE:.data=.text")
#pragma comment(linker,"/SECTION:.Amano,ERW /MERGE:.text=.Amano")

#include "ybn2lua.h"
#include "Mem.cpp"

ForceInline Void main2(Int argc, WChar **argv)
{
    if (argc-- == 1)
        return;

    CYBNToLua ytl;

    do
    {
        ytl.ConvertYbnToLua(*++argv);
    } while (--argc);
}

void __cdecl main(Int argc, WChar **argv)
{
    getargsW(&argc, &argv);
    main2(argc, argv);
    exit(0);
}