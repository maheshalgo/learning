
#include <stdio.h>

int
main ()
{
    const char str1[] = "abcdef";
    char* const str2 = str1;

    printf("%s\n", str1);
    printf("%s\n", str2);

    str2[1] = 'z'; 

    printf("%s\n", str1);
    printf("%s\n", str2);
}
