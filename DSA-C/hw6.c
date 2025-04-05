#include <stdio.h>
#include <stdlib.h>

// Data structure to store a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Modified push(): Adds node to the **end** of the list
struct Node* push(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;  // New node is now the head
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to construct the list
struct Node* constructList(int keys[], int n) {
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {  // Forward loop for tail insertion
        head = push(head, keys[i]);
    }
    return head;
}

// Helper function to print the list
void printList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(void) {
    int keys[] = {1, 2, 3, 4};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct Node* head = constructList(keys, n);
    printList(head);

    return 0;
}

// 
// 
//
// ANSWER IS 1 -> 2 -> 3 -> 4 -> NULL