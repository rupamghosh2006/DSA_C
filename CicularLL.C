#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* InsertAtBegin(struct node* Head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
        printf("Memory error!\n");
        exit(1);
    }

    newNode->data = data;

    if(Head == NULL){
        Head = newNode;
        newNode->next = Head;
    }
    else{
        struct node* Mover = Head;

        while(Mover->next != Head)
            Mover = Mover->next;

        Mover->next = newNode;
        newNode->next = Head;
        Head = newNode;
    }

    return Head;
}

struct node* InsertAtEnd(struct node* Head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL){
        printf("Memory error!\n");
        exit(1);
    }

    newNode->data = data;

    if(Head == NULL){
        Head = newNode;
        newNode->next = Head;
    }
    else{
        struct node* Mover = Head;

        while(Mover->next != Head)
            Mover = Mover->next;

        Mover->next = newNode;
        newNode->next = Head;
    }

    return Head;
}

int main(){
    struct node* Head = NULL;
    int choice, data;

    while(1){
        printf("\n1. Insert At Beginning");
        printf("\n2. Insert At End");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Head = InsertAtBegin(Head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                Head = InsertAtEnd(Head, data);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}