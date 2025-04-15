#include <stdio.h>
#define MAX_SIZE 100
// lifo last in first out
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};
void init(struct Stack* s) {
    s->top = -1;
}
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
int isFull(struct Stack* s) {
    return s->top == MAX_SIZE -1;
}
void push(struct Stack* s, int data) {
    if(isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = data;
}
int pop(struct Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
int main() {
    struct Stack s;
    init(&s);
    push(&s, 10);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Popped: %d\n", pop(&s));
    printf("Popped %d\n ", pop(&s));
    printf("Popped: %d\n", pop(&s));
    return 0;
}