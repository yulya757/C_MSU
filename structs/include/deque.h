/**
 * \file deque.h
 * \brief Header file for deque (double-ended queue) structure
 *
 * This header provides an interface for a deque data structure that can be
 * implemented either via a vector (when `DEQUE_VECTOR` is defined) or via a
 * double linked list (otherwise). The deque allows efficient insertion and removal
 * of elements at both ends.
 */

#ifndef DEQUE_H
#define DEQUE_H

/**
 * \typedef T
 * \brief Type of elements stored in the deque
 *
 * Currently defined as int, but can be changed to another type if needed.
 */
typedef int T;

/**
 * \def PRN_T
 * \brief Format string for printing elements of type `T` using printf
 *
 * Used in printing functions to specify how to format the output of deque elements.
 * For `T` = int, it is set to "%d".
 */
#define PRN_T "%d"

#ifdef DEQUE_VECTOR
/**
 * \include vector.h
 * \brief Include vector implementation header when `DEQUE_VECTOR` is defined
 *
 * When `DEQUE_VECTOR` macro is defined, the deque is implemented using a dynamic
 * array (vector) with an offset index (`start`) to allow efficient operations
 * at both ends.
 */
#include "vector.h"

/**
 * \struct Deque
 * \brief Deque structure based on a vector
 *
 * Consists of a vector and a start index that tracks the logical beginning
 * of the deque within the underlying vector.
 */
typedef struct {
    Vector v;      ///< Underlying vector holding the data
    int start;     ///< Index of the first element in the vector
} Deque;

#else
/**
 * \include list.h
 * \brief Include list implementation header when `DEQUE_VECTOR` is not defined
 *
 * If `DEQUE_VECTOR` is not defined, the deque uses a double linked list
 * (`L2List`) as its underlying structure.
 */
#include "list.h"

/**
 * \typedef Deque
 * \brief Deque type based on a double linked list
 *
 * In this implementation, `Deque` is a typedef for `L2List` — a standard double
 * linked list that naturally supports insertion and deletion at both ends.
 */
typedef L2List Deque;
#endif

/**
 * \brief Initialize a new deque
 *
 * Allocates necessary resources and sets up the deque for use.
 * The behavior depends on the underlying implementation:
 * - With `DEQUE_VECTOR`: initializes the vector and sets `start` = 0.
 * - Without `DEQUE_VECTOR`: initializes the double linked list.
 *
 * \return A newly created and initialized deque.
 *         Returns NULL if memory allocation fails.
 */
Deque deque_init();

/**
 * \brief Add an element to the front of the deque
 *
 * Inserts the given value at the beginning of the deque.
 *
 * \param deque Pointer to the deque where the element will be added
 * \param val Value to be inserted at the front
 *
 * \return 0 on success,
 *         ENOMEM if memory allocation fails,
 *         EINVAL if `deque` is NULL
 */
int deque_push_front(Deque *deque, T val);

/**
 * \brief Add an element to the back of the deque
 *
 * Appends the given value to the end of the deque.
 *
 * \param deque Pointer to the deque where the element will be added
 * \param val Value to be inserted at the back
 *
 * \return 0 on success,
 *         ENOMEM if memory allocation fails,
 *         EINVAL if `deque` is NULL
 */
int deque_push_back(Deque *deque, T val);

/**
 * \brief Remove and return the front element of the deque
 *
 * Retrieves the first element and removes it from the deque.
 * The caller must ensure the deque is not empty before calling this function.
 *
 * \param deque Pointer to the deque from which the element will be removed
 * \return Value of the removed front element.
 *         If `deque` is NULL, behavior is undefined (caller must ensure validity).
 */
T deque_pop_front(Deque *deque);

/**
 * \brief Remove and return the back element of the deque
 *
 * Retrieves the last element and removes it from the deque.
 * The caller must ensure the deque is not empty before calling this function.
 *
 * \param deque Pointer to the deque from which the element will be removed
 * \return Value of the removed back element.
 *         If `deque` is NULL, behavior is undefined (caller must ensure validity).
 */
T deque_pop_back(Deque *deque);

/**
 * \brief Destroy the deque and free all associated resources
 *
 * Releases all memory used by the deque, including the underlying data structure
 * (`vector` or `list`). If `deque` is NULL, the function does nothing.
 *
 * \param deque Pointer to the deque to be destroyed
 */
void deque_destroy(Deque *deque);

#endif // DEQUE_H

