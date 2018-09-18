#include <iostream>
#define N 500000
using namespace std;
class Node{
	public:
		long long int data;
		Node *next = NULL;
		Node(){
			next = NULL;
		}
};
long long int hash_func(long long int k){
	if(k < 0)
		k = -k;
	return ((129*k+806)%999983)%N;
}
int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		long long int n, k, count = 0;//k is target
		cin >> n >> k;
		long long int num;
		//long long int *arr = new long long int[n];
		Node* h[N];
		for(int i = 0;i < N;i++){//N個指標指向NULL 
			h[i] = NULL;
		}
		//cout << "@";
		for(int i = 0;i < n;i++){
			cin >> num;
			////Search
			//cout << "*";
			Node *p = h[ hash_func(k-num) ];
			//cout << "&" << endl;
			//cout << "Search:" <<hash_func(k-num)<<endl;
			while(p != NULL){
				//cout << "&";
				//cout << "進入" <<endl; 
				if(p -> data == k-num){
					count++;
					//cout << "增加"<<endl; 
				}
				p = p -> next;
			//	cout << "$";
			}
			//delete p;
					//cout << "@" << endl;
			/**/
			//////Insert
			//cout << "Ins:"<<hash_func(num) << endl;
			if(h[ hash_func(num) ] == NULL){
				h[ hash_func(num) ] = new Node;
				h[ hash_func(num) ]->data = num;
			}
			else{
				//cout <<"table已經有東西了"<<endl; 
				p = h[ hash_func(num) ];
				while(p->next != NULL){
					p = p -> next;
				}
				p->next = new Node;
				p -> next -> data = num;
				//delete p;
			}
			//delete p;
			//cout <<endl;
					//ccout << "!";
			/****/
		}
		cout << count << endl;
		
		//delete[] arr;
	}
		
	return 0;
}
