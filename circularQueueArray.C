#include<stdio.h>

#define Capacity 5

int QueueSize = 0, rear = -1, front = 0;
int CircularQueue[Capacity];

void enqueue(int data){
    if(QueueSize == Capacity){
        printf("\nQueue Overflow!\n");
        return;
    }
    rear = (rear + 1) % Capacity;
    CircularQueue[rear] = data;
    printf("\n%d enqueued.\n", data);
    QueueSize++;
}

void dequeue(){
    if(QueueSize == 0){
        printf("\nQueue Underflow!\n");
        return;
    }
    printf("\n%d dequeued.\n", CircularQueue[front]);
    front = (front + 1) % Capacity;
    QueueSize--;
}

void peek(){
    if(QueueSize == 0){
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nFront element is %d\n", CircularQueue[front]);
}

void display(){
    if(QueueSize == 0){
        printf("\nQueue is Empty!\n");
        return;
    }

    int i, count;
    printf("\nQueue elements are: ");
    for(i = front, count = 0; count < QueueSize; count++){
        printf("%d ", CircularQueue[i]);
        i = (i + 1) % Capacity;
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}
