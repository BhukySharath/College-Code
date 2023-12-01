
#include<stdio.h>
#define n 5
int a[n];
int endprev=n-1;
//function for creating array
void create(){
	for(int i=0;i<n;i++){
		printf("enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("array created successfully\n");
}


//function for displaying
void disp(){
	printf("here is the list of values\n");
	for(int i=0;i<n;i++){
		printf("a[%d]=%d\n",i,a[i]);
	}
}

//function for quicksort1--starting index is pivot
void sort1(int start,int end,int start1,int end1){
	int temp,pivot=a[start];
	int initial=start;
	while(end>start){
		while(a[start]<=pivot){
			start++;
			
		}
		while(a[end]>pivot){
			end--;
		}
		if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}	
	}
	temp=a[end];
	a[end]=a[initial];
	a[initial]=temp;
	start=0,end=end-1;
	start1=end+2,end1=endprev;
	endprev=end;
	if(start<end){
		sort1(start,end,start1,end1);
	}
	if(start1<end1){
		sort1(start1,end1,-1,-1);
	}
	return;
}

//main function
int main(){
	int want,val;
	printf("press 0:exit\npress 1:create\npress 2:display\npress 3:sort\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create();
		}
		else if(want==2){
			disp();
		}
		else if(want==3){
			sort1(0,n-1,-1,-1);
			endprev=n-1;
			printf("done sucessfullt=y\n");
		}
	
	printf("select operation\n");
	scanf("%d",&want);
	}
}
