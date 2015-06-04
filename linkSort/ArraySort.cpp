#include "ArraySort.h"

void InsertionSort(int* a, int n){
	int temp, j;
	for(int i = 1; i < n; i++){
        temp = a[i];
		j = i - 1;
		while(j >= 0 && temp < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

// swap the value of two elements
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectionSort(int* a, int n){
	int imin;
	for(int i = 0; i < n - 1; i++){
		imin = i;
		for(int j = i + 1; j < n; j++){
			if(a[imin] > a[j])
				imin = j;
		}
		swap(a[i], a[imin]);
	}
}

// cài đặt Merge Sort
void merge(int* a, int* b, int na, int nb, int* c){ // gộp hai mảng có thứ tự thành 1 mảng có thứ tự
	int n = na + nb;
	int* temp = new int[n];
	int i, j, z = 0;
	i = j = 0;
	while(i < na && j < nb){
		temp[z++] = (a[i] < b[j])?a[i++]:b[j++];
	}
	while(j < nb){
		temp[z++] = b[j++];
	}
	while(i < na){
		temp[z++] = a[i++];
	}
	for(int x = 0; x < n; x++){
		c[x] = temp[x];
	}
	delete[] temp;
}

void MergeSort(int* a, int n){
	if(n == 1) return;
	int* a1 = a;
	int n1 = n/2;
	int n2 = n - n1;
	int* a2 = a + n1;
	MergeSort(a1, n1);
	MergeSort(a2, n2);
	merge(a1, a2, n1, n2, a);
}

void quick_sort(int* a, int left, int right){
	int x = a[(left + right) / 2];
	int i = left, j = right;
	do{
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while(i <= j);
	if(left < j) quick_sort(a, left, j);
	if(right > i) quick_sort(a, i, right);
}

void QuickSort(int* a, int n){
	quick_sort(a, 0, n - 1);
}