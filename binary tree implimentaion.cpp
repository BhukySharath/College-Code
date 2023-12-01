#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};
struct node *head=0;



//function for creating head
struct node * head_create(struct node *present){
	int val;
	printf("enter head:");
	scanf("%d",&val);
	present=head=(struct node *)malloc(sizeof(struct node));
	(*present).data=val;
	return present;
}


//function for creating the tree
void create(struct node *present){
	int l,r;
	struct node *lefter,*righter;
	if(present==0){
		present=head_create(present);
	}
	(*present).left=(*present).right=0;
	printf("enter left val of %d:",(*present).data);
	scanf("%d",&l);
	printf("enter right val of %d:",(*present).data);
	scanf("%d",&r);
	if(l!=-1){
		lefter=(struct node *)malloc(sizeof(struct node));
		(*lefter).data=l;
		present->left=lefter;
		create(lefter);
	}
	if(r!=-1){
		righter=(struct node *)malloc(sizeof(struct node));
		(*righter).data=r;
		present->right=righter;
		create(righter);
	}
	
}

//function for the postorder traversal
void postorder(struct node *present){
	if(head==0){
		printf("tree hasn't been created yet\n");
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

void inorder(struct node *present){
	if(head==0){
		printf("tree hasent created yet\n");
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
void preorder(struct node *present){
	if(head==0){
		printf("tree hasnt been created yet\n");
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


int main(){
	int want,val;
	printf("select operation\n");
	printf("press 0:exit\npress 1:create\npress 3:postorder\npress 4:preorder\npress 2:inorder\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create(head);
		}
		else if(want==2){
			inorder(head);
		}
		else if(want==3){
			postorder(head);
		}
		else if(want==4){
			preorder(head);
		}
		else{
			printf("we dont have any operation\n");
		}
		printf("select operation\n");
		scanf("%d",&want);
	}
}
