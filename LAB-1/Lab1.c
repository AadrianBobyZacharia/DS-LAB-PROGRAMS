#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int top=-1;
int s[10];
int item;
void push()
{
if(top==STACK_SIZE -1)
{
printf("Stack Overflow\n");
return;
}
top=top+1;
s[top]=item;
}
int pop()
{
if(top==-1)
return -1;
return s[top--];
}
void display()
{
int i;
if(top==-1)
{
printf("Stack is empty\n");
return;
}
printf("Contents of the stack:\n");
for(i=0;i<=top;i++)
{
printf("%d\n",s[i]);
}
}
void main()
{
 int item_deleted;
 int choice;
 for(;;)
 {
  printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
  printf("Enter the choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter the item to be inserted\n");
          scanf("%d",&item);
          push();
          break;
   case 2:item_deleted=pop();
          if(item_deleted==-1)
            printf("Stack is empty\n");
          else
            printf("Item deleted is %d\n",item_deleted);
          break;
  case 3:display();
         break;
  default:exit(0);
 }
}
}
