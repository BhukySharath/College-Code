#include<stdio.h>
#include<stdlib.h>
#define n 5
int a[n];
void SelectionSort(){
	int i,j,max,at;
	for(i=0;i<n;i++){
		max=a[i];
		for(j=i;j<n;j++){
			if(max<=a[j]){
				max=a[j];
				at=j;
			}
		}
		max=a[i]; //max used as temporary variable
		a[i]=a[at];
		a[at]=max;                           
		
	}
}
void display(){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}	
}
void main(){
	int i;
	for(i=0;i<n;i++){
		printf("Enter element:");
		scanf("%d",&a[i]);
	}
	SelectionSort();
	display();
}
