//implimentation of stack using static memory alocation(arrays)
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *next,*prev;
};
struct stack *top=0,*head=0,*present;
//function for push
void push(){
	static struct stack *temp=0;
	int val;
	printf("enter val:\n");
	scanf("%d",&val);
	present=(struct stack *)malloc(sizeof(struct stack));
	present->next=present->prev=0;
	present->data=val;
	if(top==0){
		head=top=present;
	}
	else{
		top=present;
		temp->next=top;
		top->prev=temp;
	}
	temp=top;
	printf("%d is pushed sucessfully\n",top->data);
}

//function for pop 
void pop(){
	if(top==0){
		printf("underflow condition\n");
	}
	else{
		printf("%d is poped out\n",top->data);
		top=top->prev;
	}
}

//function for peek operation
void peek(){
	if(top==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{
		printf("peek:%d\n",top->data);
	}
	
}

//function for empty
void isempty(){
	if(top==0){
		printf("TRUE\n");
	}
	else{
		printf("FALSE\n");
	}
}

//checking for is full
void isfull(){
	printf("FALSE\n");

}
//function for displaying stack
void display(){
	struct stack *tem=head;
	if(top==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{
		while(tem!=0){
			printf("%d ",tem->data);
			tem=tem->next;
		}
		
	}

}
int main(){
	int want;
	printf("here is the list operations\n");
	printf("press 1:push\npress 2:pop\npress 3:peek\npress 4:isempty\npress 5:isfull\npress 6:display\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			push();
		}
		else if(want==2){
			pop();
		}
		else if(want==3){
			peek();
		}
		else if(want==4){
			isempty();
		}
		else if(want==5){
			isfull();
		}
		else if(want==6){
			display();
		}
		else{
			printf("we dont have such any operation\n");
		}
		printf("select opreration:\n");
		scanf("%d",&want);
	}	
	return 0;
}
