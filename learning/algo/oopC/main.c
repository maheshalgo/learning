#include "information_hiding.h"

int
main(int argc, char *argv[])
{
    int i;
    void  *val;
    StackT  *stack1;

    //allocate a stack
    stack1 = stack_init(10);

    for (i = 10; i > 0; i--) {
        stack_push(stack1, (void*)i);
    }
    for (i = 10; i > 0; i--) {
        val = stack_pop(stack1);
        printf("%d  ", (int)val);
    }
    printf("\n");
    stack_free(stack1);

}
