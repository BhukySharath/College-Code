/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
int main()
{
	int n,m,i,j,l,k,t,r;
	//here user have to enter the size of the array 
	printf("enter the value l,m,n,k,t,r:");
	scanf("%d%d%d%d%d%d",&l,&m,&n,&k,&t,&r);
	int a[n];
	int b[l][m];
	printf("enter the value for a array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("the array a is:");
		for(i=0;i<n;i++)//displaying the array a
	{
		printf(" a[%d]=%d\n",i,a[i]);
	}
	printf("enter the value for b array:\n");
	for(i=0;i<l;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("the array b is:\n{");
	for(i=0;i<l;i++)//displaying the array b
	{
		for(j=0;j<m;j++)
		{   
		    printf("\n");
			printf("b[%d][%d]=%d",i,j,b[i][j]);
		}
		printf("\n");
	}
	printf("}");
	printf("the value from one dimension array is :%d\n",*(a+k));
	printf("the value from the two dimension array is :%d",*(*(b+t)+r));
	return 0;
	
	
}

