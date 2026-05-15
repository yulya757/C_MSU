#ifndef RBTREE_H
#define RBTREE_H

#include "utils.h"

typedef enum {
    RED,
    BLACK
} RBColor;

typedef struct RBNode {
    T value;

    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;

    RBColor color;
} RBNode;

typedef RBNode *RBTree;

RBTree rb_init();

int rb_insert(RBTree *tree, T value);
int rb_erase(RBTree *tree, T value);

RBNode *rb_find(const RBTree *tree, T value);

void rb_print(const RBTree tree);

void rb_destroy(RBTree tree);

#endif