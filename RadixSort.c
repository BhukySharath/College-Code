#include<stdio.h>
#include<stdlib.h>
#define n 7
int a[n],b[10],c[n];
int get_index(int element,int i){
	int j;
	for(j=0;j<i;j++){
		element=element/10;
	}
	return element%10;
}
int max_digit_return(){
	int max=a[0],digit=0,i;
	for(i=n-1;i>=0;i--){
		if(a[i]>=max){
			max=a[i];
		}
	}
	while(max!=0){
		digit++;
		max=max/10;
	}
	return digit;
}
void RadixSort(){
	int index,digit,i,j,k;
	digit=max_digit_return();
	for(i=0;i<digit;i++){
		printf("in the digit\n");
		for(j=n-1;j>=0;j--){
			index=get_index(a[j],i);
			b[index]=b[index]+1;
		}
		for(j=1;j<10;j++){//for updataing b array
			b[j]=b[j-1]+b[j];
		}
		for(j=n-1;j>=0;j--){
			index=get_index(a[j],i);
			c[--b[index]]=a[j];
		}
		for(j=n-1;j>=0;j--){
			a[j]=c[j];
		}
		for(j=0;j<10;j++){
			b[j]=0;
		}
	}
}
void display(){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void main(){
	int i=0;
	for(i=0;i<n;i++){
		printf("Enter Element:");
		scanf("%d",&a[i]);
	}
	RadixSort();
	display();
}
