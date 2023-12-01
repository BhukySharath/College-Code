#include<stdio.h>
#include<stdlib.h>
#define len 5

int top=-1;
int stack[len];

//push function
void push(){
	int val;
	if(top>=len){
		printf("stack overflow\n");
	}
	else{
		printf("enter value:\n");
		scanf("%d",&val);
		top++;
		stack[top]=val;
		printf("%d is appended successfully!\n",val);
	}
	
}

//pop function
void pop(){
	int val;
	if(top<=-1){
		printf("uderflow!!!\n");
	}
	else{
		val=stack[top];
		top--;
		printf("%d is poped out\n",val);
	}
}

//peek function
void peek(){
	if(top>=len || top<=-1){
		printf("sorry we are enable to peek element\nit may went to overflow of underflow conditions\n");
    }
    else{
    	printf("%d\n",stack[top]);
	}
}

//function for displaying stack element
void show(){
	int temp;
	if(top>=len || top<=-1){
		printf("sorry we are enable to peek element\nit may went to overflow of underflow conditions\n");
    }
    else{
    	
    	temp=top;
		while(temp>=-1){
			printf("%d  ",stack[temp]);
			temp--;
		}
	}
	printf("\n");
}
int main(){
	int val;
	printf("here is the list of operation\n%d",len);
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
