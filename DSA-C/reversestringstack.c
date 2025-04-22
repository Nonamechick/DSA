#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

void reverseString(char* str) {
    int i;
    // Push all characters of the string into the stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop all characters from the stack and put them back to the string
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove trailing newline from fgets
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
