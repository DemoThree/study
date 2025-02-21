#include <stdio.h>
#include <stdlib.h>

typedef struct

{
    // 数组指针
    int *queue;

    int front, rear, size, capacity;

} CircularQueue;
CircularQueue *createQueue(int capacity)
{
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    int *queue = (int *)malloc(sizeof(int) * capacity);
    q->front = q->rear = q->size = 0;
    return 0;
}
void enqueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->queue[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}
int isFull(CircularQueue *q)
{

    return q->front == (q->rear + 1) % q->capacity;
}
int isEmpty(CircularQueue *q)
{
    return q->front == q->rear;
}
void deleteQueue(CircularQueue *q)
{
    free(q->queue);
    free(q);
}

int isFull(CircularQueue *q)
{
    return q->size == q->capacity;
}

int isEmpty(CircularQueue *q)
{
    return q->size == 0;
}

int dequeue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

int getFront(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front];
}

int getRear(CircularQueue *q)
{

    if (isEmpty(q))

    {

        printf("Queue is empty\n");

        return -1;
    }
    return q->queue[(q->rear - 1 + q->capacity) % q->capacity];
}
int main()
{

    CircularQueue *q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Front element is: %d\n", getFront(q));
    printf("Rear element is: %d\n", getRear(q));

    dequeue(q);
    enqueue(q, 60);

    printf("Front element is: %d\n", getFront(q));
    printf("Rear element is: %d\n", getRear(q));

    deleteQueue(q);
    return 0;
}
