#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int ans = 0;
class Node{
	public:
		long long int value;
		bool check;
		vector<int> v;
		Node(){
			value = 0;
			check = false;
			v.clear();
		}
};
long long int run(int a, Node node[]){
	int degree = node[a].v.size();
	if(node[a].check == true)
		return 0;
	node[a].check = true;
	long long int tmp = 0;
	for(int i = 0;i < degree;i++){
		tmp = max(tmp, run(node[a].v.back(), node));
		node[a].v.pop_back();
	}
	return tmp+node[a].value;
}
int main(void){
	int n;
	cin >> n;
	Node node[n+1];
	long long int coin[n+1];
	for(int i = 1;i <= n;i++)
		cin >> node[i].value;
	for(int i = 1;i < n;i++){
		int a, b;
		cin >> a >> b;
		node[a].v.push_back(b);
		node[b].v.push_back(a);
	}
	ans = max(ans, run(1, node));
	cout << ans << endl;
	return 0;
}
