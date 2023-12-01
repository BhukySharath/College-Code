//implimentation of circular queue using arrays

#include<stdio.h>
#include<stdlib.h>
#define len 5

int head=-1,tail=-1;
int que[len];
//checks if array has any space to store the val

int isspace(){
	if((tail+1)%len==head){
		return 1;
	}
	else{
		return 0;
	}
}

//function for enqueuefront
void enqueuefront(){
	int val;
	printf("enter val:\n");
	scanf("%d",&val);
	if(head==-1 && tail==-1){
		head++;
		tail++;
		que[head]=val;
	}
	else if(head==0){
		head=len-1;
		que[head]=val;
	}
	else{
		head--;
		que[head]=val;
	}
    printf("%d is succesfully added\n",val);
}

//function for delqueue
void delqueuefront(){
	int val;
	if(head==-1 && tail==-1){
		printf("enable to delete\n");
	}
	else if(head==len-1){
		val=que[head];
		head=0;
	}
	else if(head==tail){
		head=tail=-1;
	}
	
	else{
		val=que[head];
		head++;
	}
	printf("%d is deleted successfully\n",val);
}

//enqueueback function
void enqueback(){
	int val;
	printf("enter val:\n");
	scanf("%d",&val);
	if(head==-1 && tail==-1){
		head++;
		tail++;
		que[tail]=val;
	}
	else if(tail==len-1){
		tail=0;
		que[tail]=val;
	}
	else {
		tail++;
		que[tail]=val;
	}
	printf("%d is added successfully\n",val);
}

//delqueueback function

void delqueback(){
	int val;
	val=que[tail];
	if(tail==-1 && head==-1){
		printf("enable to delete\n");
	}
	else if(tail=0){
		tail=len-1;
	}
	else if (head==tail){
		head=tail=-1;
	}
	else{
		tail--;
	}
	printf("%d deleted successfully\n");
}
//peek function
void peek(){
	if(head==-1 && tail==-1){
		printf("enable to peek now\n");
	}
	else{
		printf("peek val:%d",que[head]);
	}
}

//function for is full
int isfull(){
	if(!(isspace)){
		printf("True\n");
		return 1;
	}
	else{
		printf("False\n");
		return 0;
	}
}

//function for is empty
int isempty(){
	if(!(isfull)){
		printf("True\n");
		return 1;
	}
	else{
		printf("False\n");
		return 0;
	}
}

//show function
void show(){
	if(head==-1 && tail==-1){
		printf("enable to  print\n");
	}
	else if(head==tail){
		printf("here is the vals:\n");
		printf("%d ",que[head]);
	}
	else if(tail>head){
		for (int temp=head;temp!=tail+1;temp++){
			printf("%d ",que[temp]);
		}
	}
	else if(head>tail){
		int temp=head,tempp=-20;
		while(tempp==tail+1){
			if(temp==len-1){
			temp=0;
			}
			printf("%d ",que[temp]);
			temp++;
			tempp=temp;
		}
		
	}
	printf("\n");
}



int main(){
	int want,val;
	printf("here is the list of operations\n");
	printf("press 0:exit\npress 1:enqueuefront\npress 2:delqueuefront\npress 3:peek\npess 4:isfull\npess 5:isempty\npress 6:display\npress 7:enqueueback\npress 8:dequeueback\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			enqueuefront();
		}
		else if(want==2){
			delqueuefront();
		}
		else if(want==3){
			peek();
		}
		else if(want==4){
			val=isfull();
		}
		else if(want==5){
			val=isempty();
		}
		else if(want==6){
			show();
		}
		else if(want==7){
			val=isspace();
		}
		else{
			printf("select only from given operations");
		}
		printf("select the operation\n");
		scanf("%d",&want);
	}
	return 0;
}
