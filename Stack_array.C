#include<stdio.h>
#define SIZE 5

int Stack[SIZE], top = -1;

void push(int value){
    if(top == SIZE - 1){
        printf("Stack Overflow!\n");
        return;
    }
    Stack[++top] = value;
    printf("Pushed %d\n", value);
}

void pop(){
    if(top == -1){
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped %d\n", Stack[top--]);
}

void peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", Stack[top]);
}

void displayStack(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", Stack[i]);
    }
}

int main(){

    int choice, value;

    while(1){
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
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