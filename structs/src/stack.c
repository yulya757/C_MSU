#include "stack.h"

Stack stack_init() {
    Stack stack = deque_init();
    return stack;
}
int stack_push(Stack *stack, T val) {
    return deque_push_back(&stack, val);
}
T stack_pop(Stack *stack) {
    return deque_pop_back(&stack);
}
void stack_destroy(Stack *stack){
    deque_destroy(&stack);
}
