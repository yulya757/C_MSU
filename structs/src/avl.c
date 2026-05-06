#include <stdlib.h>
#include <errno.h>
#include "avl.h"

AVLTree avl_init();

int avl_insert(AVLTree *avl, T value);

int
avl_erase(AVLTree *avl, T value) {
    AVLNode *to_delete = avl_find(avl, value);
    if (to_delete == NULL) {
        return EINVAL;
    }
    // Find actual node to delete
    AVLNode *cur;
    if (!(to_delete->left == NULL || to_delete->right == NULL)) {
        cur = to_delete->left;
        while (cur->right != NULL) {
            cur = cur->right;
        }
        cur->value ^= to_delete->value;
        to_delete->value ^= cur->value;
        cur->value ^= to_delete->value;
    } else {
        cur = to_delete;
    }

    if (cur->left != NULL) {
        cur->left->parent = cur->parent;
        if (cur->parent->left == cur) {
            cur->parent->left = cur->left;
        } else {
             cur->parent->right = cur->left;
        }
    }
    if (cur->right != NULL) {
        cur->right->parent = cur->parent;
        if (cur->parent->left == cur) {
            cur->parent->left = cur->right;
        } else {
            cur->parent->right = cur->right;
        }
    }
    if (cur->left == NULL && cur->right == NULL) {
        if (cur->parent->left == cur) {
            cur->parent->left = NULL;
        } else {
            cur->parent->right = NULL;
        }
    }
    
    AVLNode* tmp = cur->parent;
    free(cur);
    cur = tmp;
    while(cur != NULL) {
        unsigned char h_l = (cur->left != NULL ? cur->left->h : 0);
        unsigned char h_r = (cur->right != NULL ? cur->right->h : 0);
        // Right taller than left
        if (h_l + 2 == h_r) {
            unsigned char h_r_l = (cur->right->left != NULL ? cur->right->left->h : 0); 
            unsigned char h_r_r = (cur->right->right != NULL ? cur->right->right->h : 0); 
            if (h_r_r > h_r_l) {
                AVLNode *parent = cur->parent;
                AVLNode *tmp = small_left_rotate(cur);
                if (parent) {
                    if (parent->left == cur) {
                        parent->left = tmp;
                    } else {
                        parent->right = tmp;
                    }
                }
                cur = parent;
            } else {
                // big_left_rotate
            }
        } else if (h_r + 2 == h_l) { // Left taller than right
            // small_right_rotate
            // big_ight_rotate
        } else {
            if ((h_l > h_r ? h_l : h_r) + 1 == cur->h) {
                break;
            }
            cur->h = (h_l > h_r ? h_l : h_r) + 1;
            cur = cur->parent;
        }
    }
    return 0;
}

AVLNode *avl_find(const AVLTree *avl, T value);
void avl_print(const AVLTree *avl);

void avl_destroy(AVLTree avl);

static AVLNode *
small_left_rotate(AVLNode *root) {
    return root;
}

// small_right_rotate
// big_left_rotate
// big_right_rotate

