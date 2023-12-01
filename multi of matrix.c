#include<stdio.h>
int main()
{
	int i,j,r1,r2,c1,c2,k,sum,r3,c3;
    printf("enter the r1,c1 of matrix a:");
    scanf("%d%d",&r1,&c1);
    printf("enter the r2,c2 of matrix a:");
    scanf("%d%d",&r2,&c2);
	int a[r1][c1];
	int b[r2][c2];
	int c[r3][c3];
	if(c1!=r2)
	{
		printf("matrix multplication is not possible ");
	}
	else
  {

	
	printf("enter the a matrix:");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		printf("enter the b matrix:");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("the a matrix is:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("the b matrix is:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
		
	}
	printf("the multiplication of  matrix is(c):\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{ 
		  sum=0;
		  for(k=0;k<r1;k++)
		  {
		  	sum=a[i][k]*b[k][j]+sum;
		  }
		  printf("%d ",sum);
     	}
     	printf("\n");
	}
  }
  return 0;
}
