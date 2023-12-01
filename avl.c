#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left,*right;
	int balfac;
};
struct node *root=0,*present,*temp,*temp1;
int lite;
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

//function for updating the balance factor
int  update_balancefactor(struct node *temp){
	int lcounter=0,rcounter=0;
	if(temp->right!=0){
		rcounter=update_balancefactor(temp->right)+1;
	}
	if(temp->left!=0){
		lcounter=update_balancefactor(temp->left)+1;
	}
	temp->balfac=lcounter-rcounter;
	printf("data:%d  balfac:%d\n",temp->data,temp->balfac);
	if(lcounter>=rcounter){
		return lcounter;
	}
	else{
		return rcounter;
	}
} 

//function for displaying inorder
void inorder(struct node *temp){
	if(temp->left!=0){
		inorder(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right!=0){
		inorder(temp->right);
	}
}
//function for displaying postorder
void postorder(struct node *temp){
	if(temp->left!=0){
		postorder(temp->left);
	}
	if(temp->right!=0){
		postorder(temp->right);
	}
	printf("%d ",temp->data);
}

//function for displaying preorder
void preorder(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		preorder(temp->left);
	}
	if(temp->right!=0){
		preorder(temp->right);
	}
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
	temp1=0;
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
//function for parent child location]
int flag(struct node *temp,struct node *parent){
	if(parent->data<temp->data){
		return 1;
	}
	else{
		return 0;
	}
}
//function for insert by reference
void insert_by_reference(struct node *present){
	struct node *temp1;
	if(present==0){
		return ;
	}
	else{
		struct node *temp=root;
		while(temp!=0){
			temp1=temp;
			if(temp->data>present->data){	
				temp=temp->right;
			}
			else{
				temp=temp->left;
			}
		}
		if(temp1->data<=present->data){
			temp1->right=present;
		}
		else{
			temp1->left=present;
		}
		
	}
}
//function for rotation
void rotation(struct node *temp){
	struct node *parent=parent_return(temp->data);
	struct node *temp1=0;
	if(parent!=0)
   		 printf("\nthe parent val is :%d is %d\n",temp->data,parent->data);
	if(temp->balfac<=-1 && (temp->right)->balfac<=-1){
		printf("\nin the condition\n");
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=temp->right;
			}
			else{
				parent->left=temp->right;
			}
		}
		insert_by_reference(temp->right->left);
		temp1=temp->right;
		printf("\nthe val in temp1:%d\n",temp1->data);
		temp->right->left=temp;
		temp->right=0;
	}
	else if(temp->balfac>=1 && (temp->left)->balfac>=1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=temp->left;
			}
			else{
				parent->left=temp->left;
			}			
		}
		insert_by_reference(temp->left->right);
		temp1=temp->left;
		(temp->left)->right=temp;
		temp->left=0;
	}
	else if(temp->balfac<=-1 && (temp->right)->balfac>=1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=(temp->right)->left;
			}
			else{
				parent->left=(temp->right)->left;
			}
		}
		insert_by_reference(temp->right->right);
		temp1=temp->right->left;
		((temp->right)->left)->left=temp;
		((temp->right)->left)->right=temp->right;
		temp->right=0;

	}
	else if(temp->balfac>=1 && (temp->left)->balfac<=
	-1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=(temp->left)->right;
			}
			else{
				parent->left=(temp->left)->right;
			}
		}
		insert_by_reference(temp->left->left);
		temp1=temp->left->right;
		((temp->left)->right)->left=temp->left;
		((temp->left)->right)->right=temp;
		temp->left=0;
	}
	if(temp==root){
		root=temp1;
		printf("the new root will be :%d ",root->right->data);
	}
	lite=update_balancefactor(root);
}

