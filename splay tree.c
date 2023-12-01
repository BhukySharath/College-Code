#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=0,*global;
//function for inoder_predessor
void inorder_predessor(struct node *temp){
	if(temp->left!=0){
		inorder_predessor(temp->left);
	}
	global=temp;
	if(temp->right!=0){
		inorder_predessor(temp->right);
	}
}
//function for set_by_reference
void set_by_reference(struct node *present1,struct node *present){
	if(present==0){
		return ;
	}
	else{
		struct node *temp1;
		while(present1!=0){
			temp1=present1;
			if(present1->data < present->data){
				present1=present1->right;
			}
			else{
				present1=present1->left;
			}
		}
		if(temp1->data <present->data){
			temp1->right=present;
		}
		else{
			temp1->left=present;
		}
	}
}

//function for parent_return which return the parent address of given value
struct node * parent_return(int val){
	struct node *temp=root,*temp1=0;
	while(temp!=0){
		if(temp->data==val){
			break;
		}
		else if(temp->data >val){
			temp1=temp;
			temp=temp->left;
		}
		else{
			temp1=temp;
			temp=temp->right;
		}
	}
	if(temp==0){
		temp1=0;
	}
	return temp1;
}

//function for zig
struct node * zig(struct node *temp){
	struct node *temp1,*parent,*temp2;
	parent=parent_return(temp->data);
	if(parent!=0){
		parent->left=temp->left;
	}
	temp1=temp->left->right;
	temp->left->right=temp;
	temp2=temp->left;
	temp->left=0;
	set_by_reference(temp2,temp1);
	return temp2;
	
}

//function for zag
struct node *zag(struct node *temp){
	struct node *temp1,*parent,*temp2;
	parent=parent_return(temp->data);
	if(parent!=0){
		parent->right=temp->right;
	}
	temp1=temp->right->left;
	temp->right->left=temp;
	temp2=temp->right;
	temp->right=0;
	set_by_reference(temp2,temp1);
	
	return temp2;
}


//fucntion for splaying 
void splay(int val){
	struct node *neww,*parent,*grandp;
	if(root->data==val){
		return;
	}
	else if(root->left->data==val){
		root=zig(root);
	}
	else if(root->right->data == val){
		printf("here in the Zag 2\n");
		root=zag(root);
	
	}
	else{
		parent=parent_return(val);
		grandp=parent_return(parent->data);
		if(grandp->data > parent->data > val){
			neww=zig(grandp);
			if(grandp==root){
				root=neww;
			}
			splay(neww->data);
		}
		else if(grandp->data < parent->data <val){
			neww=zag(grandp);
			if(grandp==root){
				root=neww;
			}
			splay(neww->data);
		}
		else if(grandp->data > parent->data <val){
			neww=zag(parent);
			if(parent==root){
				root==neww;
			}
			splay(neww->data);
		}
		else if(grandp->data < parent->data >val){
			neww=zig(parent);
			if(parent==root){
				root==neww;
			}
			splay(neww->data);
		}	
	}
}
//function for insert
void insert(int val){
	struct node *present,*temp=0,*temp1=0;
	present=(struct node *)malloc(sizeof(struct node));
	present->data=val;
	present->right=present->left=0;
	if(root==0){
		root=present;
	}
	else{
		temp=root;
		while(temp!=0){
			temp1=temp;
			if(temp->data > present->data){
				temp=temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		if(temp1->data > present->data){
			temp1->left=present;
		}
		else{
			temp1->right=present;
		}
	}
	splay(val);
}
//function for inorder
void inorder(struct node *temp){
	if(temp->left!=0){
		inorder(temp->left);
	}
	printf("%d ",temp->data);
	if(temp->right!=0){
		inorder(temp->right);
	}
}

//function for preorder
void preorder(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		preorder(temp->left);
	}
	if(temp->right!=0){
		preorder(temp->right);
	}
}
//function for postorder
void postorder(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		postorder(temp->left);
	}
	if(temp->right!=0){
		postorder(temp->right);
	}
}

//function for search
struct node * search(int val){
	struct node *temp;
	while(temp!=0){
		if(temp->data == val){
			break;
		}
		else if(temp->data <val){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	return temp;
}

//function for deletion
void del(val){
	int p;
	struct node *parent,*temp=search(val);
	if(temp==0){
		printf("NO ELEMET IS FOUNDED\n");
	}
	else{
		splay(temp->data);
	}
	if(root->left!=0 && root->right!=0){
		inorder_predessor(root->left);
		p=global->data;
		parent=parent_return(p);
		if(parent->data > p){
			parent->left=0;
		}
		else{
			parent->right=0;
		}
	}
	else if(root->left==0){
		root=root->right;
	}
	else if(root->right==0){
		root=root->left;
	}
	else{
		free(root);
	}
}
void main(){
	int want,val;
	struct node *temp;
	printf("press 1:insert\npress 2:inorder\npress 3:delete\npress 4:search\npress 5:preorder\npress 6:postorder\nselect operatation\n");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				printf("enter val:\n");
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
				printf("enter val:");
				scanf("%d",&val);
				del(val);
				break;
			case 4:
				if(root!=0){
					printf("enter val:\n");
					scanf("%d",&val);
					temp=search(val);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
			case 5:
				if(root!=0){
					preorder(root);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
			case 6:
				if(root!=0){
					postorder(root);
				}
				else{
					printf("NO ELEMENT IS PRESENT\n");
				}
				break;
			default:printf("we dont have such kind of operation\n");
			
		}
		printf("\nselect operation\n");
		scanf("%d",&want);
	}
}
