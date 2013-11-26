#include <stdio.h>

typedef struct _stackT StackT;

StackT* stack_init(unsigned int size);

void stack_free(StackT *st);

int stack_push(StackT* st, const void* elem);

void* stack_pop(StackT* st);


