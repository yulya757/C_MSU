#include <stdlib.h>
#include <errno.h>
#include "avl.h"


static unsigned char height(AVLNode *n) {
    return n ? n->h : 0;
}

static void fix_height(AVLNode *n) {
    unsigned char hl = height(n->left);
    unsigned char hr = height(n->right);
    n->h = (hl > hr ? hl : hr) + 1;
}

static AVLNode *
small_left_rotate(AVLNode *x) {
    AVLNode *y = x->right;

    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->left = x;

    y->parent = x->parent;
    x->parent = y;

    fix_height(x);
    fix_height(y);

    return y;
}

static AVLNode *
small_right_rotate(AVLNode *y) {
    AVLNode *x = y->left;

    y->left = x->right;
    if (x->right)
        x->right->parent = y;

    x->right = y;

    x->parent = y->parent;
    y->parent = x;

    fix_height(y);
    fix_height(x);

    return x;
}

static AVLNode *
big_left_rotate(AVLNode *x) {
    x->right = small_right_rotate(x->right);
    if (x->right)
        x->right->parent = x;

    return small_left_rotate(x);
}

static AVLNode *
big_right_rotate(AVLNode *y) {
    y->left = small_left_rotate(y->left);
    if (y->left)
        y->left->parent = y;

    return small_right_rotate(y);
}

AVLTree avl_init() {
    return NULL;
}

int
avl_insert(AVLTree *avl, T value) {
    AVLNode *parent = NULL;
    AVLNode *cur = *avl;

    // Find place to insert
    while (cur != NULL) {
        parent = cur;
        if (value == cur->value) {
            return EINVAL; 
        } else if (value < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    // create node
    AVLNode *node = malloc(sizeof(AVLNode));
    if (!node) return ENOMEM;

    node->value = value;
    node->left = node->right = NULL;
    node->parent = parent;
    node->h = 1;

    // insert
    if (parent == NULL) {
        *avl = node;
        return 0;
    }

    if (value < parent->value)
        parent->left = node;
    else
        parent->right = node;

    // balance
    cur = parent;
    while (cur != NULL) {
        fix_height(cur);

        int balance = height(cur->right) - height(cur->left);

        if (balance == 2) {
            if (height(cur->right->right) >= height(cur->right->left)) {
                AVLNode *new_root = small_left_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;

            } else {
                AVLNode *new_root = big_left_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;
            }
        }
        else if (balance == -2) {
            if (height(cur->left->left) >= height(cur->left->right)) {
                AVLNode *new_root = small_right_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;

            } else {
                AVLNode *new_root = big_right_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;
            }
        }

        cur = cur->parent;
    }

    return 0;
}

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
        T tmp = cur->value;
        cur->value = to_delete->value;
        to_delete->value = tmp;
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
    while (cur != NULL) {
        fix_height(cur);

        int balance = height(cur->right) - height(cur->left);
        if (balance == 2) { // Right taller than left
            if (height(cur->right->right) >= height(cur->right->left)) {
                AVLNode *new_root = small_left_rotate(cur);
            
                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;

            } else {
                AVLNode *new_root = big_left_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;
            }
        }
        else if (balance == -2) { // Left taller than right
            if (height(cur->left->left) >= height(cur->left->right)) {
                AVLNode *new_root = small_right_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;

            } else {
                AVLNode *new_root = big_right_rotate(cur);

                if (new_root->parent == NULL)
                    *avl = new_root;
                else if (new_root->parent->left == cur)
                    new_root->parent->left = new_root;
                else
                    new_root->parent->right = new_root;
            }
        }
        cur = cur->parent;
    }
    return 0;
}

AVLNode *avl_find(const AVLTree *avl, T value) {
    AVLNode *cur = *avl;

    while (cur != NULL) {
        if (value == cur->value) {
            return cur;
        } else if (value < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    return NULL;
}

void avl_print(const AVLTree avl) {
    if (avl == NULL) {
        return;
    }
    print(avl->value);
    heap_print(avl->left);
    heap_print(avl->right);
    return;

}

void avl_destroy(AVLTree avl) {
    while (avl != NULL) {
        avl_destoy(avl->left);
        AVLTree next = avl->right;
        free(avl);
        avl=next;
    }    
}
