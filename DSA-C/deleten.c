#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head; // global
void Insert(int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    struct Node* temp1 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
// insert an integer at the end of list
void Print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n ){
    struct Node* temp1 = head;
    if(n==1) {
        head = temp1->next; // head now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++) {
        temp1 = temp1 ->next;
        // temp1 points to (n-1)th Node
        struct Node* temp2 = temp1->next;
        temp1->next = temp2->next; // (n+1)th Node
        free(temp2); // delete temp2;
    }
}// delete node at position n
int main() {
    head = NULL; // empty list;
    Insert(2);
    Insert(4);    
    Insert(6);
    Insert(5); // list
    Print(); 
    int n;
    printf("enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}