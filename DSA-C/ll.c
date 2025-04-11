#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;  
};
struct Node* head;
void Insert(struct Node** head, int x) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(*head != NULL) temp->next = *head;
    *head = temp;
}
void Print(struct Node* head) {
    printf("List is: ");
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL; // empty list 
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(int i = 0;i<n;i++) {
        printf("enter the number \n");
        scanf("%d",&x);
        Insert(&head,x);
        Print(head);
    }
}