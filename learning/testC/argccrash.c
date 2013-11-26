#include <stdio.h>

int
main(int argc, char* argv)
{
    int i=0;

    while (i++ < argc) {
        //printf("%x\n", argv); // Junk or pointer address 
        //printf("%s\n", argv[i++]); // crash
        //printf("%c\n", argv[0]); // last char of exe name
    }
}
