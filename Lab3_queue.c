#include<stdio.h>
 #include <stdlib.h>
 #define size 5
 
 int queue[size];
 int front=-1;
 int rear=-1;
 
 void insert(int value){
     if(rear==size-1){
         printf("Queue Overflow!\n");
     }
     else{
         front=0;
         rear++;
         queue[rear]=value;
         printf("%d is inserted into queue\n",value);
     }
 }
 
 void delete(){
     if(front==-1||front>rear){
         printf("Queue Underflow!\n");
     }
     else{
         printf("%d is deleted from the queue\n",queue[front]);
         front++;
     }
 }
 
 void display(){
     if(front==-1||front>rear){
         printf("Queue is Empty\n");
     }
     else{
         printf("Queue elements are:");
         for(int i=front;i<=rear;i++){
             printf("%d ",queue[i]);
         }printf("\n");
     }
 }
 
 void main(){
     int value;
     int choice;
     while(1){
         printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch(choice){
             case 1:printf("Enter a value to insert:");
             scanf("%d",&value);
             insert(value);
             break;
             case 2:delete();
             break;
             case 3:display();
             break;
             case 4:exit(0);
             default:printf("Invalid choice!Please enter again");
         }
     }
 }
