//singlel linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
struct node *head=0,*tail=0,*temp,*present,*prev, *nextter=0;
int length=0;
//create function
void create(){
//	head=0,tail=0;
	int val;
	printf("How many elements:\n");
	scanf("%d",&length);
	for(int i=0;i<length;i++){
		present=(struct node *)malloc(sizeof(struct node));
		tail=present;
		printf("enter element:\n");
		scanf("%d",&val);
		if(head==0){
			head=present;
		}
		else{
			prev->next=present;
		}
		present->data=val;
		present->next=0;
		prev=present;
	}
	printf("the linked list is created successfully\n");
}
//function for disp
void disp(){
	if(head==0 || length==0){
		printf("No element is present\n");
	}
	else{
		temp=head;
		printf("here is the linked list element\n");
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
//function for insert
void insert(){
	int pos,i,val;
	printf("enter pos:\n");
	scanf("%d",&pos);
	if(pos>length+1||pos<=0){
		printf("insertion is not possible\n");
	}
	else{
		printf("enter the val:\n");
		scanf("%d",&val);
		temp=head;
		present=(struct node *)malloc(sizeof(struct node ));
		present->data=val;
		present->next=0;
		if(pos==1){
			present->next=head;
			head=present;
		}
		else if(pos==length+1){
			tail->next=present;
			tail=present;
		}
		else{
			for(i=1;i<pos-1;i++){
				temp=temp->next;
			}
			present->next=temp->next;
			temp->next=present;
		}
		length++;
		printf("inserted successfully\n");
	}
}
//function for deletion
void del(){
	int pos,i;
	printf("enter the pos:\n");
	scanf("%d",&pos);
	if(pos>length ||pos<=0||head==0){
		printf("deletion is not possible\n");
	}
	else{
		temp=head;
		if(pos==1){
			head=temp->next;
		}
		else if(pos==length){
			while(temp->next!=tail){
				temp=temp->next;
			}
			present=temp;
			temp=temp->next;
			present->next=0;
			tail=present;
		}
		else{
			for(i=1;i<pos-1;i++){
				temp=temp->next;
			}
			present=temp;
			temp=present->next;
			present->next=temp->next;
		}
		free(temp);
		length--;
		printf("deleted successfully\n");
	}
}

//function for sorting(bobble sort algorithm)
void sort(){
	int i,k;
	struct node *temp1=0;
	if(head==0 ||length==0){
		printf("no element there\n");
	}
	else{
		for(i=1;i<=length-1;i++){
			temp=head;
			while(temp!=tail){
				temp1=temp->next;
				if((temp->data)>=(temp1->data)){
					k=temp1->data;
					temp1->data=temp->data;
					temp->data=k;
				}
				temp=temp1;
			}
		}
		printf("sorted succesfully\n");
	}
}

//function for reversing the linked list
void reverse(){
	if(head==0 ||length==0){
		printf("linked list is empty\n");
	}
	else if((head->next)->next==0){
		temp=head;
		present=temp->next;
		present->next=temp;
		temp->next=0;
		head=tail;
		tail=temp;	
		printf("reversing the linked list is completed\n");
	}
	else if(head==tail){
		printf("reversing the linked list is completed\n");
	}
	else{
		prev=head;
		present=head->next;
		nextter=present->next;
		prev->next=0;
		while(present!=tail){
			present->next=prev;
			prev=present;
			present=nextter;
			nextter=nextter->next;
		}
		present->next=prev;
		tail=head;
		head=present;
		printf("reversing the linked list is completed\n");
	}
}
int main(){
	int want;
	printf("here is the list of operation\n");
	printf("press 1:create\npress 2:disp\npress 3:insert\npress 4:delete\npress 5:sort\npress 6:length\npress 7:reverse\npress 0:exit\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create();
		}
		else if(want==2){
			disp();
		}
		else if(want==3){
			insert();
		}
		else if(want==4){
			del();
		}
		else if(want==5){
			sort();
		}
		else if(want==6){
			printf("the length of linked list is:%d",length);
		}
		else if(want==7){
			reverse();
			printf("%d ",tail);
		}
		else{
			printf("we dont have any operatio\n");
		}
		printf("\nselect operation\n");
		scanf("%d",&want);
	}
	printf("Bye!");
	return 0;
}
