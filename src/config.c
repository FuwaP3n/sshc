#include <stdio.h>
#include <stlib.h>
#include "string.h"
#include "err_log.h"

void read_and_write(char ***config_server){
	FILE *config;
	config = fopen("config", "r"); //PLACEHOLDER
	char line[255];
	int line_debug = 1;
	
	int config_server_ptr=0;
	int custom_command_list_ptr=0;


	while(true){
		if((line = fgets(line, sizeof(line), config))==EOF){ break; };
		line_debug++;
		if(strcmp(line, "SERVER")){ //ADD # THING TO WORK
			int menu_ptr=0;
			while(menu_ptr<3){
				if((line = fgets(line, sizeof(line), config))!=EOF){
					if(line[0]=='#'){	line_debug++; continue; }
					config_server[config_server_ptr][menu_ptr] = line;
					menu_ptr++;
					line_debug++;
				} else { broken_file(line_debug); break; }	
			}
		}
	

	}

	fclose(config);
}



int main(){
	char config_server[9][3][255];
	
	return 0;
}
