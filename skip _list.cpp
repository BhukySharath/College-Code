//implimentation of skiplist
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right,*up,*down;
};
struct node *heads[10],*tails[10],*present,*prev;
int len=0,level=-1;

//function for promoting the elements
void promote(int i){
	level++;
	int count=0;
	struct node *temp;
	temp=heads[i-1];
	int decision;
	while(temp!=0){
		printf("DO YOU WANT TO PROMOTE:%d\n",temp->data);
		present=(struct node *)malloc(sizeof(struct node));
		present->left=present->right=present->up=present->up=0;
		present->data=temp->data;
		scanf("%d",&decision);
		if(decision==1){
			count++;
			if(heads[i]==0){
				heads[i]=present;
				
			}	
			else{
				prev->right=present;
			}
			present->down=temp;
			prev=present;
		
		}
		temp=temp->right;
		
	}
	tails[i]=present;
	if(count!=0){
		promote(i+1);
	}
	else{
		printf("skip list created successfully\n");
	}
}

//function for creating linked list
void create(){
	int val;
	printf("enter the len:\n");
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		printf("enter val:\n");
		scanf("%d",&val);
		present=(struct node *)malloc(sizeof(struct node));
		present->left=present->right=present->up=present->down=0;
		present->data=val;
		if(heads[0]==0){
			heads[0]=present;
		}
		else{
			prev->right=present;
		}
		prev=present;
	}
	tails[0]=present;
	promote(1);
}
void disp(){
	struct node *temp;
	temp=heads[0];
	if(temp==0){
		printf("no element is present\n");
	}
	else{
		while(temp!=0){
			printf("%d ",temp->data);
			temp=temp->right;
		}
	}
	
}

//function for insert
void insert(){
	int val,lev=level,flag=0;
	struct node *temp=heads[lev],*temp1;
	printf("enter val to insert:\n");
	scanf("%d",&val);
	if(heads[0]==0){
		printf("no element is present \n");
		return;
	}
	while(lev!=-1){
		temp1=temp;
		if(flag==0){
			if((temp->data)>val){
				lev--;
				temp=heads[lev];
			}
			else{
				flag=1;
			}
		}
		else{
			if(temp->right==0){
				temp=temp->down;
				lev--;
			}
			else{
				if((temp->right)->data>val){
					temp=temp->down;
					lev--;
				}
				else{
					temp=temp->right;
				}
				
			}
			
		}
	
	}
	temp=temp1;
	printf("processing........\n");
	present=(struct node *)malloc(sizeof(struct node));
	present->left=present->down=present->right=present->up=0;
	present->data=val;
	if(temp==heads[0]){
		present->right=temp;
		heads[0]=present;
	}
	else if(temp->right==0){
		temp->right=present;
		tails[0]=present;
	}
	else{
		present->right=temp->right;
		temp->right=present;
	}
	printf("insertion is node successfully\n");
	
}
//function for search
void search(){
	int val,lev=level,flag=0;
	struct node *temp=heads[lev],*temp1;
	printf("enter val to insert:\n");
	scanf("%d",&val);
	while(lev!=-1){
		temp1=temp;
		if(flag==0){
			if((temp->data)>val){
				lev--;
				temp=heads[lev];
			}
			else{
				flag=1;
			}
		}
		else{
			if(temp->right==0){
				temp=temp->down;
				lev--;
			}
			else{
				if((temp->right)->data>val){
					temp=temp->down;
					lev--;
				}
				else{
					temp=temp->right;
				}
				
			}
			
		}
	
	}
	if(temp1->data==val){
		printf("element is founded \n");
	}
	else{
		printf("value doesnt mached in the skiplist\n");
	}
}
int main(){
	int want;
	printf("press 0:exit\npress 1:create\npress 2:disp\npress 3:insert\press 4:search\n");
	printf("select operation:\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create();
		}
		else if(want==2){
			disp();
		}
		else if(want==3){
			insert();
		}
		else if(want==4){
			search();
		}
		else{
			printf("we dont have any opertion\n");
		}
		printf("select operation:\n");
		scanf("%d",&want);
	}
	printf("bye\n");
	return 0;
}
