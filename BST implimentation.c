#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left,*right;
};
struct node *root=0,*present,*temp,*temp1;
void get_location(struct node *temp,int val){
	temp1=temp;
	if(temp->data<=val){
		temp=temp->right;
	}
	else{
		temp=temp->left;
	}
	if(temp!=0){
		get_location(temp,val);
	}
}

void insert(){
	int val;
	printf("enter the val:");
	scanf("%d",&val);
	present=(struct node *)malloc(sizeof(struct node));
	present->data=val;
	present->left=present->right=0;
	if(root==0){
		root=present;
	}
	else{
		get_location(root,val);
		if(temp1->data<=val){
			temp1->right=present;
		}
		else{
			temp1->left=present;
		}
	}
	printf("insertion is done successfully\n");
}

void disp(struct node *temp){
	if(temp->left!=0){
		disp(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right!=0){
		disp(temp->right);
	}
}

struct node * search(struct node *temp){
	int val;
	printf("enter the val to search\n");
	scanf("%d",&val);
	temp=root;
	while(temp!=0){
		if(temp->data==val){
			break;
		}
		else if(temp->data>val){
			temp=temp->left;
		}
		else {
			temp=temp->right;		
		}
	}
	return temp;
}
void inorder_predessor(struct node *temp){
	if(temp->left!=0){
		inorder_predessor(temp->left);
	}
	//inorder predessor will store
	if(temp->right!=0){
		inorder_predessor(temp->right);
	}
}
struct node * parent(int val){
	temp=root;
	while(temp!=0){
		if(temp->data==val){
				break;
		}
		else if(temp->data>val){
			temp1=temp;
			temp=temp->left;
		}
		else {
			temp1=temp;
			temp=temp->right;
		}
	}
	return temp;
}
void del(int val){
	temp=parent(val);
	printf("in the temp %d",temp->data);
	printf("in the temp1 %d",temp1->data);
	if(temp==0){
		printf("NO ELEMENT PRESENT\n");
	}
	else if(temp->left==0 && temp->right==0){//deleting of node with no children
		if(temp1->data<temp->data){
			temp1->right=0;
		}
		else{
			temp1->left=0;
		}
	}
	else if(temp->right==0){//deleting of node with no right children
		if(temp1->data<temp->data){
			temp1->right=temp->right;
		}
		else{
			temp1->left=temp->right;
		}		
	}
	else if(temp->left==0){//deleting of node with no left children
		if(temp1->data<temp->data){
			temp1->right=temp->left;
		}
		else{
			temp1->left=temp->left;
		}		
	}
	else if(temp->left!=0 && temp->right!=0){//deleting node having to children
		inorder_predessor(temp->left);	
		parent(present->data);//to find the parent node of inoder_predssor element and search function stores inthe temp1
		temp->data=present->data;
		if(present->data>temp1->data){
			temp1->right=0;
		}
		else{
			temp1->left=0;
		}
	}
	printf("deleted succsfully\n");
}
void main(){
	int want,val;
	struct node *temp;
	printf("here is the list of operation\n");
	printf("press 0:exit\npress 1:insert\npress 2:show\n");
	printf("select operation:\n");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:insert();break;
			case 2:disp(root);break;
			case 3:
				temp=search(root);
				if(temp==0){
					printf("NOT FOUNDED\n");
				}
				else{
					printf("FOUNDED\n");
				}
				break;
			case 4:
				printf("enter the element for the delete\n");
				scanf("%d",&val);
				del(val);
				break;
			default:printf("we dont have any operation\n");	
		}
			printf("\nselect operation:\n");
			scanf("%d",&want);
	}
}
