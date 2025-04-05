#include <stdio.h>
#include <stdlib.h>
// Data structure to store a linked list node
struct Node
{
 int data;
 struct Node* next;
};
// Helper function to return new linked list node from the heap
struct Node* newNode(int data, struct Node* nextNode)
{
 // allocate a new node in a heap and set its data
 struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 node->data = data;
 // set the `.next` pointer of the new node to point to the current
 // first node of the list.
 node->next = nextNode;
 return node;
}
// Function for linked list implementation from a given set of keys
struct Node* constructList(int keys[], int n)
{
 struct Node *head = NULL, *node = NULL;
 // start from the end of the array
 for (int i = n - 1; i >= 0; i--)
 {
 node = newNode(keys[i], node);
 head = node;
 }
 return head;
}
// Helper function to print a linked list
void printList(struct Node* head)
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
 struct Node* head = constructList(keys, n);
 // print linked list
 printList(head);
 return 0;
}

//
//
//
// ANSWER IS 1 -> 2 -> 3 -> 4 -> NULL