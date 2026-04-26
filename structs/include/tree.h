#ifndef TREE_H
#define TREE_H

typedef int T;

typedef struct TreeNode {
    T value;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

// Heap

// typedef struct Heap {
//     TreeNode *root;
// }
typedef TreeNode *Heap;

Heap heap_init();

int heap_insert(Heap *heap, T value);
int heap_erase(Heap *heap, T value);
T heap_max(const Heap *heap);
void heap_print(const Heap *heap);

void heap_destroy(Heap heap);

// Binary search tree

typedef TreeNode *BSTree;

BSTree bst_init();

int bst_insert(BSTree *bst, T value);
int bst_erase(BSTree *bst, T value);
TreeNode *bst_find(const BSTree *bst, T value);
void bst_print(const BSTree *bst);

void bst_destroy(BSTree bst);

#endif

