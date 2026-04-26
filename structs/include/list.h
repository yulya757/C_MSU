#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    size_t size;
} List;

typedef struct L2Node {
    int value;
    struct L2Node *next;
    struct L2Node *prev;
} L2Node;

typedef struct L2List {
    L2Node *head;
    L2Node *tail;
    size_t size;
} L2List;

extern List list_init();
extern int list_push_back(List *list, int elem);
extern int list_push_front(List *list, int elem);
extern int list_insert(List *list, Node *node, int elem);
extern int list_erase(List *list, Node *node);
extern int list_set(List *list, Node *node, int elem);
extern int list_get(List *list, int pos);
extern Node *list_find(List *list, int elem);
extern void list_destroy(List *list);

extern L2List l2_init();
extern int l2_push_back(L2List *l2, int elem);
extern int l2_push_front(L2List *l2, int elem);
extern int l2_insert(L2List *l2, L2Node *node, int elem);
extern int l2_erase(L2List *l2, L2Node *node);
extern int l2_set(L2List *l2, L2Node *node, int elem);
extern int l2_get(L2List *l2, int pos);
extern L2Node *l2_find(L2List *l2, int elem);
extern void l2_destroy(L2List *l2);

#endif
