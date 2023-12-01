//merge sort
#include<stdio.h>
#include<stdlib.h>
#define n 7
int a[n],b[n];
void merge(int f,int m,int l){
	int i=f,j=m+1,k=0;
	while(i<= m && j<=l){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}
		else {
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i<=m){
		while(i<=m){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	else{
		while(j<=l){
			b[k]=a[j];
			j++;
			k++;
		}
	}
	for(i=0;i<k;i++){
		a[f+i]=b[i];
	}
}

void mergesort(f,l){
	int m;
	if(f<l){
		m=(f+l)/2;
		mergesort(f,m);
		mergesort(m+1,l);
		merge(f,m,l);
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
	mergesort(0,n-1);
	display();
}



