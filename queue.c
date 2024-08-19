#include <stdio.h>
#define size 10

int rear = -1, front = -1;


void AddQ(int q[], int elem) {
    rear = rear + 1;
    q[rear] = elem;
}

int DelQ(int q[]) {
    front = front + 1;
    return q[front];
}

int isFull() {
    return (rear == size - 1);
}

int isEmpty() {
    return (rear == front);
}

void display(int q[]) {
int i;
    printf("Queue: ");
    if (!isEmpty()) {
        for ( i = front + 1; i <= rear; i++)
            printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int q[size], choice, elem;

    do {
        printf("\n1. Add Element \n");
        printf("2. Delete Element \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull())
                    printf("Queue is full\n");
                else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &elem);
                    AddQ(q, elem);
                    printf("%d Added successfully\n", elem);
                }
                break;

            case 2:
                if (isEmpty())
                    printf("Queue is empty\n");
                else {
                    elem = DelQ(q);
                    if (elem != -1)
                        printf("%d Removed successfully\n", elem);
                    else
                        printf("Error in dequeue operation\n");
                }
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
