#include <stdio.h>
#include <errno.h>

typedef struct _node {
    void    *elem;
} nodet;

typedef struct __stackt {
    //nodet     *head_node[];
    int        top;
    unsigned int     size;
    nodet     *head_node;
    nodet     *stack_base;
} _stackT;

_stackT* 
stack_init(unsigned int size)
{
    _stackT    *newstack = NULL;
    nodet      *elem_list = NULL;

    newstack = malloc(sizeof(_stackT));
    elem_list = malloc(size * sizeof(nodet));
    if (!newstack || !elem_list) {
        if (newstack) free(newstack);
        if (elem_list) free(elem_list);
        errno = ENOMEM;
        return (NULL);
    }
    newstack->head_node = elem_list;
    newstack->stack_base = elem_list;
    newstack->top = -1;
    newstack->size = size;
    return (newstack);
}

void 
stack_free(_stackT *st)
{
    if (st->stack_base) free(st->stack_base);
    if (st) free (st);
}

int 
stack_push(_stackT* st, const void* elem)
{
    if (st->top == st->size) {
        // stack full
        return (ENOMEM);
    }
    st->head_node->elem = elem;
    st->top++; 
    st->head_node = st->stack_base + st->top;
    return (0);
}

void* 
stack_pop(_stackT* st)
{
    void            *elem = NULL;
    if (st->top == -1) {
        return (elem);
    }
    elem = st->head_node->elem;
    st->top--;
    st->head_node = st->stack_base + st->top;
    return (elem);
}


