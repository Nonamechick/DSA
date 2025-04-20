#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top =-1;
void Push(int x) {
    if(top == MAX_SIZE -1) {
        printf("error overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop() {
    if(top == -1) {
        printf("Error: No elements \n");
        return;
    }
    top--;
}
int Top() {
    return A[top];
}
void Print() {
    int i;
    printf("Stack: ");
    for(i = 0; i<=top; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main() {
    Push(2); Print();
    Push(5); Print();
    Push(21); Print();
    Pop(); Print();
    Push(32); Print();
}