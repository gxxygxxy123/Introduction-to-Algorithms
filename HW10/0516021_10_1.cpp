#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
	public:
		 int a, b;
		 int w;
		 //bool is_ans;
		 int origin_place;
	bool operator < (const Edge &e)const{
		return w < e.w;
	}
};
bool compare(const Edge & e1, const Edge & e2){
	return e1.w < e2.w;
}
int find(int x, int p[]){
	return x == p[x] ? x : (p[x] = find(p[x], p));
}
void Union(int x, int y, int p[]){
	p[find(x, p)] = find(y, p);
}
int main(void){
	int n, m;
	cin >> n >> m;
	Edge *e = new Edge[m];
	int *p = new int[n];
	for(int t = 0;t < n;t++){
		p[t] = t;
	}
	bool *ans = new bool[m];
	for(int t = 0;t < m;t++){
		ans[t] = false;
	}
	for(int t = 0;t < m;t++){
		cin >> e[t].a >> e[t].b >> e[t].w;
		e[t].origin_place = t;
		e[t].a--;
		e[t].b--;
	}
	sort(e, e+m, compare);
	int current = 0;
	for(int i = 0, j = 0;j < m ;j++){
		if( j == m-1 ||e[j].w != e[j+1].w){
			current = e[j].w;
			for(int tmp = i;tmp <= j;tmp++){
				if(find(e[tmp].a, p) == find(e[tmp].b, p)){
					continue;
				}
				ans[e[tmp].origin_place] = true;
			}
			for(int tmp = i;tmp <= j;tmp++){
				Union(e[tmp].a, e[tmp].b, p);
			}
			i = j;
		}
	}
	for(int i = 0;i < m;i++){
		if(ans[i] == true){
			cout <<"at least one"<<endl;
		}
		else
			cout <<"none"<<endl;
	}
	return 0;
} 
