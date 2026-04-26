#include "tree.h"
#include <errno.h>

Heap heap_init() {
    return NULL;
}

int heap_insert(Heap *heap, T value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node == NULL) {
        return ENOMEM;
    }
    node->value = value;
    if (heap == NULL) {
        heap = node;
        heap->parent = NULL;
        heap->left = NULL;
        heap->right = NULL;
    }
    TreeNode *cur = heap;
    while (1) {
        if (cur->value >= node->value) {
            if (cur->right == NULL) {
                cur->right = node;
                break;
            } else if (cur->left == NULL) {
                cur->left = node;
                break;
            } else if (cur->left->value < cur->right->value) {
                if (cur->left->value < node->value) {
                    node->parent = cur;
                    node->left = cur->left;
                    node->right = NULL;
                    cur->left->parent = node;
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right->value < node->value) {
                    node->parent = cur;
                    node->left = cur->right;
                    node->right = NULL;
                    cur->right->parent = node;
                    break;
                } else {
                    cur = cur->right;
                }
            } 
        } else {
            node->parent = cur->parent;
            node->left = cur;
            node->right = NULL;
            cur->parent = node;
        }
    }
    return 0;
}

int heap_erase(Heap *heap, T value) {
    if (heap == NULL) {
        return 0;
    }
    if (heap->value == value) {
        heap->left->parent = heap->right;
        heap->right
    }
    if (heap->left == -1 && heap->right == -1) {
        return -1;
    }
    if (heap->left->)
    if (heap_erase(heap->left) == 0 && heap_erase(heap->right) == 0) {
        return -1;
    }
    TreeNode *cur = heap;
    
}
T heap_max(const Heap *heap) {
    return heap->value;
}
void heap_print(const Heap *heap) {
    if (heap == NULL) {
        return;
    }
    print(heap->value);
    heap_print(heap->left);
    heap_print(heap->right);
    return;
}

void heap_destroy(Heap heap) {
    while (heap != NULL) {
        heap_destoy(heap->left);
        Heap next = heap->right;
        free(heap);
        heap=next;
    }
}

// Binary search tree

BSTree bst_init() {
    return NULL;
}

int bst_insert(BSTree *bst, T value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (node == NULL) {
        return ENOMEM;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if (bst == NULL){
        bst = node;
        bst->parent = NULL;
    }
    TreeNode cur = bst;
    while (cur != NULL){
        if (cur->value < value) {
            node->parent = cur;
            cur = cur->left;
        } else {
            node->parent = cur;
            cur = cur->right;
        }
    }
    cur = node;
}
int bst_erase(BSTree *bst, T value) {
    TreeNode cur = bst;
    while (cur != NULL) {
        if (cur->value < value) {
            cur = cur->left;
        } else if (cur->value > value) {
            cur = cur->right;
        } else {
            cur->parent->left = cur->left;
            cur->parent->right = cur->right;
            cur->left->parent = cur->parent;
            cur->right->parent = cur->parent;
            free(cur);
            return 0;
        }
    }
    return -1;
}
TreeNode *bst_find(const BSTree *bst, T value) {
    TreeNode cur = bst;
    while (cur != NULL) {
        if (cur->value < value) {
            cur = cur->left;
        } else if (cur->value > value) {
            cur = cur->right;
        } else {
            return cur;
        }
    }
    return -1;
}
void bst_print(const BSTree *bst) {
    if (heap == NULL) {
        return;
    }
    print(heap->value);
    heap_print(heap->left);
    heap_print(heap->right);
    return;
}

void bst_destroy(BSTree bst) {
    while (bst != NULL) {
        bst_destoy(bst->left);
        BSTree next = heap->right;
        free(bst);
        bst=next;
    }
}

