#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_node
{
    void* data;
    struct bst_node* left;
    struct bst_node* right;
} node;

typedef struct
{
    node* root;
    int (*cmp) (const void*, const void*);
    void (*f) (void*);
} bst;

int cmp_int(const void* a, const void* b)
{
    int x = *((int*) a);
    int y = *((int*) b);

    return x - y;
}

void bst_init(bst* x, int (*cmp)(const void*, const void*), void (*f)(void*))
{
    x->root = NULL;
    x->cmp = cmp;
    x->f = f;
}

int* get_int(int n)
{
    int* r = (int*) malloc(sizeof(n));
    *r = n;
    return r;
}

int bst_add_r(bst* tree, node** n, void* p)
{
    if (*n == NULL) {
        *n = (node*) malloc(sizeof(node));
        (*n)->data = p;
        (*n)->left = NULL;
        (*n)->right = NULL;
        return 1;
    }
    return 0;
}

int bst_add(bst* tree, void* p)
{
    return bst_add_r(tree, &(tree->root), p);
}

int main()
{
    bst tree;
    bst_init(&tree, cmp_int, free);

    bst_add(&tree, get_int(25));
    bst_add(&tree, get_int(30));
    bst_add(&tree, get_int(22));
    bst_add(&tree, get_int(40));
    bst_add(&tree, get_int(17));

    printf("%p\n", tree.root);
    printf("%d\n", *(int*) tree.root->data);
}