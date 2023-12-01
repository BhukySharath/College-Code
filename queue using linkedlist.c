//implimentation of queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct que{
	int data;
	struct node *next;
};
struct que *front=0,*rear=0,*present;

//function for enque
void enque(){
	int val;
	printf("enter val:\n");
	scanf("%d",&val);
	present=(struct que *)malloc(sizeof(struct que));
	present->data=val;
	present->next=0;
	if(rear==0 && front==0){
		front=rear=present;
	}
	else{
		rear->next=present;
		rear=present;
	}
	printf("enqued successfully!\n");
}

//function for deque
void deque(){
	if(front==0){
		printf("underflow condition\n");
	}
	else if(front==rear){
		free(front);
		front=rear=0;
		printf("enqued succesfully!\n");
	}
	else{
		present=front;
		front=front->next;
		free(present);
		printf("dequed successfully!\n");
	}
}

//function for display
void display(){
	if(front==0){
		printf("no element is present\n");
	}
	else{
		present=front;
		while(present!=rear->next){
			printf("%d ",present->data);
			present=present->next;
		}
	}
	
}
//main function
void main(){
	int want;
	printf("here is the list operation\n");
	printf("press 1:enque\npress 2:deque\npress 3:display\npress 0:exit\n");
	scanf("%d",&want);
	while(want){
		switch (want){
			
			case 1:enque();break;
			case 2:deque();break;
			case 3:display();break;
			default:printf("we dont have any such kind of operation\n");
			
		}
		printf("select operation:\n");
		scanf("%d",&want);
		
	}
}
