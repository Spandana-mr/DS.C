#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_begin(struct node *start){
    struct node *newnode;
    int value;
    printf("enter a value to be inserted: ");
    scanf("%d",&value);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = start;
    start = newnode;
    return start;
}

struct node* insert_end(struct node *start){
    struct node *newnode, *ptr;
    int value;
    printf("enter a value to be inserted: ");
    scanf("%d",&value);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return start;
}

void display(struct node *start){
    struct node *ptr = start;
    printf("the contents of the linked list are: ");
    while(ptr->next != NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

int main(){
    struct node *start;
    start = (struct node*)malloc(sizeof(struct node));
    int value;
    printf("enter a value to insert at the start: ");
    scanf("%d",&value);
    start->data = value;
    start->next = NULL;
    int choice=0;
    while(choice!=4){
        printf("\n1.INSERT BACK\n2.INSERT FRONT\n3.DISPLAY\n4.EXIT\n");
        printf("enter an option: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: start = insert_end(start);
            break;
            case 2: start = insert_begin(start);
            break;
            case 3: display(start);
            break;
            case 4: break;
            default: printf("enter a valid option!!\n");
        }
    }
    return 0;
}
