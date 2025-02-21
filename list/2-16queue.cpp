#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure
struct Queue
{
    struct Node *front, *rear;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int data)
{

    struct Node *temp = newNode(data);

    // If queue is empty, then new node is front and rear both

    if (q->rear == NULL)

    {
        q->front = q->rear = temp;
        return;
    }
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
void dequeue(struct Queue *q)
{
    if (q->front == NULL)
        return;
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

// Function to display the front element of the queue
int front(struct Queue *q)
{
    if (q->front == NULL)
        return -1;
    return q->front->data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

int main()
{
    struct Queue *q = createQueue();

    // Enqueue elements
    enqueue(q, 10);

    enqueue(q, 20);

    enqueue(q, 30);

    // Display and dequeue elements
    while (!isEmpty(q))
    {
        printf("Front element: %d\n", front(q));
        dequeue(q);
    }

    return 0;
}