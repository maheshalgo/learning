
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int (*my_fptr)(int, int);
int (*my_fptr2)(int, int);

static int
my_func(int a, int b)
{
    printf ("%d\n", a+b);
    printf ("%d\n", 100);
}

int
main(int argc, char* argv[])
{
    int  opt = -1, ix = 0, iy = 0;
    my_fptr  add_func = NULL;

    while((opt = getopt(argc, argv, "x:y:")) != -1) {
        switch(opt) {
            case 'x':
                ix = strtol(optarg, NULL, 10);
            break;
            case 'y':
                iy = strtol(optarg, NULL, 10);
            break;
        }
    }
    printf("%d , %d\n", ix, iy);
    add_func = my_func;
    my_fptr2 = my_func;
    add_func(ix, iy);
    my_fptr2(ix, ix);
}
