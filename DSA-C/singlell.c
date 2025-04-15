#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* creteNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBegining(struct Node** head, int data) {
    struct Node* newNode = creteNode(data);
    newNode->next = *head;
    *head = newNode;
}
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if(temp!=NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL) return;
    prev->next =temp->next;
    free(temp);
}
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp!= NULL) {
        printf("%d -> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    
    insertAtBegining(&head,30);
    insertAtBegining(&head,20);
    insertAtBegining(&head,10);
    printf("Linked list: ");
    display(head);

    deleteNode(&head, 30);
    printf("after deleting 30: ");
    display(head);
    return 0;
}