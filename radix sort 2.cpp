//implimentation of radix sort

#include<stdio.h>
#define n 7

int a[n],b[n];

//function for radix sort
void radixsort(){
	int i,j,k,digits=0,place,max=a[0],N,number,rem,count[10],index;
	//loop  for finding max element
	for(i=0;i<n;i++){
		if(a[i]>=max){
			max=a[i];
		}
	}
	//finding for number of digits in max
	N=max;
	while(N!=0){
		N=N/10;
		digits++;
	}
	//running loop for traversal of array
	for(i=0;i<digits;i++){
	    	for(k=0;k<10;k++){
		    	count[k]=0;
	        }   
		for(j=0;j<n;j++){
			N=a[j];
			for(k=0;k<i;k++){
				N=N/10;
			}
			rem=N%10;
			count[rem]=count[rem]+1;
		}
		//updating the the count aray
		int c;
		for(k=9;k>0;k--){
			c=0;
			for(int s=k;s<=0;s--){
				c=c+count[s];
			}
			count[k]=c;
			
		}
		// traversal in array for placing the val
		for(j=0;j<n;j++){
			N=a[j];
			for(k=0;k<i;k++){
				N=N/10;
			}
			rem=N%10;
			index=count[rem];
			b[index]=a[j];
			count[rem]=count[rem]+1;
		}
		printf("in the %d th iteration\n",i);
		for(k=0;k<n;k++){
			a[k]=b[k];
			printf("a[%d]=%d\n",k,a[k]);
		}
		
	}
	printf("the sorted array is :\n");
	for(k=0;k<n;k++){
		printf("%d\n",a[k]);
	}
}
int main(){
	
	for(int i=0;i<n;i++){
		printf("enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	printf("array created successfully\n");
	radixsort();
	
	return 0;
}
