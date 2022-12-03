#include <stdio.h>
#include<stdlib.h>
#define size 3
int queue[size];
int front=-1;
int rear=-1;
void insert(){
    int val;
    if(front ==0 && rear==size-1 || front == rear+1){
        printf("circular queue is full");
    }
    else {
        printf("enter a value");
        scanf("%d",&val);
        if(front==-1 && rear==-1){
            front=rear=0;
        }
        else{
            rear = (rear+1)%size;
        }
    }
    queue[rear]=val;

}
void delete(){
    int val;
    if(front==-1 && rear==-1){
        printf("circular queue is empty");
    }
    val = queue[front];
    if(front==rear){
        front = rear =-1;
    }
    else{
        front = (front+1)%size;
    }
}
void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("\ncircular Queue is empty");
    }
    if(rear>front){
        for(i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
    else{
        for(i=0;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        for(i=front;i<=size-1;i++){
            printf("%d\t",queue[i]);
        }




    }

}
int main()
{
     int choice;

    while(1){
    printf("\nEnter choice\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:insert();
        break;
        case 2:delete();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        default :printf("Invalid chocie");

    }

    }

    return 0;
}
