#ifndef _LINK_LIST_H
#define _LINK_LIST_H
#include <stdio.h>

typedef struct NODE* ref;

struct NODE{
	int data;
	ref pNext;
};

struct LIST{
	ref head;
	ref tail;
};

void AddTail(LIST& l, ref new_ele);
void deleteAll(LIST& l);

#endif