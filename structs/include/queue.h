/**
 * \file queue.h
 * \brief Header file for queue data structure
 *
 * This header provides an interface for a queue data structure implemented
 * using a deque (`Deque`). The queue follows the FIFO (First-In-First-Out)
 * principle: elements are added to the back and removed from the front.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "deque.h"
#include "utils.h"

/**
 * \typedef Queue
 * \brief Queue type based on a deque
 *
 * In this implementation, `Queue` is a typedef for `Deque`. All queue operations
 * are internally mapped to corresponding deque operations, ensuring efficient
 * FIFO behavior.
 */
typedef Deque Queue;

/**
 * \brief Initialize a new queue
 *
 * Allocates necessary resources and sets up the queue for use.
 * The function internally calls `deque_init()` to create the underlying deque.
 *
 * \return A newly created and initialized queue.
 *         Returns NULL if memory allocation fails.
 */
Queue queue_init();

/**
 * \brief Add an element to the back of the queue
 *
 * Appends the given value to the end (back) of the queue (FIFO order).
 *
 * \param queue Pointer to the queue where the element will be added
 * \param val Value to be pushed into the queue
 *
 * \return 0 on success,
 *         ENOMEM if memory allocation fails,
 *         EINVAL if `queue` is NULL
 */
int queue_push(Queue *queue, T val);

/**
 * \brief Remove an element from the front of the queue
 *
 * Retrieves and removes the front element from the queue (FIFO order).
 * The caller must ensure the queue is not empty before calling this function.
 *
 * \param queue Pointer to the queue from which the element will be removed
 * \return Value of the removed front element.
 *         If `queue` is NULL, behavior is undefined (caller must ensure validity).
 */
T queue_pop(Queue *queue);

/**
 * \brief Destroy the queue and free all associated resources
 *
 * Releases all memory used by the queue, including the underlying deque structure.
 * If `queue` is NULL, the function does nothing (safe to call with NULL).
 *
 * \param queue Pointer to the queue to be destroyed
 */
void queue_destroy(Queue *queue);

#endif // QUEUE_H

