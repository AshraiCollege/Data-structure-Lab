#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the queue

// Circular Queue structure
struct CircularQueue {
    char queue[MAX];  // Array to hold the queue elements
    int front;        // Points to the front of the queue
    int rear;         // Points to the rear of the queue
};

// Function to initialize the queue
void initialize(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue *q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element into the queue
void enqueue(struct CircularQueue *q, char element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = element;
    printf("Inserted %c into the queue.\n", element);
}

// Function to delete an element from the queue
void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }

    printf("Deleted %c from the queue.\n", q->queue[q->front]);

    if (q->front == q->rear) {
        // Queue becomes empty after deletion
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Function to display the queue
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%c ", q->queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", q->queue[i]);
}

// Main function to drive the menu
int main() {
    struct CircularQueue q;
    initialize(&q);

    int choice;
    char element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an Element into Circular Queue\n");
        printf("2. Delete an Element from Circular Queue\n");
        printf("3. Display Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to insert: ");
                scanf(" %c", &element);
                enqueue(&q, element);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