//function for the traversal
void traversal(struct node *temp){
	if(temp->left!=0){
		traversal(temp->left);
	}
	if(temp->right!=0){
		traversal(temp->right);
	}
	if(temp->balfac>1 || temp->balfac<-1){
		rotation(temp);
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
	lite=update_balancefactor(root);
	traversal(root);
	printf("insertion is done successfully\n");
}

//main function
void main(){
	int want,val;
	printf("here is the list of operation\n");
	printf("press 0:exit\npress 1:insert\npress 2:inorder\npress 3:delete\npress 4:postorder\npress 5:preorder\n");
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
				if(root==0){
					printf("NO ELEMENT IS PRESENT\n");
				}
				else{
					inorder(root);				
				}
				break;
			case 3:
				if(root==0){
					printf("NO ELEMENT IS PRESENT\n");
				}
				else{
					printf("enter val to delete:\n");
					scanf("%d",&val);
					del(val);
					up#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left,*right;
	int balfac;
};
struct node *root=0,*present,*temp,*temp1;
int lite;
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

//function for updating the balance factor
int  update_balancefactor(struct node *temp){
	int lcounter=0,rcounter=0;
	if(temp->right!=0){
		rcounter=update_balancefactor(temp->right)+1;
	}
	if(temp->left!=0){
		lcounter=update_balancefactor(temp->left)+1;
	}
	temp->balfac=lcounter-rcounter;
	printf("data:%d  balfac:%d\n",temp->data,temp->balfac);
	if(lcounter>=rcounter){
		return lcounter;
	}
	else{
		return rcounter;
	}
} 

//function for displaying inorder
void inorder(struct node *temp){
	if(temp->left!=0){
		inorder(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right!=0){
		inorder(temp->right);
	}
}
//function for displaying postorder
void postorder(struct node *temp){
	if(temp->left!=0){
		postorder(temp->left);
	}
	if(temp->right!=0){
		postorder(temp->right);
	}
	printf("%d ",temp->data);
}

//function for displaying preorder
void preorder(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		preorder(temp->left);
	}
	if(temp->right!=0){
		preorder(temp->right);
	}
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
	temp1=0;
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
//function for parent child location]
int flag(struct node *temp,struct node *parent){
	if(parent->data<temp->data){
		return 1;
	}
	else{
		return 0;
	}
}
//function for insert by reference
void insert_by_reference(struct node *present){
	struct node *temp1;
	if(present==0){
		return ;
	}
	else{
		struct node *temp=root;
		while(temp!=0){
			temp1=temp;
			if(temp->data>present->data){	
				temp=temp->right;
			}
			else{
				temp=temp->left;
			}
		}
		if(temp1->data<=present->data){
			temp1->right=present;
		}
		else{
			temp1->left=present;
		}
		
	}
}
//function for rotation
void rotation(struct node *temp){
	struct node *parent=parent_return(temp->data);
	struct node *temp1=0;
	if(parent!=0)
   		 printf("\nthe parent val is :%d is %d\n",temp->data,parent->data);
	if(temp->balfac<=-1 && (temp->right)->balfac<=-1){
		printf("\nin the condition\n");
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=temp->right;
			}
			else{
				parent->left=temp->right;
			}
		}
		insert_by_reference(temp->right->left);
		temp1=temp->right;
		printf("\nthe val in temp1:%d\n",temp1->data);
		temp->right->left=temp;
		temp->right=0;
	}
	else if(temp->balfac>=1 && (temp->left)->balfac>=1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=temp->left;
			}
			else{
				parent->left=temp->left;
			}			
		}
		insert_by_reference(temp->left->right);
		temp1=temp->left;
		(temp->left)->right=temp;
		temp->left=0;
	}
	else if(temp->balfac<=-1 && (temp->right)->balfac>=1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=(temp->right)->left;
			}
			else{
				parent->left=(temp->right)->left;
			}
		}
		insert_by_reference(temp->right->right);
		temp1=temp->right->left;
		((temp->right)->left)->left=temp;
		((temp->right)->left)->right=temp->right;
		temp->right=0;

	}
	else if(temp->balfac>=1 && (temp->left)->balfac<=
	-1){
		if(parent!=0){
			if(flag(temp,parent)==1){
				parent->right=(temp->left)->right;
			}
			else{
				parent->left=(temp->left)->right;
			}
		}
		insert_by_reference(temp->left->left);
		temp1=temp->left->right;
		((temp->left)->right)->left=temp->left;
		((temp->left)->right)->right=temp;
		temp->left=0;
	}
	if(temp==root){
		root=temp1;
		printf("the new root will be :%d ",root->right->data);
	}
	lite=update_balancefactor(root);
}

//function for the traversal
void traversal(struct node *temp){
	if(temp->left!=0){
		traversal(temp->left);
	}
	if(temp->right!=0){
		traversal(temp->right);
	}
	if(temp->balfac>1 || temp->balfac<-1){
		rotation(temp);
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
	lite=update_balancefactor(root);
	traversal(root);
	printf("insertion is done successfully\n");
}

//main function
void main(){
	int want,val;
	printf("here is the list of operation\n");
	printf("press 0:exit\npress 1:insert\npress 2:inorder\npress 3:delete\npress 4:postorder\npress 5:preorder\n");
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
				if(root==0){
					printf("NO ELEMENT IS PRESENT\n");
				}
				else{
					inorder(root);				
				}
				break;
			case 3:
				if(root==0){
					printf("NO ELEMENT IS PRESENT\n");
				}
				else{
					printf("enter val to delete:\n");
					scanf("%d",&val);
					del(val);
					update_balancefactor(root);				
				}
				break;
			case 4:
				if(root==0){
					printf("enable to treversal\n");
				}
				else{
					postorder(root);
				}
				break;
			case 5:
				if(root==0){
					printf("enable to treversal\n");
				}
				else{
					preorder(root);
				}
				break;				
			default:printf("we dont have any operation\n");	
		}
			printf("\nselect operation:\n");
			scanf("%d",&want);
	}
}date_balancefactor(root);				
				}
				break;
			case 4:
				if(root==0){
					printf("enable to treversal\n");
				}
				else{
					postorder(root);
				}
				break;
			case 5:
				if(root==0){
					printf("enable to treversal\n");
				}
				else{
					preorder(root);
				}
				break;				
			default:printf("we dont have any operation\n");	
		}
			printf("\nselect operation:\n");
			scanf("%d",&want);
	}
}
