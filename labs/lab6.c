#include <stdio.h>
#include <stdlib.h>

// ---- Node Tanimi ----
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ---- Kuyruk Yapisi ----
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// ---- Kuyrugu Baslat ----
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// ---- Kuyrugun Bos Olup Olmadigini Kontrol ----
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// ---- Kuyruga Eleman Ekle (enqueue) ----
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Kuyruk bossa hem front hem rear yeni node olur
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode; // son elemana ekle
    q->rear = newNode;       // rear'i güncelle
}

// ---- Kuyruktan Eleman Çikar (dequeue) ----
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Kuyruk bos!\n");
        return -1; // hata
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    // front NULL olduysa rear'i de NULL yap
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// ---- Kuyrugun Önündeki Eleman ----
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Kuyruk bos!\n");
        return -1;
    }
    return q->front->data;
}

// ---- Kuyruk Elemanlarini Yazdir ----
void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ---- Test ----
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    printf("Dequeue: %d\n", dequeue(&q));
    printQueue(&q);

    printf("Front: %d\n", peek(&q));

    return 0;
}
