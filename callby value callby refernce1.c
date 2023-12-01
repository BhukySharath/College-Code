#include<stdio.h>//programme for demonstration of call by value and call by refernce.
int fun1(int n)
{
	n*=4;
	return n;
}
int fun2(int *n)
{
	(*n)*=4;
	return *n;
}
int main ()
{   int n;
	int *p;
	printf("enter the value of n\n ");
	scanf("%d",&n);
	p=&n;
	printf("call by value is:%d\n",fun1(n));
	printf("the value n after call by value is:%d\n",n);

	printf("the by call by refernce is :%d\n",fun2(p));
	printf("the value n after call by refence is:%d\n",n);

	return 0;
	
}

