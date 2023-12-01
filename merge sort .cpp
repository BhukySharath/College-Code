#include<stdio.h>
#define n 6
int a[n],b[n];
void create(){
	int i;
	for(i=0;i<n;i++){
		printf("enter a[%d]:\n",i);
		scanf("%d",&a[i]);
	}
	printf("array is created sucessfully\n");
}


//function for displaying the array
void disp(){
	int i;
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
//function for sorting
void sort(int f,int l){
	int m;
	if(f<=l){
		m=(f+l)/2;
		sort(f,m);
		sort(m+1,l);
		int i=f,j=m+1;
		int start;
		int k=start=0;
		while(i<=m && j<=l){
			if(a[i]<=a[j]){
				b[k]=a[i];
				i++;
				k++;
	  		}
			else{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		printf("crossed while loop\n");
		if(i<=m){
			for(int s=i;s<=m;s++){
				b[k]=a[s];
				k++;
			}
		}
		else {
			for(int s=j;s<=l;s++){
				b[k]=a[s];
				k++;
			}
		}
		//now copying in original array
		i=0;
		for(int s=f;s<=l;s++){
			a[s]=b[i];
			i++;
		}
		
	}
}
int main(){
	int want;
	printf("select operation\npress 0:exit\npress 1:create\npress 2:display\npress 3:sort\n");
	scanf("%d",&want);
	while(want){
		if(want==1){
			create();
		}
		else if(want==2){
			disp();
		}
		else if(want==3){
			sort(0,n-1);
		}
		else{
			printf("we dont have any operation\n");
		}
		printf("select operation\n");
		scanf("%d",&want);
	}
	return 0;
}
