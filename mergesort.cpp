#include <iostream>
using namespace std;

void printArray(int *a, int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
}

void merge(int *a, int s, int m, int e){
	int size = e-s+1;
	int merge[size];
	int i=0, j=s, k=m;
	while(j < m && k<=e){
		if(a[j] < a[k]){
			merge[i++] = a[j++];
		}
		else if(a[k] < a[j]){
			merge[i++] = a[k++];

		}
		else if(a[j] == a[k]){
			merge[i++] = a[j++];
			merge[i++] = a[k++];
		}
	}
	while(j<m){
		merge[i++] = a[j++];
	}
	while(k<=e){
		merge[i++] = a[k++];
	}
	for(int t=0; t<size; t++){
		a[s++] = merge[t];
	} 
}


void mergeSort(int *a, int s, int e){
	int size = e-s+1;

	int m = size/2;
	if(s >= e){
		return;
	}
	mergeSort(a, s, s+m-1);
	mergeSort(a, s+m, e);
	merge(a, s, s+m, e);
}

int main() {
	// your code goes here
	// int sort_test[] = {4,31,2,11,5,1,7};
	int sort_test[] = {-2,3,-5};
 
	mergeSort(sort_test, 0, (sizeof(sort_test)/sizeof(sort_test[0]))-1);
	printArray(sort_test, sizeof(sort_test)/sizeof(sort_test[0]));
 
	return 0;
}