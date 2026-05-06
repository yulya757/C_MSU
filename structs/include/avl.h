#ifndef AVL_H
#define AVL_H

#include "utils.h"

typedef struct AVLNode {
    T value;
    struct AVLNode *left;
    struct AVLNode *right;
    struct AVLNode *parent; 
    unsigned char h;
} AVLNode;

typedef AVLNode *AVLTree;

AVLTree avl_init();

int avl_insert(AVLTree *avl, T value);
int avl_erase(AVLTree *avl, T value);
AVLNode *avl_find(const AVLTree *avl, T value);
void avl_print(const AVLTree *avl);

void avl_destroy(AVLTree avl);

#endif
