#ifndef UTILS_H
#define UTILS_H

/**
 * \typedef T
 * \brief Type of elements stored in the our structs
 *
 * Currently defined as int, but can be changed to another type if needed.
 */
typedef int T;

/**
 * \def PRN_T
 * \brief Format string for printing elements of type `T` using printf
 *
 * Used in printing functions to specify how to format the output of structs elements.
 * For `T` = int, it is set to "%d".
 */
#define PRN_T "%d"

#endif
