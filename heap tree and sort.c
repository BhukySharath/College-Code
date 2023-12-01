#include<stdio.h>
#include<stdlib.h>
int a[100];
int len=-1;
void hepify_from_bottom(){
	int c=len;
	int p=(c-1)/2;
	int temp;
	while(a[p]<=a[c] && c>0){
		temp=a[p];
		a[p]=a[c];
		a[c]=temp;
		c=p;
		p=(c-1)/2;
	}
	
}
void insert(){
	int val;
	printf("Enter val:");
	scanf("%d",&val);
	len++;
	a[len]=val;
	hepify_from_bottom();
}
void heapify_from_top(int len){
	int p=0;
	int left=2*p+1;
	int right=2*p+2;
	int temp;
	while(left<=len || right<=len){
		if(right<=len){
			if(a[p]<=a[left] && a[left]>=a[right]){
				temp=a[left];
				a[left]=a[p];
				a[p]=temp;
				p=left;
			}
			else if(a[p]<=a[right] && a[left]<=a[right]){
				temp=a[right];
				a[right]=a[p];
				a[p]=temp;
				p=right;
			}
			else{
				break;
			}
		}
		else if(left<=right){
			if(a[left]>=a[p]){
				temp=a[left];
				a[left]=a[p];
				a[p]=temp;
				p=left;
			}
			else{
				break;
			}
		}
		left=2*p+1;
		right=2*p+2;
	}

}
void del(){
	printf("Deleted element is:%d\n",a[0]);
	a[0]=a[len];
	len--;
	heapify_from_top(len);
}
void sort(){
	int i,temp;
	for(i=0;i<len;i++){
		temp=a[0];
		a[0]=a[len-i];
		a[len-i]=temp;
		heapify_from_top(len-i-1);
	}
	printf("Sorted heap :\n");
	display();
	printf("\nBYE");
	exit(0);

}
void display(){
	int i=0;
	for(i=0;i<=len;i++){
		printf("%d ",a[i]);
	}
}
void main(){
	int want;
	printf("press 1:insert\npress 2:delete\npress 3:sort\npress 4:display\n");
	printf("NOTE :AFTER SORT YOUR ENABLE TO PERFROM OTHER OPERATION:\n");
	printf("Select operation:\n");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				sort();
				break;
			case 4:
				display();
				break;
			default:
				printf("we dont have any operation\n");
		}
		printf("\nSelect operation:\n");
		scanf("%d",&want);
	}
}
