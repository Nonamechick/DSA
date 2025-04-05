#include <stdio.h>
#include <stdlib.h>
// A Linked List Node
struct Node
{
 int data;
 struct Node* next;
};
// Global head pointer
struct Node* head = NULL;
// Takes a list and a data value, creates a new link with the given
// data and pushes it onto the list's front
void push(int data)
{
 // allocate a new node in a heap and set its data
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 // set the `.next` pointer of the new node to point to the current
 // head node of the list.
 newNode->next = head;
 // change the head pointer to point to the new node, so it is
 // now the first node in the list.
 head = newNode;
}
// Function for linked list implementation from a given set of keys
void constructList(int keys[], int n)
{
 // start from the end of the array
 for (int i = n - 1; i >= 0; i--) {
 push(keys[i]);
 }
}
// Helper function to print the global linked list `head`
void printList()
{
 struct Node* ptr = head;
 while (ptr)
 {
 printf("%d -> ", ptr->data);
 ptr = ptr->next;
 }
 printf("NULL");
}
int main(void)
{
 // input keys
 int keys[] = {1, 2, 3, 4};
 int n = sizeof(keys)/sizeof(keys[0]);
 // `head` points to the first node (also known as a head node) of a linked list
 constructList(keys, n);
 // print linked list
 printList();
 return 0;
}

//
//
//
// ANSWER IS 1 -> 2 -> 3 -> 4 -> NULL