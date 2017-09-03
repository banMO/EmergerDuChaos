#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
    int dataInt;
    char* dataString;
} Data;

typedef enum
{
    INT,
    STRING
} DataType;

struct node
{
    Data data;
    DataType type;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

typedef struct
{
    Node* first;
    Node* last;
} VariantQueue;

void init_queue(VariantQueue* queue)
{
    queue->first = NULL;
    queue->last = NULL;
}

Node* node_create_char(const char* s)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    size_t len = strlen(s);
    char* str = (char*) malloc(len + 1);
    memcpy(str, s, len + 1);

    newNode->data.dataString = str;
    newNode->type = STRING;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node* node_create_int(const int d)
{
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data.dataInt = d;
    newNode->type = INT;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void enqueue_string(VariantQueue* queue, char* s)
{
    Node* newNode = node_create_char(s);
    Node* first = queue->first;

    if (first == NULL)
    {
        queue->first = newNode;
        queue->last = newNode;
    }
    else
    {
        first->prev = newNode;
        newNode->next = first; 
        queue->first = newNode;
    }
}

void enqueue_int(VariantQueue* queue, int d)
{
    Node* newNode = node_create_int(d);
    Node* first = queue->first;

    if (first == NULL)
    {
        queue->first = newNode;
        queue->last = newNode;
    }
    else
    {
        first->prev = newNode;
        newNode->next = first; 
        queue->first = newNode;
    }
}

Node* dequeue(VariantQueue* queue) {
    Node* last = queue->last;

    last->prev->next = NULL;
    queue->last = last->prev;
    last->prev = NULL;

    return last;
}


void print(VariantQueue* queue)
{
    Node* current = queue->first;

    while (current != NULL)
    {
        if (current->type == STRING) {
            puts(current->data.dataString);
        } else {
            printf("%d\n", current->data.dataInt);
        }
        current = current->next;
    }
}

void release(VariantQueue* queue) {
    Node* first = queue->first;
    Node* aux;

    while (first != NULL)
    {
        if (first->type == STRING) {
            free(first->data.dataString);
            first->data.dataString = NULL;
        }

        aux = first->next;
        free(first);
        first = aux;
    }
    queue->first = NULL;
    queue->last = NULL;
}

int main()
{
    VariantQueue queue;
    init_queue(&queue);

    enqueue_string(&queue, "Ubuntu");
    enqueue_string(&queue, "OpenSuse");
    enqueue_int(&queue, 0);
    enqueue_string(&queue, "Debian");
    enqueue_int(&queue, 1);
    enqueue_string(&queue, "Fedora");
    enqueue_int(&queue, 1);
    enqueue_string(&queue, "Gentoo");
    enqueue_string(&queue, "CentOs");
    enqueue_int(&queue, 2);
    enqueue_int(&queue, 3);

    print(&queue);

    dequeue(&queue);

    printf("El ultimo es: %s\n", queue.last->data.dataString);

    puts("====== After Dequeuing =====");
    print(&queue);

    release(&queue);

    puts("====== After Releasing =====");
    print(&queue);
}