#include <iostream>
using namespace std;

void printArray(int *a, int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
}

void quicksort(int *a, int s, int e){

	int start, end, p;
	start = s;
	end = e-1;
	p = e;
	if(start > end) {
		return;
	}
	while(start < end){
		while(a[start] < a[p])
			start++;
		while(a[end] > a[p]) 
			end--;
		if(start < end) {
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	if(a[start] > a[p]) {
		int temp = a[start];
		a[start] = a[p];
		a[p] = temp;
	}

	quicksort(a, s, start-1);
	quicksort(a, start+1, e); 
}

int main() {
	// your code goes here
	int sort_test[] = {4,31,2,11};

	printArray(sort_test, sizeof(sort_test)/sizeof(sort_test[0]));
	cout << endl;
	
	quicksort(sort_test, 0, (sizeof(sort_test)/sizeof(sort_test[0]))-1);
	printArray(sort_test, sizeof(sort_test)/sizeof(sort_test[0]));

	return 0;
}