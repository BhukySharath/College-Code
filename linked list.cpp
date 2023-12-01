//data structure in c
//linked list implemtation reading and displaying on the output screen
#include<stdio.h>
#include<stdlib.h>
struct node
  {
  	int data;
  	struct node *next;
  };
int  main()
{  
int choice;
struct node * head,*temp,*newnode;
head=0;
printf("enter the choice (0,1)?");
scanf("%d",&choice);
while(choice)

{  
    newnode = (struct node*) malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=newnode;
		temp=newnode;
	}
	else{
		temp->next=newnode;
		temp=newnode;
	}
printf("enter the choice (0,1)?");
scanf("%d",&choice);

}
	//printing on the output screen 
temp=head;
while(temp!=0)
{
	printf("%d\n",temp->data);
	temp=temp->next;
}
return 0;
}
