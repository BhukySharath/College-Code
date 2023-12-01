#include<stdio.h>
int main()
{
	int i,j,r,c;
	printf("enter the r,c of matrix a:\n");
	scanf("%d%d",&r,&c);
	int a[r][c];
	int tr[c][r];
	printf("enter the a matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("the a matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("the transpose of matrix is:\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{   tr[i][j]=a[j][i];
			printf("%d ",tr[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
