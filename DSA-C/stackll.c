#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* link;
};

// Pointer to the top of the stack
struct Node* top = NULL;

// Push operation
void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Stack overflow\n");
        return;
    }
    temp->data = x;
    temp->link = top;
    top = temp;
}

// Pop operation
void Pop() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

// Peek operation (returns top element)
int Peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Check if stack is empty
int IsEmpty() {
    return top == NULL;
}

// Display stack elements
void Display() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Main function for testing
int main() {
    Push(10);
    Push(20);
    Push(30);
    Display();

    printf("Top element is: %d\n", Peek());

    Pop();
    Display();
    printf("Top element is: %d\n", Peek());

    Pop();
    Display();
    printf("Top element is: %d\n", Peek());
    
    Pop();
    Display();
    printf("Top element is: %d\n", Peek());

    Pop(); // Attempt to pop from empty stack

    return 0;
}
