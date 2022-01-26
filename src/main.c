//main.c
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

int main(int argc, char* argv[])
{
	//check number or arguments
        if(argc != 4){
                printf("Invalid arguments!\n");
                exit(1);
        }

	//check file
	FILE *fp;
	if(argv[1]==NULL || *argv[1]=='\0'){
		printf("Invalid file!\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Invalid file!\n");
		exit(1);
	}

	//check -d
	if(strcmp(argv[2], "-d") != 0){
		printf("Invalid arguments!\n");
		exit(1);
	}

	//check date
	char *date;
	if( checkDate(argv[3]) == 0 )
	{
		printf("Invalid date!\n");
		exit(1);
	}
	else{
		date = argv[3];
	}

	//processes every line of csv file
	dict_node *dict_head = NULL;

	char *line = NULL;
	size_t line_size = 0;
	size_t read_len = getline(&line, &line_size, fp);
	
	const char comma[2] = ",";
       	const char t[2] = "T";
	char *cookie;
	char *cookie_date;	

	while(read_len != -1){
		cookie = strtok(line, comma);
		cookie_date = strtok(NULL, t);
	
		if( checkDate(cookie_date) != 0 && strcmp(date, cookie_date) == 0 ){
			if(dict_head == NULL){
				dict_head = add_to_head(cookie);
			}
			else{
				add_to_end(dict_head, cookie);
			}
		}

		free(line);
		line = NULL;
		line_size = 0;
		read_len = getline(&line, &line_size, fp);
	}
	free(line);
	fclose(fp);

	//find max value 
	int max = maxValue(dict_head);

	//print the cookies with max value
	if(max != 0){
		printMaxCookies(dict_head, max);
	}

	//free all allocated mem
	freeDictList(dict_head);	

        return 0;
}
