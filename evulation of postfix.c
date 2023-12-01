//evulation of postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int stack[100] ,top=-1;
//addition
int add(int a,int b){
	return b+a;
}
//subtraction
int sub(int a,int b){
	return b-a;
}
//multiplication
int mul(int a,int b){
	return b*a;
}
//division
double div(int a,int b){
	return b/a;
}
//reminder
int mod(int a,int b){
	return  b%a;
}
//power
int power(int a,int b){
	return pow(b,a);
}
//function for evulate
void evulate(){
	char exp[30];
	int i,j,r,val;
	printf("Enter expression:");
	scanf("%s",exp);
	for(i=0;i<strlen(exp);i++){
		if(isalpha(exp[i])){
			printf("Enter value of:%c ",exp[i]);
			scanf("%d",&val);
			stack[++top]=val;
		}
		else if(isdigit(exp[i])){
			stack[++top]=(int)exp[i]-48;
		}
		else{
			switch(exp[i]){
				case '+':
					r=add(stack[top],stack[top-1]);
					break;
				case '-':
					r=sub(stack[top],stack[top-1]);
					break;
				case '*':
					r=mul(stack[top],stack[top-1]);
				case '/':
					r=div(stack[top],stack[top-1]);
					break;
				case '%':
					r=mod(stack[top],stack[top-1]);
					break;
				case '^':
					r=power(stack[top],stack[top-1]);
			}
			top=top-1;
			stack[top]=r;
		}
	}
}
//main function
void main(){
	int want;
	printf("press 1:evulate\npress 0:exit\n");
	printf("\nSelect operation:");
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				evulate();
				printf("Result:%d",stack[top]);
				break;
			default:
				printf("We dont have such operation\n");
		}
		printf("\nSelect operation:");
		scanf("%d",&want);
	}
}

