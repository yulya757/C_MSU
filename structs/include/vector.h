/**
 * \file
 * \brief Header file for dynamic array(vector) structure
 */


#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef int T;
#define PRN_T "%d"
// printf(PRN_T " ", v->data[i]);
// printf("%d" " ", v->data[i]);

typedef struct Vector {
    T *data;
    size_t size;
    size_t capacity;
} Vector;

/**
    \brief Vector initialization with first malloc
        of `data` array of size `size`
    \return Newly created vector
    \param size Size of first malloc'ed `data` array
 */
Vector vector_init(size_t size);

/**
    \brief Get element from vector by index
        if index is in bounds, fails otherwise
    \return Requested element value
    \param v Vector to be processed
    \param index Index of requested element.
        Must be in bounds(from `-size` to `size - 1`).
        Negative indexes means counting from back of array.
*/
T vector_get(const Vector *v, const int index);

/**
    \brief Set element in vector by index
        if index is in bounds, fails otherwise
    \return Newly set element value
    \param v Vector to be processed
    \param index Index of requested element.
        Must be in bounds(from `-size` to `size - 1`).
        Negative indexes means counting from back of array.
    \param value Value to be set
*/
T vector_set(Vector *v, const int index, const T value);

/**
    \brief Insert element in vector by index
        if index is in bounds, shifts elements to the right.
    \return 0 if no error, EINVAL if index out of bounds, ENOMEM if realloc fails
    \param v Vector to be processed
    \param index Index of element.
        Must be in bounds(from `-size to `size - 1`).
        Negative indexes means counting from back of array.
    \param value Value to be inserted
*/
int vector_insert(Vector *v, const int index, const T value);

/**
    \brief Erase element in vector by index
        if index is in bounds, shifts elements to the left.
    \return 0 if no error, EINVAL if index out of bounds
    \param v Vector to be processed
    \param index Index of element.
        Must be in bounds(from `-size` to `size - 1`).
        Negative indexes means counting from back of array.
*/
int vector_erase(Vector *v, const int index);

/**
    \brief Push back element in vector
    \return 0 if no error, ENOMEM if realloc fails
    \param v Vector to be processed
    \param value Value to be inserted
*/
int vector_push_back(Vector *v, const T value);
// *vector_pop_back

/**
    \brief Resize vector. The contents will be unchanged
        in the range from the start of the region up to
        the minimum of the old and new sizes. If `size` is zero,
        vector capacity shinks to fit vector size.
    \return 0 if no error, ENOMEM if realloc fails
    \param v Vector to be processed
    \param size New size
*/
int vector_resize(Vector *v, size_t size); // 0 means shrink to fit

/**
    \brief Print vector contentc space separated. If "v" is NULL? prints NULL
    \param v Vector to be printed
 */
void vector_print(const Vector *v);

/**
    \brief Deallocates `data` array
    \param v Vector to be destroyed
*/
void vector_destroy(Vector *v);

#endif
