//implimentation of queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *temp,*temp1,*newnode,*temp2,*tail=0,*head=0;


//function for enqueue 
void enqueue(){
	int val;
	printf("enter the val:\n");
	scanf("%d",&val);
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=0;
	newnode->next=0;
	if(tail==0 && head==0){
		tail=newnode;
		head=newnode;
		temp=newnode;
	}
	else{
		tail=newnode;
		temp->next=newnode;
	}
	newnode->data=val;
	temp=newnode;
	printf("%d is added successfully\n",val);
}

//function for delqueue
void delqueue(){
	int val;
	if(head==0 && tail==0){
		printf("enable to delete\n");
	}
	else{
		temp=head;
		head=head->next;
		val=temp->data;
		free(temp);
	}
	printf("%d is deleted successfully!\n",val);
	
}

//peek function
void peek(){
	if(head==0){
		printf("enable to peek now\n");
	}
	else{
		printf("peek val:%d\n",head->data);
	}
}

//function for is full
void isfull(){
	printf("False\n");
}

//function for is empty
void isempty(){
	if(tail==0){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}

//show function
void show(){
	temp=head;
	if(head==0){
		printf("enable to display");
	}
	else{
		printf("here is the stored val:\n");
		while(temp!=0){
		printf("%d ",temp->data);
		temp=temp->next;
		}
	}
	printf("\n");
}

int main(){
	int want,val;
	printf("here is the list of operations\n");
	printf("press 0:exit\npress 1:enqueue\npress 2:delqueue\npress 3:peek\npess 4:isfull\npess 5:isempty\npress 6:display\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			enqueue();
		}
		else if(want==2){
			delqueue();
		}
		else if(want==3){
			peek();
		}
		else if(want==4){
			isfull();
		}
		else if(want==5){
			isempty();
		}
		else if(want==6){
			show();
		}
		else{
			printf("select only from given operations");
		}
		printf("select the operation\n");
		scanf("%d",&want);
	}
	return 0;
}
