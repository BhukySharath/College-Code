//implimentation of binary tree

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
	
};
struct node *root;
//create function of binary tree
void create(struct node *temp,int val){
	int x,l,r;
	struct node *newnode,*tail1,*tail2; 
	if(root==0){
		printf("enter val for root:\n");
		scanf("%d",&x);
		if(x==-1){
			printf("done successfully\n");
		}
		else{
			newnode=(struct node *) malloc(sizeof(struct node));
			newnode->left=0;
			newnode->right=0;
			newnode->data=x;
			root=newnode;
			temp=newnode;
			create(temp,x);
		}
	}
	else{
		printf("enter left of %d\n",val);
		scanf("%d",&l);
		printf("enter right of %d\n",val);
		scanf("%d",&r);
		if(l!=-1){
			tail1=(struct node *) malloc(sizeof(struct node));
			tail1->left=tail1->right=0;
			temp->left=tail1;
			tail1->data=l;
			create(tail1,l);
		}
		if(r!=-1){
			tail2=(struct node *) malloc(sizeof(struct node));
			tail2->left=tail2->right=0;
			temp->right=tail2;
			tail2->data=r;
			create(tail2,r);
		}
		return;
	}
	printf("created successfully!\n");
}


//intranse function 
void intranse(struct node *temp){
	

}

//function for pretranse
void pretranse(struct node *temp){
	printf("%d ",temp->data);
	if(temp->left!=0){
		pretranse(temp->left);
	}
	if(temp->right!=0){
		pretranse(temp->right);
	}
	return ;
	
}

//function for post transe
void posttranse(struct node *temp){
	if(temp->left!=0){
		posttranse(temp->left);
	}
	if(temp->right!=0){
		posttranse(temp->right);
	}
	printf("%d ",temp->data);
	return ;
	
}

int main(){
	int val=0,want;
	struct node *temp=0;
	printf("press 0:exit\npress 1:create\npress 2:intranse\npress 3:pretranse\npress 4:posttranse\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create(temp,val);
		}
		else if(want==2){
			printf("here is the intranse val\n");
			intranse(root);
		}
		else if(want==3){
			printf("here is the pretranse val:\n");
			pretranse(root);
		}
		else if(want==4){
			printf("here is the posttranse val:\n");
			posttranse(root);
		}
		else{
			printf("we dont have any command\n");
		}
			
		printf("command:\n");
		scanf("%d",&want);
	}
	printf("thank you\n");
	return 0;
}
