#include "linkSort.h"
#include <stdio.h>

void ListInsertionSort(LIST& l){
	if(l.head == l.tail) return; // danh sách đã được sắp
	ref q = l.head;
	ref p = q->pNext;
	// tạo 1 nút mang giá trị nhỏ nhất chèn vào đầu danh sách
	ref t = new NODE;
	t->data = -1;
	t->pNext = l.head;
	l.head = t;

	while(p != NULL){
		ref r = l.head;
		while(r != p){
			if(r->pNext->data > p->data)
				break;
			r = r->pNext;
		}
		// tiến hành cập nhật trường pNext
		if(r != p){
			q->pNext = p->pNext;
			p->pNext = r->pNext;
			r->pNext = p;
			p = q;
		}

		q = p;
		p = p->pNext;
	}
	// trả lại danh sách ban đầu, hủy nút t
	l.head = t->pNext;
	delete t;
}

void ListSelectionSort(LIST& l){
	LIST lres;
	ref min; // chỉ đến phần từ có giá trị nhỏ nhất trong list
	ref p, q, minPrev;
	lres.head = lres.tail = NULL; // khởi tạo lres
	while(l.head != NULL){
		p = l.head;
		q = p->pNext;
		min = p;
		minPrev = NULL;
		while(q != NULL){
			if(q->data < min->data){
				min = q;
				minPrev = p;
			}
			p = q;
			q = q->pNext;
		}
		if(minPrev != NULL)
			minPrev->pNext = min->pNext;
		else
			l.head = min->pNext;
		min->pNext = NULL;
		AddTail(lres, min);
	}
	l = lres;
}

void ListQSort(LIST& l){
	ref p, x; // x chỉ đến phần tử cầm canh
	LIST l1, l2;
	if(l.head == l.tail)
		return; // đã có thứ tự
	l1.head = l1.tail = NULL;
	l2.head = l2.tail = NULL;
	x = l.head;
	l.head = x->pNext;
	while(l.head != NULL){ // tách l thành l1, l2
		p = l.head;
		l.head = p->pNext;
		p->pNext = NULL;
		if(p->data <= x->data)
			AddTail(l1, p);
		else
			AddTail(l2, p);
	}
	ListQSort(l1);
	ListQSort(l2);
	
	// Nối l1, x và l2 thành l đã sắp xếp
	if(l1.head != NULL){
		l.head = l1.head;
		l1.tail->pNext = x;
	}
	else
		l.head = x;
	x->pNext = l2.head;
	if(l2.head != NULL)
		l.tail = l2.tail;
	else l.tail = x;
}

void DistributeList(LIST& l, LIST& l1, LIST& l2){
	ref p;
	do{ // tách l thành l1 và l2
		p = l.head;
		l.head = p->pNext;
		p->pNext = NULL;
		AddTail(l1, p);
	}while(l.head && p->data <= l.head->data);
	if(l.head)
		DistributeList(l, l2, l1);
	else
		l.tail = NULL;
}

void MergeList(LIST& l, LIST& l1, LIST& l2){
	ref p;
	while(l1.head && l2.head){
		if(l1.head->data <= l2.head->data){
			p = l1.head;
			l1.head = p->pNext;
		}
		else{
			p = l2.head;
			l2.head = p->pNext;
		}
		p->pNext = NULL;
		AddTail(l, p);
	}
	if(l1.head){
		l.tail->pNext = l1.head;
		l.tail = l1.tail;
	}
	else{
		l.tail->pNext = l2.head;
		l.tail = l2.tail;
	}
}

void ListMergeSort(LIST& l){
	LIST l1, l2;
	if(l.head == l.tail) return;
	l1.head = l1.tail = NULL;
	l2.head = l2.tail = NULL;
	DistributeList(l, l1, l2);
	ListMergeSort(l1);
	ListMergeSort(l2);
	MergeList(l, l1, l2);
}