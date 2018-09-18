#include <iostream>
using namespace std;
class Node{
	public:
		Node *left, *right;
		int value;
		Node(){
			left = NULL;
			right = NULL;
		}
};
void insert(Node *p, int num){
	while(1){
		if(p->value > num){//往左邊找 
			if(p->left == NULL){
				p->left = new Node();
				p->left->value = num;
				break;
			}
			else{
				p = p->left;
			}
		}
		else{//往右邊找 
			if(p->right == NULL){
				p->right = new Node();
				p->right->value = num;
				break;
			}
			else{
				p = p->right;
			}
		}
	}
}
void search(Node* p, int num){
	while(1){
		if(p->value == num){
			return;
		}
		else if(p->value > num){
			cout << 'L';
			p = p->left;
		}
		else{
			cout << 'R';
			p = p->right;
		}
	}
}
int main(void){
	int m, n;
	while(cin >> n >> m){
		Node *r = NULL;//root
		for(int t = 0;t < n;t++){
			int num;
			cin >> num;
			if(r == NULL){//empty
				r = new Node();
				r->value = num;
			}
			else{
				insert(r, num);
			}
			
		}
		search(r, m);
		cout << endl;
	}
	return 0;
}
