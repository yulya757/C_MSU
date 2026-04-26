#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "list.h"

extern List list_init() {
    List list;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
extern int list_push_back(List *list, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    return 0;
}

extern int list_push_front(List *list, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = v->head;
    list->head = new_node;
    if (list->head == NULL) {
        list->tail = new_node;
    }
    list->size++;
    return 0;
}
extern int list_insert(List *list, Node *node, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = node->next;
    node->next = new_node;

    if (list->tail == node) {
        list->tail = new_node;
    }
    list->size++;
    return 0;  
}
extern int list_erase(List *list, Node *node) {
    Node *curr = list->head;
    Node *prev = NULL;
    while (curr != node) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    if (list->tail == curr) {
        list->tail = prev;
    }
    free(curr);
    list->size--;
    return 0;
}
extern int list_set(List *list, Node *node, int elem) {
    node->value = elem;
    return 0;
}
extern int list_get(List *list, int pos) {
    if (pos < 0 || (size_t)pos >= list->size) {
        return EINVAL; 
    }
    Node *curr = list->head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    return curr->value;
}
extern Node *list_find(List *list, int elem) {
    Node *curr = list->head;
    while (curr){
        if (curr->value == elem) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
extern void list_destroy(List *list) {
    Node *curr = list->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return 0;
}

//L2List

extern L2List l2_init() {
    List l2;
    l2->head = NULL;
    l2->tail = NULL;
    l2->size = 0;
    return l2;
}
extern int l2_push_back(L2List *l2, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = NULL;
    if (l2->head == NULL) {
        l2->head = new_node;
        l2->tail = new_node;
        new_node->prev = NULL;
    } else {
        l2->tail->next = new_node;
        new_node->prev = l2->tail;
        l2->tail = new_node;
    }
    l2->size++;
    return 0;
}
extern int l2_push_front(L2List *l2, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = v->head;
    new_node->prev = NULL;
    l2->head = new_node;
    if (l2->head == NULL) {
        l2->tail = new_node;
    }
    l2->size++;
    return 0;
}
extern int l2_insert(L2List *l2, L2Node *node, int elem) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return ENOMEM;
    }
    new_node->value = elem;
    new_node->next = node->next;
    new_node->prev = node;
    node->next = new_node;

    if (l2->tail == node) {
        l2->tail = new_node;
    }
    l2->size++;
    return 0;  
}
extern int l2_erase(L2List *l2, L2Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    list->size--;
    return 0;
}
extern int l2_set(L2List *l2, L2Node *node, int elem) {
    node->value = elem;
    return 0;
}
extern int l2_get(L2List *l2, int pos) {
    if (pos < 0 || (size_t)pos >= l2->size) {
        return EINVAL; 
    }
    Node *curr = l2->head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    return curr->value;
}
extern L2Node *l2_find(L2List *l2, int elem) {
    Node *curr = l2->head;
    while (curr){
        if (curr->value == elem) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
extern void l2_destroy(L2List *l2) {
    Node *curr = l2->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    l2->head = NULL;
    l2->tail = NULL;
    l2->size = 0;
    return 0;
}
