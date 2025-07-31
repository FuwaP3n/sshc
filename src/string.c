#include <stdlib.h>
//#include <stdio.h>
int strlen(char *a){
	int length = 0;
	while(a[length]!='\0'){
		length++;
	}
	return length; //!NB! It will return length of string without \0 character, so string "Hello world!\0" will return int 12
}

char * strcomb(char *a, char *b){
	int size_out = strlen(a)+strlen(b)+1;
	char * out = malloc(size_out);
	int i = 0;
	int o = 0;
	while(i<strlen(a)){
		if(a[i]=='\0'){ break; }
		out[i] = a[i];
		i++;
	}
	while(o<strlen(b)){
		if(b[o]=='\0'){ break; }
		out[i+o] = b[o];
		o++;
	}
	out[size_out] = '\0';
	return out;
}

bool strcmp(char *str1, char *str2){
	if(strlen(str1)==strlen(str2)){
		for(int i=0; i<strlen(str1); i++){
			if(str1[i]!=str2[i]){
				return false;
			}
		}	return true;
	}	
	return false;
}



/*TEST MAIN
int main(){
	printf("Measuring length of a string...\nstring: 'Hello world!'\n");
	printf("%d\n", strlen("Hello world!\0"));
	printf("Combining strings...\nstring1: 'Hello '  |  string2: 'world!'\n");
	printf("%s\n", strcomb("Hello \0", "world!\0"));
	printf("Comparing two strings...\nstring1: 'Hello' |  string2: 'world!'\nPredicted false\n");
	if(strcmp("Hello\0", "world!\0")){ printf("true\n"); }
	else { printf("false\n"); }
	printf("Comparing two strings...\nstring1: 'Hello world!' |  string2: 'Hello world!'\nPredicted true\n");
	if(strcmp("Hello world!\0", "Hello world!\0")){ printf("true\n"); }
	else { printf("false\n"); }
	printf("TEST FINISHED!\n");

}*/
