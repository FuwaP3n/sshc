#include <stdio.h>
#include <stdlib.h>
#include <libssh/libssh.h>
#include "string.h"

struct LOGIN{
	char username[99];
	char ip[15];
	char password[99];
};

void action(char *act, char *param1, char *param2){
}

void get_user_ip(struct LOGIN* login, char *userip){
	int x = 0;
	int y = 0;
	while(userip[x]!='@'){
		login->username[x] = userip[x];
		x++;
	}
	login->username[x] = '\0';
	x++;
	while(userip[x+y]!='\0'){
		login->ip[y] = userip[x+y];
		y++;
	}	
	login->ip[y] = '\0';
}

 get_config_file(){
	char *config_path = strcomb(getenv("HOME"), "/.config/sshc/config");
	FILE *config;
	config = fopen(config_path, "r");
	if()
	return 	
}


int main(int argc, char *argv[]){
	struct LOGIN login;
	
	
	if(strcmp(argv[1], "-c")){ //Check if use autologin
		printf("Using auto login\n");
		exit(0);
	}
	char* config = get_config_file();
	printf("config: %s\n", config);
	get_user_ip(&login, argv[1]); //placing user and ip into login
	
	printf("%s -> %s\n", login.username, login.ip);
	return 0;
}
