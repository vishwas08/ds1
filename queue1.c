#include <stdio.h>
#include<stdlib.h>
#define size 3
int queue[size];
int front=-1;
int rear=-1;
void insert(){
    int val;
    if(rear==size-1){
        printf("queue is full");
    }
    else {
        printf("enter a value");
        scanf("%d",&val);
        if(front==-1 && rear==-1){
            front=rear=0;
        }else{
            rear++;
        }
    }
    queue[rear]=val;

}
void delete(){
    int val;
    if(front==-1 && rear==-1){
        printf("queue is empty");
    }
    val = queue[front];
    if(front==rear){
        front = rear =-1;
    }
    else{
        front++;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("\nQueue is empty");
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
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
