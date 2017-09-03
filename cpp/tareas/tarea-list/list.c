#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char* data;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

typedef struct
{
    Node* head;
    Node* last;
} List;

void sll_init(List* list)
{
    list->head = NULL;
    list->last = NULL;
}

Node* node_create(const char* s)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    size_t len = strlen(s);
    char* str = (char*) malloc(len + 1);
    memcpy(str, s, len + 1);

    newNode->data = str;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Agregar al principio
void sll_add_head(List* list, char* s)
{
    Node* newNode = node_create(s);
    Node* head = list->head;

    if (head == NULL)
    {
        list->head = newNode;
        list->last = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head; 
        list->head = newNode;
    }
}

// Agregar al final
void sll_add(List* list, char* s)
{
    Node* newNode = node_create(s);
    Node* current = list->head;

    if (current == NULL)
    {
        list->head = newNode;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        list->last = newNode;
    }
}

void sll_print(List* list)
{
    Node* current = list->head;
    while (current != NULL)
    {
        puts(current->data);
        current = current->next;
    }
}

// imprimir del final al principio
void sll_print_back(List* list)
{
    Node* current = list->last;
    while (current != NULL)
    {
        puts(current->data);
        current = current->prev;
    }
}

void sll_release(List* list)
{
    Node* head = list->head;
    Node* next;

    if (head != NULL)
    {
        next = head->next;
        free(head->data);
        head->data = NULL;
        free(head);
        head = NULL;
        head = next;
    }
}

int main()
{
    List list;
    sll_init(&list);
    // Agregar al principio
    sll_add_head(&list, "VIM");
    sll_add_head(&list, "Emacs");
    sll_add_head(&list, "Nano");
    
    // Agregar al final
    sll_add(&list, "Gedit");
    sll_add(&list, "Sublime Text");
    sll_add(&list, "Geany");

    sll_print(&list);

    sll_print_back(&list);
}