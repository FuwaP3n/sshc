#include <stdio.h>
#include <stdlib.h>
#include <libssh/libssh.h>
#include "string.h"

struct LOGIN{
	char username[99];
	char ip[15];
	char password[99];
};


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
