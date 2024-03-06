#include<stdio.h>
#define MAXSIZE 10

struct stack
{int st[MAXSIZE];
 int top;
}ar;

int isFULL();
int isEMPTY();
void push(int data);
int pop();

void main()
{ ar.top=-1;
  it i,n;
  printf("How Many Values Do You Want To Enter:\n");
  scanf("%d",&n);
  for(i=0; i<n; i++)
   {int data;
    scanf("%d",&data);
    push(data);
   }
  printf("The Elements In The Stack Are:\n");
  for(i=0; i<n; i++)
  {printf("%d\n",ar.st[i]);
  }
  printf("How Many Elements Do You Want To Pop:\n");
  int n1;
  scanf("%d",&n1);
  for(i=0; i<n1; i++)
  {int x=pop();
   printf("Popped Elements:%d",x);
  }
  n=n-n1;
  printf("The Elements In The Stack Are:\n");
  for(i=0; i<n; i++)
  {printf("%d",ar.st[i]);
  }
}
int isFULL()
{ if(ar.top==MAXSIZE-1)
    return 1;
  else
    return 0;
}
int isEMPTY()
{ if(ar.top==-1)
    return 1;
  else
    return 0;
}
void push(int data)
{ if(isFULL())
  {printf("Overflow Condition!\n");
   exit(1);
  }
  else
  {ar.top++;
   ar.st[ar.top]=data;
   printf("Data Is Successfully Inserted\n");
  }
}
void pop()
{ if(isEmpty)
  {printf("Underflow Condition!\n");
   return(-1);
  }
  return ar.st[ar.top--];
}
  
