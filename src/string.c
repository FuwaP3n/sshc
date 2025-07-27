#include <stdlib.h>
int strlen(char *a){
	int length = 0;
	while(a[length]!='\0'){
		length++;
	}
	return length; //!NB! It will return index of last element excluding \0 char!
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
	return out; //!!!MEMORY LEAK IF YOU NOT FREE THIS POINTER!!
}

int strcmp(char *str1, char *str2){
	if(strlen(str1)==strlen(str2)){
		for(int i=0; i<strlen(str1)+1; i++){
			if(str1[i]!=str2[i]){
				return 0;
			}
		}	return 1;
	}	
	return 0;
}
