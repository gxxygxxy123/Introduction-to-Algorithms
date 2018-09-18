#include <iostream>

using namespace std;
int heap_size;
int length_A;
int heapsize(int A[]){
	return heap_size;
}
int length(int A[]){
	return length_A;
}
void maxHeapify(int A[], int i){
	int l = 2*i;
	int r = 2*i+1;
	int largest = i;
	if(l <= heapsize(A) && A[l] > A[i]){
		largest = l;
	}
	if(r <= heapsize(A) && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		swap(A[i], A[largest]);
		maxHeapify(A, largest);
	}
}
void buildMaxHeap(int A[]){
	for(int i = heapsize(A)/2;i >= 1;i--)
		maxHeapify(A, i);
}
void HeapSort(int A[]){
	buildMaxHeap(A);
	for(int i = length(A);i >= 2;i--){
		swap(A[1], A[i]);
		heap_size = heap_size - 1;
		maxHeapify(A, 1);
	}
}
int main(void){
	int A[100005];
	cin >> length_A;
	heap_size = length_A;
	for(int i = 1;i <= length_A;i++){
		cin >> A[i];
	}
	buildMaxHeap(A);
	for(int i = 1;i <= length_A;i++){
		cout << A[i] << ' ';
	}
	cout << endl;
	
	HeapSort(A);
	for(int i = 1;i <= length_A;i++){
		cout << A[i] << ' ';
	}
	cout << endl;
	return 0;
}
