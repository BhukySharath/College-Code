//infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int stack[20],top=-1,r=0;
char operators[]={'-','+','*','/','%','^','(',')'};
int precedence[]={0,0,1,1,1,2,3,3};
char result[30],exp[30];


void push(char c){
	top++;
	stack[top]=c;
}
int value(char c){
	int i;
	for(i=0;i<strlen(operators);i++){
		if(c==operators[i]){
			break;
		}
	}
return precedence[i];
}
void compare(int i){
	if(isalnum(exp[i])){
		result[r]=exp[i];
		r++;
	}
else if(top==-1 || stack[top]=='('||exp[i]=='('){
	push(exp[i]);
}
else if(value(exp[i])>value(stack[top])){
	if(exp[i]==')'){
		while(stack[top]!='('){
			result[r]=stack[top];
			top--;
			r++;
		}
		top--;
	}	
else{
	push(exp[i]);
}		

}
else if(value(exp[i])<value(stack[top])){
	result[r]=stack[top];
	top--;
	r++;
	compare(i);
}
else if(value(exp[i])==value(stack[top])){
	if(exp[i]!='^' && stack[top]!='^'){
		result[r]=stack[top];
		top--;
		r++;
		compare(i);
}
else{
	push(exp[i]);
}
}
}
void display(){
	printf("\nthe reqired postfix expression is:\n");
	for(int i=0;i<strlen(result);i++){
		printf("%c",result[i]);
	}
}
void update(){
while(top!=-1){
	result[r]=stack[top];
	top--;
	r++;
	}
}
int main(){
int i;
printf("enter the expression:\n");
scanf("%s",exp);
printf("enterd expression is: %s",exp);
for(i=0;i<strlen(exp);i++){
	compare(i);
}
update();
display();
return 0;
}
