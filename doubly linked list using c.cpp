//doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
	struct node *pre;
};
struct node *head=0,*tail=0,*temp,*present,*prev, *nextter=0;
int n=5;
//create function
void create(int A[]){
	int val;
	head=tail=0;

	for(int i=0;i<n;i++){
		present=(struct node *)malloc(sizeof(struct node));
		present->data=A[i];
		present->next=present->pre=0;
		if(head==0){
			head=present;
		}
		else{
			present->pre=prev;
			prev->next=present;
		}
		prev=present;
		
	}
	tail=present;
}
//function for disp
void disp(){
	if(head==0){
		printf("No element is present\n");
	}
	else{
		temp=head;
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
//function for insert
void insert(){
	int pos,val=56;
	printf("\nenter pos for insertion:\n");
	scanf("%d",&pos);
	present=(struct node *)malloc(sizeof(struct node));
	present->data=val;
	present->next=present->pre=0;
	if(pos<=0 || pos>n+1){
		printf("\ninsertion is not possible\n");
		free(present);
	}
	else if(pos==1 && head==0){
		tail=head=present;
		n++;
	}
	else if(pos==1){
		present->next=head;
		head=present;
		n++;
	
	}
	else if(pos==n+1){
		tail->next=present;
		present->pre=tail;
		tail=present;
		n++;
	
	}
	else{
		temp=head;
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
		}
		present->pre=temp;
		present->next=temp->next;
		(temp->next)->pre=present;
		temp->next=present;
		n++;
	}
	
}
//function for deletion
void del(){
	int pos;
	printf("\nenter the pos deletion:\n");
	scanf("%d",&pos);
	if(pos<=0 || pos>n || head==0){
		printf("\ndeletion is not possible\n");
		pos=-1;
	}
	else if(pos==1){
		temp=head->next;
		temp->pre=0;
		free(head);
		head=temp;
	}
	else if(pos==n){
		temp=tail;
		tail=tail->pre;
		tail->next=0;
		free(temp);
	}
	else{
		temp=head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		(temp->pre)->next=temp->next;
		(temp->next)->pre=temp->pre;
		free(temp);
	}
	if(pos!=-1){
		n--;

		
	}

}
//function for reversing the linked list
void reverse(){
	if(head==0){
		printf("\nNo element is present\n");
	}
	else{
		temp=head;
		while(temp!=0){
			present=temp;
			temp=temp->next;
			//prev is used for swapping 
			prev=present->next;
			present->next=present->pre;
			present->pre=prev;
		}	
		temp=head;
		head=tail;
		tail=temp;
	}

}
int main(){
    int A[]={1,23,12,8,45};
    create(A);
    insert();
    disp();
    del();
    disp();
    reverse();
    printf("\n");
    disp();
}
