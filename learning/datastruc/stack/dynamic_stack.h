
typedef struct _stackT stackT;

stackT* stack_create(int size);

int stack_push(stackT* this_stack, void *elem);

void* stack_pop(stackT* this_stack);

