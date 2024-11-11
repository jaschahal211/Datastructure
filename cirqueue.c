#include <stdio.h>
#define max 5
int myqueue[max];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    do {
        printf("\n1-Insert\n2-Delete\n3-Print\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
}

void enqueue() {
    int item;
    printf("Enter element you want to insert into the queue: ");
    scanf("%d", &item);

    if ((rear + 1) % max == front) {
        printf("Queue Overflow! Cannot insert.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % max;
        myqueue[rear] = item;
        printf("Element %d inserted successfully.\n", item);
    }
}

void dequeue() {
    int item;
    if (front == -1) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        item = myqueue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
        printf("Element %d deleted successfully.\n", item);
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contents: ");
        i = front;
        while (i != rear) {
            printf("%d ", myqueue[i]);
            i = (i + 1) % max;
        }
        printf("%d ", myqueue[rear]);
        printf("\n");
    }
}

