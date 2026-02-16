#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data){
    if(rear == SIZE - 1){
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }

    queue[rear] = data;
    printf("%d enqueued successfully\n", data);
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
        return;
    }
    else if(front == rear){
        printf("%d dequeued\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("%d dequeued\n", queue[front]);
        front++;
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", queue[front]);
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for(int i = front; i <= rear; i++){
        printf("%d\n", queue[i]);
    }
}

int main(){

    int choice, value;

    while(1){

        printf("\n--- QUEUE MENU ---\n");
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
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
