#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

Vector vector_init(size_t capacity) {
    Vector v;
    v.data = (T*)calloc(capacity, sizeof(T));
    v.size = 0;
    v.capacity = capacity;
    return v;
}

T vector_get(const Vector *v, const int index) {
    int index1 = index;
    if (abs(index1) > v->size) {
        printf("EINVAL");
        exit(1);
    }
    if (index < 0) {
        index1 = v->size + index;
    } else {
        index1 = index;
    }
    return v->data[index1];
}

T vector_set(Vector *v, const int index, const T value) {
    int index1 = index;
    if (abs(index1) > v->size) {
        printf("EINVAL");
        exit(1);
    }
    if (index < 0) {
        index1 = v->size + index;
    } else {
        index1 = index;
    }
    v->data[index1] = value;
    return value;
}

int vector_insert(Vector *v, const int index, const T value) {
    int index1 = index;
    if (abs(index1) > v->size) {
        return EINVAL;
    }
    if (v->size + 1 > v->capacity) {
        size_t new_capacity = v->capacity * 2;
        if (new_capacity == 0) {
            new_capacity = 1;
        }
        T *new_data = realloc(v->data, new_capacity * sizeof(T));
        if (new_data == NULL) {
            return ENOMEM;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    if (index < 0) {
        index1 = v->size + index;
    } else {
        index1 = index;
    }
    for (int i = v->size; i > index1; i--) {
        v->data[i] = v->data[i-1];
    }
    v->data[index1] = value;
    v->size = v->size + 1;
    return 0;
}

int vector_erase(Vector *v, const int index) {
    int index1 = index;
    if (abs(index1) > v->size) {
        return EINVAL;
    }
    if (index < 0) {
        index1 = v->size + index;
    } else {
        index1 = index;
    }
    for (int i = index1; i < v->size - 1; i++) {
        v->data[i] = v->data[i+1];
    }
    v->size = v->size - 1;
    return 0;
}

int vector_push_back(Vector *v, const T value) {
    if (v->size + 1 > v->capacity) {
        size_t new_capacity = v->capacity * 2;
        if (new_capacity == 0) {
            new_capacity = 1;
        }
        T *new_data = realloc(v->data, new_capacity * sizeof(T));
        if (new_data == NULL) {
            return ENOMEM;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size] = value;    
    v->size = v->size + 1;
    return 0;
}

// *vector_pop_back

int vector_resize(Vector *v, size_t capacity) {
    if (capacity == 0) {
        if (v->size == 0){
            free(v->data);
            v->data = (T*)malloc(sizeof(T));
            if (v->data == NULL) {
                errno = ENOMEM;
                return ENOMEM;
            }
            v->capacity = 1;
            return 0;
        } else {
            T* new_data = (T*)malloc(v->size * sizeof(T));
            if (new_data == NULL) {
                errno = ENOMEM;
                return ENOMEM;
            }
            for (size_t i = 0; i < v->size; i++) {
                new_data[i] = v->data[i];
            }
            free(v->data);
            v->data = new_data;
            v->capacity = v->size;
            return 0;
        }
    }
    
    if (capacity == v->capacity) {
        return 0;
    } else {
        T* new_data = (T*)malloc(capacity * sizeof(T));
        if (!new_data) {
            errno = ENOMEM;
            return ENOMEM;
        }

        size_t size_to_copy;
        if (v->size < capacity) {
            size_to_copy = v->size;
        } else {
            size_to_copy = capacity;
        }

        for (size_t i = 0; i < size_to_copy; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);

        v->data = new_data;
        v->capacity = capacity;
        v->size = size_to_copy;

        return 0;
    }
        if (capacity == v->capacity) {
            return 0;
        }

        T* new_data = (T*)malloc(capacity * sizeof(T));
        if (new_data == NULL) {
            errno = ENOMEM;
            return ENOMEM;
        }

        v->data = new_data;
        v->capacity = capacity;

        if (v->size > capacity) {
            v->size = capacity;
        }

        return 0;
}

void vector_print(const Vector *v) {
    if (v == NULL) {
        printf("NULL");
        exit(1);
    }
    for (int i = 0; i < v->size; i++) {
        printf(PRN_T " ", v->data[i]);
    }
}

void vector_destroy(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
