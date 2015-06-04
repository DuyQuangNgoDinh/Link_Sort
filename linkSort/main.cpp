#include "linkSort.h"
#include "ArraySort.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


void outList(LIST& l){
	ref q = l.head;
	while(q != NULL){
		cout << q->data << " ";
		q = q->pNext;
	}
}

void ArrayTimeCount(int* a, int n, void (*algorithm)(int*, int)){
	clock_t t = clock();
	algorithm(a, n);
	t = clock() - t;
	cout << "Thoi gian thuc hien (tren mang): "<< t << "(milisec)\n";
}

void ListTimeCount(LIST& l, void (*algorithm)(LIST& )){
	clock_t t = clock();
	algorithm(l);
	t = clock() - t;
	cout << "Thoi gian thuc hien (tren danh sach): "<< t << "(milisec)\n";
}

int main(){
	ifstream input("input.txt");
	int n;
	input >> n;

	int* a = new int[n];
	LIST l;
	l.head = l.tail = NULL;
	
	// tạo mảng
	for(int i = 0; i < n; i++)
		input >> a[i];

	input.seekg(0, ios::beg);
	input >> n;

	// tạo list
	for(int i = 0; i < n; i++){
		ref a = new NODE;
		a->pNext = NULL;
		input >> a->data;
		AddTail(l, a);
	}

	ArrayTimeCount(a, n, InsertionSort);
	ListTimeCount(l, ListMergeSort);

	deleteAll(l);
	delete[] a;
	return 0;
}