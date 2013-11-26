#include <stdio.h>

typedef struct _a {
    int  b;
    char c;
}a;

#pragma pack(push , 1)
typedef struct ___a_ {
    int  b;
    char c;
}___a;
#pragma pack(pop)

struct  __attribute__((__packed__)) {
    int b;
    char c;
}_z;

typedef struct  __attribute__((__packed__)) _z {
    int b;
    char c;
}z;


int
main ()
{
    z  __z;
    a  __a;
    ___a  _a_;
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(__z));
    printf("%d\n", sizeof(_z));
    printf("%d\n", sizeof(_a_));
}
