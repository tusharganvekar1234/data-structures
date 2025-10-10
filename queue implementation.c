#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue {
    int front, rear;
    int data[SIZE];
};

typedef struct queue QUEUE;

void enqueue(QUEUE *q, int item) {
    if (q->rear == SIZE - 1) {
        printf("\nQueue overflow\n");
    } else {
        q->rear++;
        q->data[q->rear] = item;
        if (q->front == -1)
            q->front = 0;
        printf("\nEnqueued %d\n", item);
    }
}

void dequeue(QUEUE *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("\nQueue underflow\n");
    } else {
        printf("\nDequeued %d\n", q->data[q->front]);
        q->front++;
        // Reset queue if empty after dequeue
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

void display(QUEUE q) {
    if (q.front == -1) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue contents:\n");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    QUEUE q;
    q.front = q.rear = -1;

    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
