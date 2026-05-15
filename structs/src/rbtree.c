#include <stdlib.h>
#include <errno.h>

#include "rbtree.h"

static void
left_rotate(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *tree = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

static void
right_rotate(RBTree *tree, RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *tree = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

static void insert_fixup(RBTree *tree, RBNode *s) {
    while (s->parent && s->parent->color == RED) {
        RBNode *p = s->parent;
        RBNode *g = p->parent;

        if (p == g->left) {
            RBNode *u = g->right;
            // uncle red
            if (color(u) == RED) {
                p->color = BLACK;
                u->color = BLACK;
                g->color = RED;
                s = g;
            } else {
                // LR
                if (s == p->right) {
                    s = p;
                    left_rotate(tree, s);
                    p = s->parent;
                    g = p->parent;
                }
                // LL
                p->color = BLACK;
                g->color = RED;
                right_rotate(tree, g);
            }
        } else {
            RBNode *u = g->left;
            // uncle red mirror
            if (color(u) == RED) {
                p->color = BLACK;
                u->color = BLACK;
                g->color = RED;
                s = g;
            } else {
                // RL
                if (s == p->left) {
                    s = p;
                    right_rotate(tree, s);
                    p = s->parent;
                    g = p->parent;
                }
                // RR
                p->color = BLACK;
                g->color = RED;

                left_rotate(tree, g);
            }
        }
    }
    (*tree)->color = BLACK;
}

static RBNode *tree_min(RBNode *n) {
    while (n->left){
        n = n->left;
    }
    return n;
}

static void transplant(RBTree *tree, RBNode *u, RBNode *v) {
    if (!u->parent) {
        *tree = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v) v->parent = u->parent;
}

static void delete_fixup(RBTree *tree, RBNode *s, RBNode *p) {
    while (s != *tree && color(s) == BLACK) {
        if (s == p->left) {
            RBNode *u = p->right;
            // sibling red
            if (color(u) == RED) {
                u->color = BLACK;
                p->color = RED;
                left_rotate(tree, p);
                u = p->right;
            }

            // sibling black + both black children
            if (color(u->left) == BLACK &&
                color(u->right) == BLACK) {
                u->color = RED;
                s = p;
                p = s->parent;
            } else {
                // near child red
                if (color(u->right) == BLACK) {
                    if (u->left) {
                        u->left->color = BLACK;
                    }
                    u->color = RED;
                    right_rotate(tree, u);
                    u = p->right;
                }

                // far child red
                u->color = p->color;
                p->color = BLACK;
                if (u->right) {
                    u->right->color = BLACK;
                }
                left_rotate(tree, p);
                s = *tree;
            }
        } else {
            RBNode *u = p->left;

            // sibling red mirror
            if (color(u) == RED) {
                u->color = BLACK;
                p->color = RED;
                right_rotate(tree, p);
                u = p->left;
            }

            // sibling black + both black children mirror
            if (color(u->left) == BLACK &&
                color(u->right) == BLACK) {
                u->color = RED;
                s = p;
                p = s->parent;
            } else {
                // near child red mirror
                if (color(u->left) == BLACK) {
                    if (u->right) {
                        u->right->color = BLACK;
                    }
                    u->color = RED;
                    left_rotate(tree, u);
                    u = p->left;
                }

                // far child red mirror
                u->color = p->color;
                p->color = BLACK;
                if (u->left) {
                    u->left->color = BLACK;
                }
                right_rotate(tree, p);
                s = *tree;
            }
        }
    }
    if (s) s->color = BLACK;
}

RBTree rb_init() {
    return NULL;
}

RBNode *rb_find(const RBTree *tree, T value) {
    RBNode *cur = *tree;
    while (cur) {
        if (value == cur->value) {
            return cur;
        }
        if (value < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return NULL;
}

int rb_insert(RBTree *tree, T value) {
    RBNode *p = NULL;
    RBNode *cur = *tree;

    while (cur) {
        p = cur;
        if (value == cur->value) {
            return EINVAL;
        }
        if (value < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    RBNode *s = malloc(sizeof(RBNode));
    if (!s) {
        return ENOMEM;
    }
    s->value = value;
    s->left = NULL;
    s->right = NULL;
    s->parent = p;
    s->color = RED;

    if (!p) {
        *tree = s;
    } else if (value < p->value) {
        p->left = s;
    } else {
        p->right = s;
    }
    insert_fixup(tree, s);

    return 0;
}

int rb_erase(RBTree *tree, T value) {
    RBNode *d = rb_find(tree, value);
    if (!d) {
        return EINVAL;
    }

    RBNode *y = d;
    RBColor y_original = y->color;
    RBNode *s = NULL;
    RBNode *p = NULL;

    if (!d->left) {
        s = d->right;
        p = d->parent;
        transplant(tree, d, d->right);
    } else if (!d->right) {
        s = d->left;
        p = d->parent;
        transplant(tree, d, d->left);
    } else {
        y = tree_min(d->right);
        y_original = y->color;
        s = y->right;
        if (y->parent == d) {
            p = y;
            if (s) {
                s->parent = y;
            }
        } else {
            p = y->parent;
            transplant(tree, y, y->right);
            y->right = d->right;
            y->right->parent = y;
        }
        transplant(tree, d, y);

        y->left = d->left;
        y->left->parent = y;
        y->color = d->color;
    }
    free(d);
    if (y_original == BLACK) {
        delete_fixup(tree, s, p);
    }
    return 0;
}

void rb_print(const RBTree tree) {
    if (!tree) {
        return;
    }
    print(tree->value);
    rb_print(tree->left);
    rb_print(tree->right);
}

void rb_destroy(RBTree tree) {
    if (!tree)
        return;

    rb_destroy(tree->left);
    rb_destroy(tree->right);

    free(tree);
}