#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data){

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(front == NULL){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued successfully\n", data);
}

void dequeue(){

    if(front == NULL){
        printf("Queue Underflow!\n");
        return;
    }

    struct node* temp = front;
    printf("%d dequeued\n", front->data);

    if(front == rear){
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
}

void display(){

    if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }

    struct node* mover = front;

    printf("Front --> ");
    while(mover != NULL){
        printf("%d --> ", mover->data);
        mover = mover->next;
    }
    printf("NULL\n");
}

void peek(){

    if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element is %d\n", front->data);
}

int main(){

    int choice, value;

    while(1){

        printf("\n--- LINKED LIST QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
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
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
