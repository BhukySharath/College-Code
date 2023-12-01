//quick sort
#include<stdio.h>
#include<stdlib.h>
#define n 7
int a[7];
void quicksort(int f,int l){
	int pivot,temp,i=f,j=l;
	if(f>l){
		return;
	}
	while(i<=j){
		while(a[pivot] >= a[i]  && i<=j){
			i++;
		}
		while(a[pivot] <a[j]){
			j--;
		}
		if(i<=j){
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	temp=a[j];
	a[j]=a[pivot];
	a[pivot]=temp;
	quicksort(f,j-1);
	quicksort(j+1,l);
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
	quicksort(0,n-1);
	display();

}
