#include <stdio.h>
#include <stdlib.h>
#include <libssh/libssh.h>

struct LOGIN{
	char username[99];
	char ip[15];
	char password[99];
};


//START OF STRING.C FUNCTIONS
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
//END OF STRING.C FUNCTIONS



void get_user_pass(struct LOGIN* login, char *userpass){
	int x = 0;
	int y = 0;
	while(userpass[x]!='@'){
		login->username[x] = userpass[x];
		x++;
	}
	login->username[x] = '\0';
	x++;
	while(userpass[x+y]!='\0'){
		login->ip[y] = userpass[x+y];
		y++;
	}	
	login->ip[y] = '\0';
}

char * get_config_file(){
	char *homefolder = malloc(sizeof(getenv("HOME")));
	homefolder = getenv("HOME");
	return strcomb(homefolder, "/.sshc_config");	
}



int main(int argc, char *argv[]){
	struct LOGIN login;
	if(argv[1][0]=='-' && argv[1][1]=='c'){ //Check if use autologin
		printf("Using auto login\n");
		exit(0);
	}
	char* config = get_config_file();
	printf("config: %s\n", config);
	get_user_pass(&login, argv[1]); //placing user and pass into login
	
	printf("%s -> %s\n", login.username, login.ip);
	return 0;
}
