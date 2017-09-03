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
    // usamos este puntero a funcion para liberar la memoria.
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
    if (*n == NULL)
    {
        *n = (node*) malloc(sizeof(node));
        (*n)->left = NULL;
        (*n)->right = NULL;
        (*n)->data = p;

        return 1;
    }
    
    int r = tree->cmp((*n)->data, p);
    
    if (r == 0)
        return 0;
        
    if (r > 0)
        return bst_add_r(tree, &((*n)->left), p);
        
    return bst_add_r(tree, &((*n)->right), p);
}

int bst_add(bst* tree, void* p)
{
    return bst_add_r(tree, &(tree->root), p);
}

void print_int(void* x, const void* p)
{
    printf("%d\n", *((int*)p));
}

void bst_iterate_r(node* n, void* tag, void(*f)(void*, const void*))
{
    if (n == NULL)
        return;

    bst_iterate_r(n->left, tag, f);
    f(tag, n->data);
    bst_iterate_r(n->right, tag, f);
}

void bst_iterate(bst* tree, void* tag, void(*f)(void*, const void*))
{
    bst_iterate_r(tree->root, tag, f);
}

void acum(void* tag, const void* p)
{
    int* s = (int*) tag;
    int n = *((int*) p);

    *s += n;
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

    // printf("%p\n", tree.root);
    printf("%d\n", *(int*) tree.root->data);
    
    // Para que pasar el argumento null?
    bst_iterate(&tree, NULL, print_int);

    int s = 0;
    bst_iterate(&tree, &s, acum);
    printf("suma: %d\n", s);
}
