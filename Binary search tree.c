#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left,*right;
};
struct node *root=0,*present,*temp,*temp1;

//function for geting location for inserting
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

//function for inserting
void insert(int val){
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

//function for displaying
void inorder(struct node *temp){
	if(temp->left!=0){
		inorder(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right!=0){
		inorder(temp->right);
	}
}
//function for displaying
void preorder(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		preorder(temp->left);
	}
	if(temp->right!=0){
		preorder(temp->right);
	}
}
//function for displaying
void postorder(struct node *temp){
	if(temp->left!=0){
		postorder(temp->left);
	}
	if(temp->right!=0){
		postorder(temp->right);
	}
	printf("%d ",temp->data);
}

//fuction for searching the element
struct node * search(int val){
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
//function for the inorder_predesor
void inorder_predessor(struct node *temp){
	if(temp->left!=0){
		inorder_predessor(temp->left);
	}
	temp1=temp;//inorder predessor will store
	if(temp->right!=0){
		inorder_predessor(temp->right);
	}
}
//function for parent return
struct node * parent_return(int val){
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
	return temp1;	
}
//function for deleting
void del(int val){
	int pval;
	struct node *present=search(val);
	struct node *parent=parent_return(val);
	if(present==0){
		printf("sorry it is not present in the tree\n");
	}
	else if(present->right!=0 && present->left!=0){
		inorder_predessor(present->left);
		pval=temp1->data;
		del(pval);
		present->data=pval;
	}
	else if(present->left==0 && present->right==0){
		if(parent->data>present->data){
			parent->left=0;
		}
		else{
			parent->right=0;
		}
	}
	else if(present->left==0){
		if(parent->data>present->data){
			parent->left=present->right;
		}
		else{
			parent->right=present->right;
		}
	}
	else if(present->right==0){
		if(parent->data>present->data){
			parent->left=present->left;
		}
		else{
			parent->right=present->left;
		}
	}
	
}

//main function
void main(){
	int want,val;
	printf("here is the list of operation\n");
	printf("press 0:exit\npress 1:insert\npress 2:inorder\npress 3:delete\npress 4:preorder\npress 5:postorder\n ");
	printf("select operation:\n");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				printf("enter the val:");
				scanf("%d",&val);
				insert(val);
				break;
			case 2:
				if(root!=0){
					inorder(root);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
			case 3:
				printf("enter val to delete:\n");
				scanf("%d",&val);
				del(val);
				break;
			case 4:
				if(root!=0){
					preorder(root);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
			case 5:
				if(root!=0){
					postorder(root);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
				
			default:printf("we dont have any operation\n");	
		}
			printf("\nselect operation:\n");
			scanf("%d",&want);
	}
}
