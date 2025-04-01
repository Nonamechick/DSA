#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[], int size) {
    for (int i =0; i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insert(int arr[], int *size, int element, int pos) {
    if (*size >= MAX_SIZE) {
        printf("Arr is full\n");
        return 0;
    }
    else if (pos<0 || pos> *size) {
        printf("Invalid position");
        return 0;
    }
    for (int i= *size; i>pos;i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    (*size)++;
    return 1;
}
int delete(int arr[], int *size, int pos) {
    if(*size <=0) {
        printf("Arr is empty\n");
        return 0;
    }
    else if (pos <0 || pos >= *size) {
        printf("Invalid pos\n");
        return 0;
    }
    for (int i = pos; i< *size-1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
    return 1;
}
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    insert(arr, &size, 312,0);
    insert(arr, &size, 534,1);
    insert(arr, &size, 521, 1);
    printf("Arr after insertions: ");
    display(arr,size);
    delete(arr, &size, 1);
    printf("Array after deletion: ");
    display(arr,size);
    return 0;
}