#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};
struct node *root=0;

//create function of binary search tree
void create(struct node *temp){
	struct node * temp1;
	int val=0;
	while(val!=-1){
		printf("enter val:\n");
		scanf("%d",&val);
		if(temp==0){
			temp=(struct node*)malloc(sizeof(struct node));
			root=temp;
		}
		else{
			temp=root;
			while(1){
	 			if(val>temp->data){
	 				if(temp->right==0){
	 					temp1=(struct node *)malloc(sizeof(struct node));
	 					temp->right=temp1;
	 					temp=temp1;
	 					break;
					}
					else{
						temp=temp->right;
					}
				}
				else if(val<temp->data){
					if(temp->left==0){
						temp1=(struct node *)malloc(sizeof(struct node));
						temp->left=temp1;
						temp=temp1;
						break;
					}
				    else{
						temp=temp->left;
					}	
				}
				else{
					printf("Should not be equal!!\n");
				}	
			}
		}
		temp->left=temp->right=0;
		temp->data=val;	
	}
printf("created sucessfully!\n");
}

//function for inoreder
void inorder(struct node * temp){
	if(temp->left!=0){
		inorder(temp->left);
	}
	if(temp->left->left==0 && temp->left->right==0){
		printf("%d ",temp->data);
	}
	if(temp->right!=0){
		inorder(temp->right);
		
	}
	printf("%d ",temp->data);
	return;
}

//delete function
void del(struct node *temp){

	int val,c=0,max=0,flag=0;
	struct node *parent=0,*temp1;
	printf("enter val to delete:\n");
	scanf("%d",&val); 
	while(temp!=0){
		if(temp->data==val){
			printf("%d founded in tree.......",val);
			int flag=1;
			break;
		}
		else if(temp->data<val){
			parent=temp;
			c=1;
			temp=temp->right;
		}
		else if(temp->data>val){
			parent=temp;
			temp=temp->left;
			c=-1;
		}
		
	}
if(flag==1){
	printf("%d is not founded\n",val);
}
else{
	if(temp->right==0 && temp->left==0){
		if(c==-1){
			parent->left=0;
		}
		else{
			parent->right=0;
		}
		printf("deleted successfully!\n");
	}
	else if(temp->right==0 && temp->left!=0){	
		if(c==-1){
			parent->left=temp->left;
		}
		else{
			parent->right=temp->left;
		}
		printf("deleted sucessfully\n");
	}		
	else if(temp->left==0 && temp->right!=0){
		if(c==-1){
			parent->left=temp->right;
			
		}
		else{
			parent->right=temp->right;
		}
		printf("deleted sucessfully\n");
	}	
	else{
		max=temp->left->data;
		temp1=temp->left;
		while(temp1->right!=0){
			max=temp1->data;
			temp1=temp1->right;
		}
		temp->data=temp1->data;
		del(temp1);
		printf("deleted sucessfully using recursion\n");
	}	
	
}
}
//main function

int main(){

	int val,operation_select;
	printf("Here is the list of operations\n");
	printf("press 1:create binary search tree (BST)\npress 2:Inorder\npress 3:delete\npress 0:exit");
	scanf("%d",&operation_select);
	while(operation_select){
		if(operation_select==1){
			printf("NOTE:Press -1 for stop the inserting val!");
			create(root);
		}
		else if(operation_select==2){
			inorder(root);
		}
		else if(operation_select==3){
			del(root);
		}
		else{
			printf("we dont have any operations\n");
		}
		printf("select operation:\n");
		scanf("%d",&operation_select);
	}
return 0;
}
