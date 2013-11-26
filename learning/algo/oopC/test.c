#include <stdio.h>

int 
main()
{
    char **aptr , *str;
    int i = 0;

    aptr = malloc(20 * sizeof(char*));
    while (i < 30) {
        str = malloc(30);
        sprintf(str, "%s%d", "abc", i);
        aptr[i++] = str;
    }
    i = 0;
    while (i < 30) {
        printf("%s\n", aptr[i++]);
    }
   
}

