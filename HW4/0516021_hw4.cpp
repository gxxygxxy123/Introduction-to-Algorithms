#include <iostream>
#define N 150000
using namespace std;
class Node{
	public:
		int data;
		int sum;
		Node(){
			sum = 0;
		}
};
long long int hash_func(long long int k){
	if(k < 0)
		k = -k;
	return ((129*k+806)%199999)%N;
	
}
int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		long long int n, k, count = 0;//k is target
		cin >> n >> k;
		long long int num;//input
		Node *h[N];
		for(int i = 0;i < N;i++)
			h[i] = NULL;
		for(int i = 0;i < n;i++){
			cin >> num;
			//Search
			//cout << "Search:" <<hash_func(k-num)<<endl;
			long long int index = hash_func(k-num);
			while(1){
				if(h[ index ] != NULL ){
					if(h[ index ]->data == k-num){
						//cout <<"進來"<<endl;
						count += h[ index ]->sum;
						break;
					}
					else{
						if(index == N-1)
							index = 0;
						else
							index++;
					}
				}
				else
					break;
			}
			//Insert
			//cout << "Ins:"<<hash_func(num) << endl;
			index = hash_func(num);
			while(1){
				if(h[index] != NULL && h[index]->data == num){
					h[index]->sum ++;
					//cout << "重複index:"<<index<<endl;
					break;
				}
				else if(h[index] == NULL){
					h[index] = new Node;
					h[index]->sum = 1;
					h[index]->data = num;
					//cout << "建立index:"<<index<<endl;
					break;
				}
				else{
					if(index == N-1)
						index = 0;
					else
						index++;
				}
			}
		}
		cout << count << endl;
	}
		
	return 0;
}
