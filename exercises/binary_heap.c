#include <stdio.h>


#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap dolu!\n");
        return;
    }

    heap[size] = value;
    int i = size;
    size++;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

int deleteRoot() {
    if (size == 0) {
        printf("Heap bos!\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return root;
}

void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);

    printf("Heap: ");
    printHeap();

    printf("Silinen eleman: %d\n", deleteRoot());
    printHeap();

    printf("Silinen eleman: %d\n", deleteRoot());
    printHeap();

    return 0;
}
