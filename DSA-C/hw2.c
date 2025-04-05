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
// Naive function for linked list implementation containing three nodes
struct Node* constructList()
{
 struct Node* head = newNode(1, newNode(2, newNode(3, NULL)));
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
 // `head` points to the first node (also known as a head node) of a linked list
 struct Node* head = constructList();
 // print linked list
 printList(head);
 return 0;
}
// 
//
//
//  ANSWER IS 1 -> 2 -> 3 -> NULL