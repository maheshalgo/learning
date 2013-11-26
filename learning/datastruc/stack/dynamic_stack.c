#include <stdio.h>
#include "dynamic_stack.h"

typedef struct _nodet {
    void*          elem;
    struct _nodet *next;
} nodet;

typedef struct __stackT{
    unsigned int multi_block_sizes[100];
    nodet        *stack_bases[100];
    nodet        *stacktop;
    nodet        *head;
    unsigned int curr_stack_block;
    unsigned int curr_stack_block_head;
} _stackT; 

stackT* 
stack_create(unsigned int size)
{
    stackT       *new_stack;

    new_stack      = malloc(sizeof(_stackT));
    if (new_stack) {
        new_stack->stack_bases[0] = malloc(sizeof(nodet));
        new_stack->curr_stack_block = 0;
        new_stack->multi_block_sizes[0] = size;
    }
    if (!(new_stack->stack_bases[0])) {
        if (new_stack) {
            free(new_stack);
            new_stack = NULL;
        } 
    } else {
    }
    return (new_stack);
}

int 
stack_push(stackT* this_stack, void *elem)
{
    if (!this_stack || !elem) {
        return (EINVAL);
    }
    if (this_stack->stacktop == 
        (this_stack->stack_bases[this_stack->curr_stack_block] +
        this_stack->multi_block_size[this_stack->curr_stack_block])) {
        // current block of stack is fully. Allocate a new block of memory
        // twice the previous size of stack block
    } else {
        this_stack->stacktop->elem = elem;
        this_stack->stacktop = this_stack->stackbases[
    }
 
}

void* 
stack_pop(stackT* this_stack)
{
}

