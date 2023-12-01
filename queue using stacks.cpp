//implimention of queue using stacks 

#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack1[10],stack2[10],top=-1;

//function push nothing but enque
void push(int val){
	stack1[++top]=val;
}

//function for pop nothing but deque
void pop(){
	int i=0;
	while(top>=0){
		stack2[i]=stack1[top];
		top--;
		i++;
	}
	i=i-2;
	top=-1;
	while(i>=0){
		stack1[++top]=stack2[i];
		i--;
	}
		
}
void enque(){
	int val;
	printf("enter the val:\n");
	scanf("%d",&val);
	if(top==max-1){
		printf("overflow condition\n");
	}
	else{
		push(val);
	}
}

//function for the deque
void deque(){
	if(top==-1){
		printf("underflow condition\n");
	}
	else{
		pop();
		printf("dequed successfully!\n");
	}

}
void display(){
	if(top==-1){
		printf("no element is present!\n");
	}
	else{
		for(int i=0;i<=top;i++){
			printf("%d ",stack1[i]);
		}
	}

}
//main function
int main(){
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
	return 0;
}
