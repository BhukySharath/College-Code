#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Brute_force
void Brute_force(){
	int i=0,j=0,count=0,flag=0;
	char text[100],pattern[100],copy[100];
	printf("Enter text:");
	scanf("%s",text);
	printf("Eneter pattern:");
	scanf("%s",pattern);
	while(strlen(pattern)+i <= strlen(text)){
		if(text[i]==pattern[j]){
			count++,j++;
		}
		else{
			j=0;
			count=0;
		}
		i++;
		if(count==strlen(pattern)){
			flag=1;
			printf("%d ",i-count);
			j=0,count=0;
		}
	}
	if(flag==0){
		printf("No Match Found\n");
	}
}
//hashvalue return
float hash_value(char text[]){
	int i;
	float hash_val=0;
	for(i=strlen(text)-1;i>=0;i--){
		hash_val+=(int)(text[i])*pow(26,strlen(text)-1-i);
	}
	return (int)hash_val;
}
//Rabin karp
void Rabin_karp(){
	char c;
	int i=0,j,count,hashp,flag=0;
	char text[100],pattern[100],copy[100];
	printf("Enter text:\n");
	scanf("%s",text);
	printf("Eneter pattern:\n");
	scanf("%s",pattern);
	hashp=hash_value(pattern);
	while(strlen(pattern)+i <= strlen(text)){
		count=0,j=i;
		while(count<strlen(pattern)){
			copy[count]=text[j];
			j++;
			count++;
		}
		if(hashp==hash_value(copy)){
			printf("%d ",i);
			flag=1;
		}
		i++;
	}
	if(flag==0){
		printf("No Match Found\n");
	}
}
//main function
void main(){
	printf("press 1:Rabin-karp\npress 2:Brute-Force\npress 0:exit\n");
	printf("Select operation:\n");
	int want;
	scanf("%d",&want);
	while(want){
		switch(want){
			case 1:
				Rabin_karp();
				break;
			case 2:
				Brute_force();
				break;
			default:
				printf("We dont have such kind of operation\n");
		}
		printf("\nSelect operation:\n");
		scanf("%d",&want);
	}
}
