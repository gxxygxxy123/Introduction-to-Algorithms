#include<iostream>
using namespace std;
int max(int a, int b){
	return (a >= b)? a : b;
}
class Node{
	public:
		int x;
		int count;
		Node(){
			count = 1;
		}
};
int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		int n, ans = 1;
		cin >> n;
		Node *arr = new Node[n];
		for(int i = 0;i < n;i++){
			cin >> arr[i].x;
			for(int j = 0;j < i;j++){
				if(arr[i].x >= arr[j].x){
					arr[i].count = max(arr[i].count, arr[j].count+1);
				}
			}
			ans = max(ans,arr[i].count);
		}
		cout << ans << endl;
		delete[] arr;
	}
	
	return 0;
} 
