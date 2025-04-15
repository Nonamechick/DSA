#include <stdio.h>
#define MAX_SIZE 100
// fifo first in first out
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};
void init(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(struct Queue* q) {
    return q->rear < q->front;
}
int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}
void enqueue(struct Queue* q, int data) {
    if(isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->arr[++(q->rear)] = data;
}
int dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->arr[(q->front)++];
}
int main() {
    struct Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued %d\n",dequeue(&q));
    printf("Dequeued %d\n",dequeue(&q));
    printf("Dequeued %d\n",dequeue(&q));
    return 0;
}