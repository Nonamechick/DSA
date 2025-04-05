// #include <stdio.h>
// #include <stdlib.h>
// // Data Structure to store a linked list node
// struct Node
// {
//  int data;
//  struct Node* next;
// };
// void push(struct Node* head, int data)
// {
//  // allocate a new node in a heap and set its data
//  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//  newNode->data = data;
//  // set the `.next` pointer of the new node to point to the current
//  // first node (head node) of the list.
//  newNode->next = head;
//  // change the head pointer to point to the new node, so it is
//  // now the first node in the list.
//  head = newNode; // No, this line does not work! (Why?)
// }
// // Function for linked list implementation from a given set of keys
// struct Node* constructList(int keys[], int n)
// {
//  struct Node* head = NULL;
//  // start from the end of the array
//  for (int i = n - 1; i >= 0; i--) {
//  push(head, keys[i]); // try to push a key at front – doesn't work
//  }
//  return head;
// }
// // Helper function to print given linked list
// void printList(struct Node* head)
// {
//  struct Node* ptr = head;
//  while (ptr)
//  {
//  printf("%d -> ", ptr->data);
//  ptr = ptr->next;
//  }
//  printf("NULL");
// }
// int main(void)
// {
//  // input keys
//  int keys[] = {1, 2, 3, 4};
//  int n = sizeof(keys)/sizeof(keys[0]);
//  // head points to first node (also called as head node) of linked list
//  struct Node* head = constructList(keys, n);
//  // print linked list
//  printList(head);
//  return 0;
// }

// 
// 
//
// ANSWER IS NULL Before push() correction

#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
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
        return newNode;
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
    for (int i = 0; i < n; i++) {  // Forward loop since we're inserting at the tail
        head = push(head, keys[i]);
    }
    return head;
}

// Function to print the list
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
// ANSWER IS 1 -> 2 -> 3 -> 4 -> NULL  After correction 