//helpers.h

#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	typedef struct node{
		char *key;
		unsigned int value;
		struct node *next;
	} dict_node;

	int isNum(char c);	
	int checkDate(char *date);

	dict_node* add_to_head(char *cookie);
	void add_to_end(dict_node *dict_head, char *cookie);

	int maxValue(dict_node *dict_head);
	void printMaxCookies(dict_node *dict_head, int max);

	void freeDictList(dict_node *dict_head);

#endif
