//implimentation of queue using arrays

#include<stdio.h>
#include<stdlib.h>
#define len 5

int temp1=-1,temp2=-1;
int stack1[len],stack2[len];

//function for enqueue 
void enqueue(){
	int x;
	printf("enter val:\n");
	scanf("%d",&x);
	if(temp1>=len){
		printf("stack overflow\n");
	}
	else{
		temp1++;
		stack1[temp1]=x;
	}
	printf("%d is added successfully\n",x);
}

//function for delqueue
void delqueue(){
	int val;
	if(temp1>=0){
		while(temp1>=0){
		temp2++;
		stack2[temp2]=stack1[temp1];
		temp1--;
	}
	val=stack2[temp2];
	temp2--;
	while(temp2>=0){
		temp1++;
		stack1[temp1]=stack2[temp2];
		temp2--;
	}
	printf("%d is deleted successfully\n",val);
	
	}
	else{
		printf("enable to delete\n");
	}
}

//peek function
void peek(){
	int val;
	if(temp1>=0){
		while(temp1>=0){
		temp2++;
		stack2[temp2]=stack1[temp1];
		temp1--;
	}
	val=stack2[temp2];
	temp2--;
	printf("peek val:%d\n",val);
	
	}
	else{
		printf("peek enable to fetch\n");
	}
}

//function for is full
void isfull(){
	if(temp1>=len){
		printf("True\n");
	}
	else{
		printf("False\n");
	}

}

//function for is empty
void isempty(){
	if(temp1<=0){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}

//show function
void show(){
	if(temp1>=len || temp1<=0){
		printf("enable to display\n");
	}
	else{
		for(int temp=0;temp<=temp1;temp++){
		printf("%d ",stack1[temp]);
	}
	}
	
	
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
