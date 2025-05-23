#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InserAtHead(int x) {
    // struct Node myNode;
    // myNode.data = x;
    // myNode.prev = NULL;
    // myNode.next = NULL;
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void Print() {
    struct Node* temp = head;
    printf("forward: ");
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL) return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    head = NULL;
    InserAtHead(2); Print(); ReversePrint();
    InserAtHead(4); Print(); ReversePrint();
    InserAtHead(6); Print(); ReversePrint();
}