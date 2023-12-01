//implimentation of priority queues
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	int priority;
};
struct node *front=0,*rear=0,*present;
//function for the enqueue
void enqueue(){
	struct node *temp,*temp1;
	int val,p;
	printf("enter val:\n");
	scanf("%d",&val);
	printf("enter priority:\n");
	scanf("%d",&p);
	present=(struct node *)malloc(sizeof(struct node));
	present->next=0;
	present->data=val;
	present->priority=p;
	if(rear==0){
		front=rear=present;
	}
	else{
		if(front->priority > present->priority){
			present->next=front;
			front=present;
		}
		else{
			temp=front;
			while(temp!=0){
				if(temp->priority <= present->priority ){
					temp1=temp;
					temp=temp->next;
				}
				else{
					break;
				}
			}
			present->next=temp1->next;
			temp1->next=present;
			if(temp1==rear){
				rear=rear->next;
			}
		}		
	}
	printf("insertion is done sucessfully\n");
}

//function for dequeueing 
void dequeue(){
	struct node *temp;
	if(front==0){
		printf("no element is present\n");
	}
	else if(front==rear){
		free(front);
		front=rear=0;
		printf("deleted successfully\n");
	}
	else{
		temp=front;
		front=front->next;
		printf("deleted successfully\n");
		free(temp);
	}
}

//function for the peek
void next_to_out(){
	if(front==0){
		printf("no element is present\n");
	}
	else{
		printf("%d",front->data);
	}
}
//function for displaying the queue
void display(){
	struct node *temp;
	if(front==0){
		printf("no element is present\n");
	}
	else{
		temp=front;
		while(temp!=rear){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}

void main(){
	int want;
	printf("here is the list of operation:\n");
	printf("press 1:enqueue\npress 2:dequeue\npress 3:display\npress 4:next_to_out\nselect operation\n");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				next_to_out();
				break;
			default:
				printf("no element is present\n");
		}
		printf("\nselect operation\n");
		scanf("%d",&want);
	}
	
	
}
