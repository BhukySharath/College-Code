//implimentation of stack using static memory alocation(arrays)
#include<stdio.h>
#include<stdlib.h>
#define len 7
int pos=-1;
int stack[len];
//function for push
void push(){
	int val;
	if(pos>=len-1){
		printf("insertion is not possible due to overflow condition\n");
	}
	else{
		printf("enter element:\n");
		scanf("%d",&val);
		pos++;
		stack[pos]=val;
		printf("push operation done successfully\n");
	}
}

//function for pop 
void pop(){
	int val;
	if(pos<=-1){
		printf("deletion operation is not possible due to under flow condition\n");
	}
	else{
		printf("%d is poped out\n",stack[pos]);
		pos--;
	}
}

//function for peek operation
void peek(){
	if(pos>0){
		printf("%d is peek\n",stack[pos]);
	}
	else{
		printf("NO ELEMENT IS THERE\n");
	}
	
}

//function for empty
void isempty(){
	if(pos==-1){
		printf("TRUE\n");
	}
	else{
		printf("FALSE\n");
	}
}

//checking for is full
void isfull(){
	if(pos==len-1){
		printf("TRUE\n");
	}
	else{
		printf("FALSE\n");
	}
}
//function for displaying stack
void display(){
	if(pos>0){
		for(int i=0;i<=pos;i++){
			printf("%d ",stack[i]);
		}
	}
	else{
		printf("NO ELEMENT IS PRESENT\n");
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
