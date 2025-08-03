#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "err_log.h"

struct CONFIG_SERVER{
	char name[255];
	char ip[255];
	char user[255];
};

char read_line(FILE *file, char *dest, int size){
	char buff;
	int ptr=0;
	if(size==0){
		while(true){
			buff = fgetc(file);
			if(buff==EOF){
				return EOF;
			} if(buff=='\n'){
				return 0;
			}
			dest[ptr] = buff;
			ptr++;
			dest[ptr] = '\0';
		}
	} 
	for(int i=0; i<size+1; i++){
		buff = fgetc(file);
		if(buff==EOF){ return EOF; }	
		if(buff=='\n'){ return 0;}
		dest[i] = buff;
		dest[i+1]='\0';
	}
}



void read_and_write(struct CONFIG_SERVER * config_server){
	FILE *config;
	config = fopen("config", "r"); //PLACEHOLDER
	if(config==NULL){ printf("No config file found!\n"); return; }
	
	int line_size=255;
	char line[line_size];
	int line_debug = 1;
	
	int config_server_ptr=0;
	int custom_command_list_ptr=0;

	//Okay, I know this looks completely stupid, but I can't do it better. If someone sees it and says. Hey, I can do it better! Then fucking do it, rewrite this stupid bullshit, cause I tried to do it with 3d array, it didn't. So I did it with stupid struct. If you want to rewrite it, you should rewrite other functions which use CONFIG_SERVER struct or wite a function which will convert array or other bullshit to CONFIG_SERVER struct.

//You know, I do this stuff before uni, to have some macros that I will use for backup my data. And I try to make a full engine that will use ssh to backup. And now, I'm considering to actually abandon this project and write smaller code specially for me, not for everyone...
//Man I hate it.
//03.08.25


	while(true){
		if(read_line(config, line, line_size)==EOF){ break; };
		line_debug++;
		if(strcmp(line, "SERVER")){
			int menu_ptr=0;
			while(menu_ptr<3){	
				if(read_line(config, line, line_size)!=EOF){
					if(line[0]=='#'){ line_debug++; continue; }
				}	else { broken_file(line_debug); menu_ptr=10; }
				switch(menu_ptr){
					case 0:
						strcpy(line, config_server->name);
						break;
					case 1:
						strcpy(line, config_server->ip);	
						break;
					case 2:
						strcpy(line, config_server->user);
						break;
					default:
						break;
				}
				menu_ptr++;
				line_debug++;
			}
		} 
		if(strcmp(line, "MACROS")){
		//place for custom macros
		}
	}
	fclose(config);
}


//IGNORE EMPTY LINES
//TEST ERROR FOR BROKEN FILE
//TEST OPEN FILE
//TEST WORKING

int main(){
	struct CONFIG_SERVER config_server;
	read_and_write(&config_server);

	printf("NAME    IP    USER\n");
	printf("%s    %s    %s\n", config_server.name, config_server.ip, config_server.user);
	return 0;
}
