#include <iostream>
using namespace std;

class Node{
public:
	int value;
	Node* left;
	Node* right;
	Node(int data){
		value = data;
	}
};

void printArray(int *a, int size){
	for(int i=0; i<size; i++)
		cout << a[i] << " ";
	cout << endl;
}

void swap(int *a, int i1, int i2){
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
}

void Heapify(int* a, int index, int size){
	
	int left, right;
	left = (2*index)+1;
	right = (2*index)+2;
	if(left > size)
		return;
	int max = 0;
	Heapify(a, left, size);
	if(right > size)
		max = left;
	else {
		Heapify(a, right, size);
		max = (a[left] > a[right] ? left : right);
	}
	if(a[index] < a[max] && max <= size){
		swap(a, index, max);
		Heapify(a, max, size);
	}
}

void heapSort(int *a, int end){
	if(end == 0){
		return;
	}
	cout << "End: " << end << endl; 
	Heapify(a, 0, end);
	swap(a, 0, end);
	// printArray(a,6);
	heapSort(a, end-1);
}

int main() {
	// your code goes here
	int a[] = {1,1,0,0,2,2};
	///int a[] = {1,5,-2,3,-5,7,10};
	heapSort(a, (sizeof(a)/sizeof(a[0]))-1);
	printArray(a, sizeof(a)/sizeof(a[0]));
	return 0;
}