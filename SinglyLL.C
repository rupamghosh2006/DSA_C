#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* InsertAtBegin(struct node* Head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
    printf("Memory allocation failed\n");
    exit(1);
    }

    newNode->data = data;
    newNode->next = Head;

    return newNode;
}

struct node* InsertAtEnd(struct node* Head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
    printf("Memory allocation failed\n");
    exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

     if(Head == NULL){
        return newNode;
    }

    struct node* Mover = Head;
    while(Mover->next != NULL){
        Mover = Mover->next;
    }
    Mover->next = newNode;

    return Head;
}

struct node* InsertAfterNode(struct node* Head, int data, int Location){

    if(Head == NULL){
        printf("Location not found, insertion not possible.\n");
        return Head;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;

    struct node* Mover = Head;

    while(Mover != NULL){

        if(Mover->data == Location){

            newNode->next = Mover->next;
            Mover->next = newNode;

            return Head;   
        }

        Mover = Mover->next;
    }

    printf("Location not found, insertion not possible.\n");
    free(newNode);  

    return Head;
}

void displayList(struct node* Head){

    if(Head == NULL){
        printf("List is Empty\n");
        return;
    }

    struct node* Mover = Head;

    printf("Head->");
    
    while(Mover != NULL){
        printf("%d->",Mover->data);
        Mover = Mover->next;
    }
    
    printf("NULL\n");
}

int main(){
    struct node* Head = NULL;
    int choice;

    while(1){
        printf("Enter choice:\n1. Display List\n2. Insert at Begin\n3. Insert at End\n4. Insert after specific location\n5. Exit\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:{
            displayList(Head);
            break;
        }
        case 2:{
            int data;
            printf("Enter the value you want to insert at the Beginning: ");
            scanf("%d",&data);
            Head = InsertAtBegin(Head,data);
            break;
        }
        case 3:{
            int data;
            printf("Enter the value you want to insert at the End: ");
            scanf("%d",&data);
            Head = InsertAtEnd(Head,data);
            break;
        }
        case 4:{
            int location, data;
            printf("Enter the value of the Element after which you want to insert the node: ");
            scanf("%d",&location);
            printf("Enter the value you want to insert: ");
            scanf("%d",&data);
            Head = InsertAfterNode(Head,data,location);
            break;
        }
        case 5:{
            exit(0);
            break;  
        }  
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}