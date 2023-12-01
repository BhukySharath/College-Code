//singly circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=0,*tail=0,*present,*temp;
int len=0;
void create(){
	head=0,tail=0;
	int val;
	printf("enter the no of element:\n");
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		printf("enter element:\n");
		scanf("%d",&val);
		present=(struct node*)malloc(sizeof(struct node));
		(*present).data=val;
		(*present).next=0;
		if(head==0){
			head=present;
		}
		else{
			temp->next=present;
		}
		temp=present;
	}
	tail=present;
	present->next=head;
	printf("linked list is created succesfully\n");
}

//function for display
void disp(){
	present=head;
	temp=0;
	if(head==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{
		printf("here is the linked list element\n");
		while(temp!=tail){
			printf("%d ",present->data);
			temp=present;
			present=present->next;
		}
	}
	
}
void insert(){
	int pos,val;
	printf("enter val:\n");
	scanf("%d",&val);
	printf("enter pos:\n");
	scanf("%d",&pos);
	if(pos<0 || pos>len+1){
		printf("unable insert at %d",pos);
	}
	else {
		present=(struct node *)malloc(sizeof(struct node));
		present->data=val;
		present->next=0;
		if(pos==1 && head==0){
			head=tail=present;
			present->data=val;
			present->next=head;
		}
		if(pos==1){
			present->next=head;
			tail->next=present;
			head=present;
		}
		else if(pos==len+1){
			tail->next=present;
			tail=present;
			tail->next=head;
		}
		else{
			temp=head;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			present->next=temp->next;
			temp->next=present;
		}
		printf("insertion done succesfully\n");	
		len++;
	}
}

//function for the deletion
void del(){
	int pos;
	printf("enter the positon of element to delete\n");
	scanf("%d",&pos);
	if(head==0){
		printf("NO ELEMENT IS PRESENT\n");	
	}
	else if(pos<0 || pos>len){
		printf("DELETION IS NOT POSSIBLE\n");
	}
	else{
		if(pos==1){
			if(len==1){
				head=0;
			}
			else{
				head=head->next;
				tail->next=head;
			}
		}
		else if(pos==len){
			temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			temp->next=head;
			
		}
		else{
			temp=head;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			temp->next=(temp->next)->next;
		}
		len--;
		printf("deletion operation isdone succesuflly\n");
	}
}
void reverse(){
	struct node *present=head,*after=0,*pre=0;
	if(head==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{
		while(pre!=tail){
			after=present->next;
			present->next=pre;
			pre=present;
			present=after;
		}
		head->next=tail;
		present=head;
		head=tail;
		tail=present;
	}

}
int main(){
	int want;
	printf("select operatation\n");
	printf("press 0:exit\npress 1:create\npress 2:display\npress 3:insert\npress 4:delete\npress 5:reverse\n");
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
			reverse();
		}
		else{
			printf("we dont have any option such\n");
		}
		
		printf("\nselect operation\n");
		scanf("%d",&want);
	}
	return 0;
}
