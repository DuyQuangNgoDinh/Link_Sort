#include "LinkList.h"

void AddTail(LIST& l, ref new_ele){
	if(l.head == NULL){
		l.head = new_ele;
		l.tail = l.head;
	}
	else{
		l.tail->pNext = new_ele;
		l.tail = new_ele;
	}
}

void deleteAll(LIST& l){
	if(l.head == NULL) return;
	ref p = l.head;
	while(p != NULL){
		ref t = p;
		p = p->pNext;
		delete t;
	}
}