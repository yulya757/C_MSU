/**
 * \file stack.h
 * \brief Header file for stack data structure
 *
 * This header provides an interface for a stack data structure implemented
 * using a deque (`Deque`). The stack follows the LIFO (Last-In-First-Out)
 * principle: elements are added and removed from the top.
 */

#ifndef STACK_H
#define STACK_H

#include "deque.h"
#include "utils.h"

/**
 * \typedef Stack
 * \brief Stack type based on a deque
 *
 * In this implementation, `Stack` is a typedef for `Deque`. All stack operations
 * are internally mapped to corresponding deque operations, ensuring efficient
 * LIFO behavior.
 */
typedef Deque Stack;

/**
 * \brief Initialize a new stack
 *
 * Allocates necessary resources and sets up the stack for use.
 * The function internally calls `deque_init()` to create the underlying deque.
 *
 * \return A newly created and initialized stack.
 *         Returns NULL if memory allocation fails.
 */
Stack stack_init();

/**
 * \brief Push an element onto the top of the stack
 *
 * Adds the given value to the top of the stack (LIFO order).
 *
 * \param stack Pointer to the stack where the element will be added
 * \param val Value to be pushed onto the stack
 *
 * \return 0 on success,
 *         ENOMEM if memory allocation fails,
 *         EINVAL if `stack` is NULL
 */
int stack_push(Stack *stack, T val);

/**
 * \brief Pop an element from the top of the stack
 *
 * Retrieves and removes the top element from the stack (LIFO order).
 * The caller must ensure the stack is not empty before calling this function.
 *
 * \param stack Pointer to the stack from which the element will be removed
 *
 * \return Value of the removed top element.
 *         If `stack` is NULL, behavior is undefined (caller must ensure validity).
 */
T stack_pop(Stack *stack);

/**
 * \brief Destroy the stack and free all associated resources
 *
 * Releases all memory used by the stack, including the underlying deque structure.
 * If `stack` is NULL, the function does nothing (safe to call with NULL).
 *
 * \param stack Pointer to the stack to be destroyed
 */
void stack_destroy(Stack *stack);

#endif // STACK_H

