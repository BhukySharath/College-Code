//implimentation of stack using static memory alocation(arrays)
#include<stdio.h>
#include<stdlib.h>
#define len 7
int pos=-1;
int stack[len];
int undolen=0;

struct undoo{
	int data;
	struct undoo *next,*prev;
};
struct undoo *present=-1,*head=0,*temp;
//function for updating undo elements
void update(int val){
	present=(struct undoo *)malloc(sizeof(struct undoo));
	present->next=present->prev=0;
	present->data=val;
	if(head==0){
		head=present;
		head->prev=0;
	}
	else{
		present->prev=temp;
		temp->next=present;
	}
	temp=present;
	undolen++;
}
//function for insertion
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
	update(1);
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
	update(-1);
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
	if(pos>=0){
		for(int i=0;i<=pos;i++){
			printf("%d ",stack[i]);
		}
	}
	else{
		printf("NO ELEMENT IS PRESENT\n");
	}
}
//function for undo
void undo(){
	int val;
	if(undolen<=0 || present==0)
		printf("enable to undo\n");
	}
	else{
		val=present->data;
		temp=present;
		present=present->prev;
		free(temp);
		undolen--;
		if(val==1){
			pos--;
		}
		else{
			pos++;
		}
		printf("undo operation is done succesfully\n");
	}
}
int main(){
	int want;
	printf("here is the list operations\n");
	printf("press 1:push\npress 2:pop\npress 3:peek\npress 4:isempty\npress 5:isfull\npress 6:display\npress 7:undo\n");
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
		else if(want==7){
			undo();
		}
		else{
			printf("we dont have such any operation\n");
		}
		printf("select opreration:\n");
		scanf("%d",&want);
	}	
	return 0;
}
