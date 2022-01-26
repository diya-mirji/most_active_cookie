//helpers.c

#include "helpers.h"

//helper functions that check constraints
//isNum: checks if given character is an integer digit
int isNum(char c)
{
	if( c < 48 || c > 57){ return 0; }
	return 1;
}

//checkDate: checks if the given string is of proper date format
int checkDate(char *date)
{
	if(strlen(date) != 10){ return 0; }
	
	if( isNum(date[0])==0 || isNum(date[1])==0 || isNum(date[2])==0 || isNum(date[3])==0 ){
		return 0;
	}
	else if( date[0]==48 && date[1]==48 && date[2]==48 && date[3]==48 ){
		return 0;
	}
	
	if(date[4] != 45){ return 0; }
	
	if( isNum(date[5])==0 || isNum(date[6])==0 ){
		return 0;
	}
	else if( date[5]==48 && date[6]==48 ){
		return 0;
	}
	else if( date[5]>49 && date[6]>50 ){
		return 0;
	}

	if(date[7] != 45){ return 0; }

	if( isNum(date[8])==0 || isNum(date[9])==0 ){
		return 0;
	}
	else if( date[8]==48 && date[9]==48 ){
		return 0;
	}
	else if( date[8]>51 && date[9]>49 ){
		return 0;
	}

	return 1;
}


//helper functions for the Dict List
//add_to_head: returns a new dict_node for the first element of the Dict List
dict_node *add_to_head(char *cookie)
{
	dict_node *new_node = malloc(sizeof(dict_node));
	
	char *cookie_copy = malloc(20);
	strcpy(cookie_copy, cookie);
	new_node->key = cookie_copy;
	
	new_node->value = 1;
	new_node->next = NULL;
	return new_node;
}

//add_to_end: adds a new dict_node to the end of the given Dict List
void add_to_end(dict_node *dict_head, char *cookie)
{
	dict_node *current = dict_head;
	while( current->next != NULL ){
		if( strcmp(current->key, cookie) == 0 ){ //if cookie already in the Dict List
			current->value = current->value + 1;
			return;
		}
		current = current->next;
	}
	if( strcmp(current->key, cookie) == 0 ){ //if cookie already in the Dict List
		current->value = current->value + 1;
		return;
	}
	
	//at end
	current->next = malloc(sizeof(dict_node));
	
	char *cookie_copy = malloc(20);
	strcpy(cookie_copy, cookie);
	current->next->key = cookie_copy;
	
	current->next->value = 1;
	current->next->next = NULL;
	return;
}


//helper functions to find and print most active cookies in Dict List
//maxValue: returns max value of all dict_node in the given Dict List
int maxValue(dict_node *dict_head)
{
	dict_node *current = dict_head;
        int max = 0;

        while(current != NULL){
                if( current->value > max ){
                        max = current->value;
                }
                current = current->next;
        }
	return max;
}

//printMaxCookies: prints out each of the cookies(key of the dict_node) that have the given max value
void printMaxCookies(dict_node *dict_head, int max)
{
	dict_node *current = dict_head;

	while(current != NULL){
		if(current->value == max){
			printf("%s\n", current->key);
		}
		current = current->next;
	}
}


//helper function that frees allocated memory
//freeDictList: frees all dynamically allocated memory associated with the Dict List
void freeDictList(dict_node *dict_head)
{
	if(dict_head != NULL){
		dict_node *current = dict_head;
		dict_node *temp;

		while(current != NULL){
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp);
		}
	}
}


