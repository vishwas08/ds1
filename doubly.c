#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void insert_head();
void delete_val();
/*void insert_last();
void insert_val();
void delete_head();
void delete_last();
*/

struct Node
{
    int data;
    struct Node *link;
    struct Node *prev;
};
typedef struct Node node;
node *start=NULL;

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display \n3.Insert Head \n4.Delete val\n5.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_head();
            break;
        case 4:
            delete_val();
            break;
        case 5:
            exit(1);

        default:
            printf("Invalid choice\n");
        }
    }
}

void create()
{
    int c;
    node *new,*curr,*ptr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    ptr = start;
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            ptr->link = NULL;
            new->prev = curr;
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}
void insert_head(){
    node *temp,*mew;
    mew = (node *) malloc(sizeof(node));
    temp = start;
    printf("enter element value");
    scanf("%d",&mew->data);
    if(start=NULL){
        start = mew;
        mew->link = NULL;
        mew->prev = NULL;
    }
    else{
        mew->link = start;
        mew->prev = NULL;
    }
}
void delete_val(){
    int val;
    node *ptr,*prevptr;
    prevptr = start;
    ptr = start;
    printf("enter value to be deleted");
    scanf("%d",&val);
    while(ptr->data!=val){
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = ptr->link;
    ptr->link->prev = prevptr;
    free(ptr);

}
