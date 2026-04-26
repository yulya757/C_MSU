#include "queue.h"

Queue queue_init() {
    Queue queue = deque_init();
    return queue;
}
int queue_push(Queue *queue, T val) {
    return deque_push_back(&queue, val);
}
T queue_pop(Queue *queue) {
    return deque_pop_front(&queue);
}
void queue_destroy(Queue *queue) {
    deque_destroy(&queue);
}
