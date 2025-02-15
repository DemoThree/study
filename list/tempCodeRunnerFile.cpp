#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;

    /* data */
} Node;

Node *init()
{
    Node *l = (Node *)malloc(sizeof(Node));
    l->data = 0;
    l->pre = NULL;
    l->next = NULL;
    return l;
}
int main(int argc, char const *argv[])
{
    Node *List;
    printf("hello");
    return 0;
}
