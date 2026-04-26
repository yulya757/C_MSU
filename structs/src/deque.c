#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "deque.h"

#ifdef DEQUE_VECTOR

Deque deque_init() {
    Deque deque;
    deque->v = vector_init(0);
    deque->start = 0;
    return deque;
}

int deque_push_front(Deque *deque, T val) {
    if (deque->start == 0) {
        size_t new_capacity = deque->v->capacity * 3;
        vector_resize(&deque->v, new_capacity);
        deque->start = (new_capacity - deque->v->size) / 2;
        for (int i = 0; i < deque->v->size; i++) {
            vector_set(&deque->v, deque->start + i, vector_get(&deque->v, i));
        }
    }
    deque.start--;
    return vector_set(&deque->v, 0, val);
}

int deque_push_back(Deque *deque,T val) {
    return vector_push_back(&deque->v, val);
}

T deque_pop_front(Deque *deque) {
    deque->start++;
    return vector_get(&deque->v, deque->start - 1);
}

T deque_pop_back(Deque *deque) {
    int val = vector_get(&deque->v, deque->start + deque->v->size - 1);
    vector_erase(&deque->v, deque->start + deque->v->size - 1);
    return val;
}

void deque_destroy(Deque *deque) {
    vector_destroy(&deque->v);
    deque->start = 0;
}
#else
#endif

Deque deque_init() {
    Deque deque = l2_init();
    return deque;
}
int deque_push_front(Deque *deque, T val) {
    return l2_push_front(&deque, val);
}
int deque_push_back(Deque *deque,T val) {
    return l2_push_back(&deque, val);
}
T deque_pop_front(Deque *deque) {
    int val = l2_get(&deque, 0);
    l2_erase(&deque, &deque->head);
    return val;
}
T deque_pop_back(Deque *deque) {
    int val = l2_get(&deque, deque->size - 1);
    l2_erase(&deque, &deque->head);
    return val;
}
void deque_destroy(Deque *deque) {
    l2_destroy(&deque);
}
