//testing.c

#include <assert.h>
#include "helpers.h"

static char *test_isNum(){
	assert(isNum('0') == 1);
	assert(isNum('9') == 1);
	assert(isNum('d') == 0);
	assert(isNum('!') == 0);
}

static char *test_checkDate(){
	assert(checkDate("2018-12-09") == 1);
	assert(checkDate("0000-12-09") == 0);
	assert(checkDate("2018-00-09") == 0);
	assert(checkDate("2018-12-00") == 0);
	assert(checkDate("2018.12-09") == 0);
	assert(checkDate("2018-b2-09") == 0);
}

static char *test_addToHead(){
	dict_node *dict_head = add_to_head("cookie");
	assert(strcmp(dict_head->key, "cookie") == 0);
	assert(dict_head->value == 1);
	assert(dict_head->next == NULL);
	freeDictList(dict_head);
}

static char *test_addToEnd(){
	dict_node *dict_head = add_to_head("cookie");
	add_to_end(dict_head, "cookie");
	assert(strcmp(dict_head->key, "cookie") == 0);
	assert(dict_head->value == 2);
	assert(dict_head->next == NULL);
	
	add_to_end(dict_head, "anothercookie");
	assert(strcmp(dict_head->next->key, "anothercookie") == 0);
	assert(dict_head->next->value == 1);
	assert(dict_head->next->next == NULL);

	freeDictList(dict_head);
}

static char *test_maxValue(){
	dict_node *dict_head = NULL;
	assert(maxValue(dict_head) == 0);
	
	dict_head = add_to_head("cookie");
	assert(maxValue(dict_head) == 1);
	
	add_to_end(dict_head, "cookie");
	assert(maxValue(dict_head) == 2);
	
	add_to_end(dict_head, "anothercookie");
	assert(maxValue(dict_head) == 2);

	freeDictList(dict_head);
}

int main(){
	test_isNum();
	test_checkDate();
	test_addToHead();
	test_addToEnd();
	test_maxValue();
	return 0;
}

