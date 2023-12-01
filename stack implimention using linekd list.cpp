#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
struct stack *top=0,*temp,*newnode,*temp1;

//push function
void push(){
	int x;
	printf("enter val:\n");
	scanf("%d",&x);
	newnode=(struct stack *) malloc(sizeof(struct stack));
	newnode->data=x;
	if(top==0){
		newnode->next=0;
		top=newnode;
	}
	else{
		newnode->next=top;
		top=newnode;
	}
	printf("%d stored successfully\n",x);
	
}

//pop function
void pop(){
	int val;
	if(top->next=0){
		top=0;
		printf("your operation done!!\n");
	}
	else{
		val=top->data;
		temp=top;
		top=top->next;
		free(temp);
		printf("%d is poped out\n",val);
	}
}

//peek function
void peek(){
	if(top==0){
		printf("no value is there\n");
	}
	else{
		printf("the peek element is %d\n",top->next);
	}
	
}

//function for displaying stack element
void show(){
	if(top->next==0){
		printf("%d ",top->data);
	}
	else{
		temp=top;
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	
	}
}
int main(){
	int val;
	printf("here is the list of operation\n");
	printf("press 0:exit\npress 1:push\npress 2:pop\npress 3:peek\npress 4:display\n");
	scanf("%d",&val);
	while(val){
		if(val==1){
			push();
		}
		else if(val==2){
			pop();
		}
		else if(val==3){
			peek();
		}
		else if(val==4){
			show();
		}
		else{
			printf("sorry we dont have any operations\n");
		}
		printf("select operation\n");
		scanf("%d",&val);
	}
	return 0;
}
