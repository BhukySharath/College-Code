//implimentation of circulat queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *temp,*temp1,*newnode,*temp2,*tail=0,*head=0,*tempp;

//function for enqueue 
void enqueue(){
	int val;
	printf("enter the val:");
	scanf("%d",&val);
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=0;
	newnode->next=0;
	if(head==0 && tail==0){
		head=newnode;
		tail=newnode;
		tail->next=head;

	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
	tail->next=head;
	tail->data=val;
	printf("%d is added sucessfully\n",val);
}

//function for delqueue
void delqueue(){
	int val;
	temp=head;
	val=temp->data;
	temp1=temp->next;
	head=temp1;
	free(temp);
	tail->next=head;
	printf("%d is deleted\n");
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
	temp1=0;
	printf("here is the stored val:\n");
	while(temp1!=head){
		printf("%d ",temp->data);
		temp1=temp->next;
		temp=temp->next;
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
		printf("select the operation:\n");
		scanf("%d",&want);
	}
	printf("thank you!!!!\n");
	return 0;
}
