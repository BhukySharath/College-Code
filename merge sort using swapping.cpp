#include<stdio.h>
#define n 6

int a[n],b[n];

//function for creating
void create(){
	for (int i=0;i<n;i++){
		printf("enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("array created sucessfully\n");
}

//function for displaying the array
void disp(){
	for (int i=0;i<n;i++){
		printf("a[%d]=%d\n",i,a[i]);
	}
}
//function for merge
void merge(int l,int m,int u){
	int i=l,j=m+1,k=0;
	while(i<=m && j<=u){
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
		while(j<=u){
			b[k]=a[j];
			j++,k++;
		}
	}
	for(int i=0;i<=k-1;i++){
		a[f+i]=b[i];
		b[i]=0;
	}

	
}

//function for  sort
void sort(int l,int u){
	int m;
	if(l<u){
		m=(l+u)/2;
		sort(l,m);
		sort(m+1,u);
		merge(l,m,u);
	}
}


//main function
int main(){
	int val,want;
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
			sort(0,n-1);
			printf("sorting is done\n");
		}
		else{
			printf("we dont have any operation\n");
		}
		printf("select operations\n");
		scanf("%d",&want);
	}
	return 0;
}
