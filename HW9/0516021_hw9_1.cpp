#include<iostream>
#include<algorithm>
using namespace std;
long long find(long long x, long long p[], long long size[]){
	if(x != p[x]){
		p[x] = find(p[x], p, size);
	}
	return p[x];
}
void link(long long x, long long y, long long rank[], long long p[], long long size[]){
	long long total = size[x] + size[y];
	size[x] = total;
	size[y] = total;
	if(rank[x] > rank[y]){
		p[y] = x;
	}
	else{
		p[x] = p[y];
		if(rank[x] == rank[y])
			rank[y]++;
	}
}
void Union(long long x, long long y, long long rank[], long long p[], long long size[]){
	if(find(x, p, size) == find(y, p, size))
		return;//新增這個就AC了 
	link(find(x, p, size), find(y, p, size), rank, p, size);
	long long total = size[x] + size[y];
	//size[x] = total;
	//size[y] = total;
}
int main(void){
	long long n, m;
	cin >> n >> m;
	long long *p = new long long[n]; 
	long long *size = new long long[n];
	long long *rank = new long long[n];
	for(long long i = 0;i < n;i++){
		p[i] = i;
		rank[i] = 0;
		size[i] = 1;
	}
	for(long long i = 0;i < m;i++){
		long long a, b;
		cin >> a >> b;
		a--;b--;
		Union(a, b, rank, p, size);
	}
	long long ans = 0;
	for(long long i = 0;i < n;i++){
		ans = max(ans, size[i]);
	}
	cout << ans << endl;
	return 0;
}
