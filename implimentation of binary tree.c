//implimentation of binary tree by Sharath arjun
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

//templete of each node in tree
struct node{
	int data;
	struct node *left ,*right;
};
struct node *root=0,*temp;

//function for creating the binary tree
void create(struct node *temp){
	struct node *present;
	if(root==0){
		int val;
		printf("enter val:");
		scanf("%d",&val);
		if(val!=-1){
			present=(struct node *)malloc(sizeof(struct node));
			root=present;
			present->left=present->right=0;
			present->data=val;
			create(present);
		}

	}
	else{
		int left_val,right_val;
		printf("enter the left value of %d:",temp->data);
		scanf("%d",&left_val);
		printf("enter the right value of %d:",temp->data);
		scanf("%d",&right_val);
		if(left_val!=-1){
			present=(struct node *)malloc(sizeof(struct node));
			temp->left=present;
			present->left=present->right=0;
			present->data=left_val;
			create(present);
		}
		if(right_val!=-1){
			present=(struct node *)malloc(sizeof(struct node));
			temp->right=present;
			present->left=present->right=0;
			present->data=right_val;
			create(present);
		}
	}
}


//function for the inorder traversal of binary tree
void inorder(struct node *present){
	if(present==0){
		printf("NO ELEMENT IS PRESENT!\n");
	}
	else{
		if(present->left!=0){
			inorder(present->left);
		}
		printf("%d ",present->data);
		if(present->right!=0){
			inorder(present->right);
		}
	}
}


//function for the postorder traversal
void postorder(struct node *present){
	if(present==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{	
		if(present->left!=0){
			postorder(present->left);
		}
		if(present->right!=0){
			postorder(present->right);
		}
		printf("%d ",present->data);
	}
}
//function for preorder traversal
void preorder(struct node *present){
	if(root==0){
		printf("NO ELEMENT IS PRESENT\n");
	}
	else{
		printf("%d ",present->data);
		if(present->left!=0){
			preorder(present->left);
		}
		if(present->right!=0){
			preorder(present->right);
		}
	}
}
//main function 
//deals with choosing the operation
void main(){
	int want;
	printf("here is the list of operation:\n");
	printf("press 1:create\npress 2:inoreder\npress 3:preorder\npress 4:postorder\npress 0:exit\n");
	scanf("%d",&want);
	while(want){
		switch (want){
			case 1:create(root);printf("binary tree created successfully\n");break;
			case 2:inorder(root);break;
			case 3:preorder(root);break;
			case 4:postorder(root);break;
			default :printf("we dont have any operation\n");
		}
		printf("\nselect operation:\n");
		scanf("%d",&want);
	}
}
