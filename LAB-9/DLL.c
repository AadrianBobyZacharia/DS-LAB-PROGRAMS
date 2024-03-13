#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
struct node *prev;
int data;
struct node *next;
}DLL;
DLL *head=NULL;
DLL *tail=NULL;
DLL *temp=NULL;
int count=0;
DLL* createnode(int x)
{
DLL* newnode=(DLL*)malloc(sizeof(DLL));
newnode->prev=NULL;
newnode->data=x;
newnode->next=NULL;
return newnode;
}
void insertfront(int x)
{
DLL *nn=createnode(x);
if(count==0)
{head=nn;
tail=head;}
else{
nn->next=head;
head->prev=nn;
head=nn;
}
count++;
}
void deleteaftergivenvalue(int y)
{
if(count==0)
printf("Double Linked List is empty");
else{
temp=head;
while(temp->data!=y){
temp=temp->next;
if(temp==NULL)
{
printf("Not present in DLL\n");
exit(0);
}
}
temp=temp->next;
temp->next->prev=temp->prev;
temp->prev->next=temp->next;
free(temp);
count--;
}
}
void display()
{
temp=head;
if(count==0)
printf("Double Linked List is Empty\n");
else{
printf("Linked List is:\n");
printf("[%d|%d|%d]<-->",temp->prev,temp->data,temp->next);
temp=temp->next;
while(temp->next!=NULL)
{
printf("[%d|%d|%d]<-->",temp->prev,temp->data,temp->next);
temp=temp->next;
}
printf("[%d|%d|%d]\n",temp->prev,temp->data,temp->next);
}
}
void main()
{
int choice,x1,x2,count=0;
while (choice!=4)
{
printf("\nPlease select the process to be executed 1:Insertfront
2:deleteaftergivenvalue 3:DisplayLL 4:End\n");
scanf("%d",&choice);
switch(choice){
case 1: printf("Enter the number to be inserted at first");
scanf("%d",&x1);insertfront(x1);
break;
case 2: printf("Enter the value after which the node must be
deleted:");
scanf("%d",&x2);
deleteaftergivenvalue(x2);
break;
case 3: display();
break;
}
}
}
