#include<stdio.h>
void sort(int a[],int n){
		int temp;
		for(int j=1;j<n;j++){
			temp=a[j];
			for(int i=j-1;i>=-1;i--){
				if(i==-1){
					a[i+1]=temp;
				}
				else if(temp<=a[i]){
					a[i+1]=a[i];
				}
				else{
					a[i+1]=temp;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("a[%d]=%d\n",i,a[i]);
		}
}
int main(){
	int n,a[n];
	printf("enter lenth of array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	sort(a,n);
	
}
