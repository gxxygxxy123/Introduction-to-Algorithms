#include <iostream>

using namespace std;
int count;
int Partition(int A[], int p, int r){
	int i = p - 1;
	int j;
	for(int j = p;j <= r-1;j++){
		if(A[j] <= A[r]){
			i = i + 1;
			swap(A[i], A[j]);
		}
		count++;
	}
	swap(A[i+1], A[r]);
	return i + 1;//middle
}
void Quicksort(int A[], int p, int r){
	int q;
	if(p < r){
		q = Partition(A, p, r);
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);
	}
}
int main(void){
	int T;
	cin >> T;
	for(int i = 0; i < T;i++){
		int N;
		count = 0;
		cin >> N;
		int *arr = new int[N];
		for(int j = 0; j < N;j++){//input
			cin >> arr[j];
		}
		/*if(arr[N-1] > arr[0]){
			for(int t = 0;t < N;t++){
				if(arr[t] > arr[N-1]){
					flag = false;
					break;
				}
			}
		}*/
		/*else if(arr[N-1] < arr[0]){
			for(int t = 0;t < N;t++){
				if(arr[t] < arr[N-1]){
					flag = false;
					break;
				}
			}
		}*/
		Quicksort(arr, 0, N-1);
		if(count >= N*(N-1)/2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		for(int j = 0;j < N;j++){
			cout << arr[j] << ' ';
		}
		cout << endl;
		delete[] arr;
	}
	return 0;
}
