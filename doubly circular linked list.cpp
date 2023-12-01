//implimentation of doubly circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *newnode,*head=0,*tail=0,*temp,*temp1,*temp2,*current,*tempr;
int decision=1,len=0,val;

//create alinked list
void create(){
	while(decision){
	    len++;
		newnode=(struct node *) malloc(sizeof(struct node));
		newnode->prev=0;
		newnode->next=0;
		printf("enter the val:\n");
		scanf("%d",&val);
		newnode->data=val;
		if(head==0){
			temp1=newnode;
			head=newnode;
		}
		else{
			temp1->next=newnode;
			newnode->prev=temp1;
			temp1=newnode;
		}
		printf("Do you want to store (0,other)?\n");
		scanf("%d",&decision);
    }
    temp=head;
    temp->prev=temp1;
    temp1->next=temp;
    tail=temp1;
    printf("your data stored successfully!\n");
    decision=1;
    printf("linked list creted successfully!\n");
}


//function to display linked list
void show(){
	printf("\n here is the list:\n");
	temp=head;
	temp1=0;
	while(temp1!=tail){
		printf("%d   ",temp->data);
		temp1=temp;
		temp=temp->next;
	}
	printf("\n");
	decision=1;
}

//insertion at begin
void insert_at_begin(){
	int val;
	printf("enter the val:\n");
	scanf("%d",&val);
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=head;
	newnode->prev=tail;
	head=newnode;
	printf("inserted successfully!\n");
}

//insertion at pos
void insert_at_pos(){
	int i=1,pos;
	printf("enter the position:\n");
	scanf("%d",&pos);
	temp1=head;
	while(i<pos){
		temp1=temp1->next;
		i++;
	}
	temp2=temp1->next;
	printf("enter the val:\n");
	scanf("%d",&val);
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=val;
	newnode->prev=temp1;
	newnode->next=temp2;
	temp1->next=newnode;
	temp2->prev=newnode;
	printf("inserted successfully!\n");
}

//insertion at end
void insert_at_end(){
	int val;
	printf("enter the val:\n");
	scanf("%d",&val);
	newnode=(struct node *) malloc(sizeof(struct node));
	newnode->data=val;
	newnode->prev=tail;
	newnode->next=head;
	tail->next=newnode;
	head->prev=newnode;
	tail=newnode;
	printf("inserted successfully!\n");
}

//deletion at begin
void del_at_begin(){
	temp=head;
	temp2=temp->next;
	temp1=temp->prev;
	temp2->prev=temp1;
	temp1->next=temp2;
	head=temp2;
	free(temp);
	printf("deleted sucessfully!\n");
}

//deleting at pos
void del_at_pos(){
	int i=1,pos;
	printf("enter the position;\n");
	scanf("%d",&pos);
	temp=head;
	while(i<pos){
		temp=temp->next;
	}
	temp1=temp->prev;
	temp2=temp->next;
	temp1->next=temp2;
	temp2->prev=temp1;
	free(temp);
	printf("deleted sucessfully!\n");
}

//deleting at end
void del_at_end(){
	temp=tail;
	temp1=temp->prev;
	temp2=temp->next;
	temp1->next=head;
	temp2->prev=temp1;
	tail=temp1;
	free(temp);
	printf("deleted sucessfully!\n");
}

//reversing the linked list
void reverse(){
	 temp1=tail;
	 temp=head;
	 temp2=temp->next;
	 while(temp1->prev!=head){
	 	temp->prev=temp2;
	 	temp->next=temp1;
	 	temp1=temp;
	 	temp=temp2;
	 	temp2=temp->next;
	 }
	 tempr=head;
	 head=tail;
	 tail=tempr;
	 printf("reversed successfully!\n");
}
int main(){
	int want;
	printf("here is the list of operations:\n");
	printf("press 0:to stop\npress 1:create\npress 2: display\npess 3:insert at begin\npress 4:insert at pos\npress 5:insert at end\npress 7:delete at begin\npress 8:delete at pos\npress 9:delete at end\npress 10:reverse");
    scanf("%d",&want);
    while(want)
    {
    	if(want==1){
			create();	
    	}
    	else if(want==2){	
			show();	
		}
		else if(want==3){
			insert_at_begin();	
		}
		else if(want==4){
			insert_at_pos();
		}
		else if(want==5){
			insert_at_end();
		}
		else if(want==7){
			del_at_begin();
		}
		else if(want==8){
			del_at_pos();
		}
		else if(want==9){
			del_at_end();
		}
		else if(want==10){
			reverse();
		}
		else{
			printf("no option available!\n");
		}
		//printf("press 0:to stop\npress 1:create\npress 2: display\npess 3:insert at begin\npress 4:insert at pos\npress 5:insert at end\npress 6:insert at end\npress 7:delete at begin\npress 8:delete at pos\npress 9:delete at end\npress 10:reverse");
    	printf("enter operation\n");
		scanf("%d",&want);
	}
	return 0;
}
