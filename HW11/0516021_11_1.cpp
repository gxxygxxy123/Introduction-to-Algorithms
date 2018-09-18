#include<iostream>
#include<vector>
#include<queue>
#include<stdbool.h>
using namespace std;
class Edge{
	public:
		int end, weight;
		Edge(const int e, const int w){
			end = e;
			weight = w;
		}
};
class Node{
	public:
		int d, idx;
};
struct GreaterThanByd
{
  bool operator()(const Node& a, const Node& b) const
  {
    return a.d > b.d;
  }
};
int main(void){
	int NumVertice, NumEdge, NumQuestion;
	cin >> NumVertice >> NumEdge >> NumQuestion;
	vector<Edge> list[NumVertice+1];
	for(int t = 0;t < NumEdge;t++){
		int a, b, c;
		cin >> a >> b >> c;
		Edge tmp(b, c);
		list[a].push_back(tmp);
	}
	for(int t = 0;t <= NumVertice;t++){
		Edge tmp(t, 0);
		list[0].push_back(tmp);
	}
	//Bellman_ford
	int DistanceToZero[NumVertice+1];
	//int parent[NumVertice+1];
	for(int i = 0;i < NumVertice+1;i++){
		DistanceToZero[i] = 10000000;
	}
	DistanceToZero[0] = 0;
	//parent[0] = 0;
	for(int i = 0;i < NumVertice;i++){
		int flag = 1;
		for(int a = 0;a < NumVertice+1;a++){
			for(int b = 0;b < list[a].size();b++){
				if(DistanceToZero[a] != 10000000){
					if(DistanceToZero[a] + list[a][b].weight < DistanceToZero[list[a][b].end]){
						flag = 0;
						DistanceToZero[list[a][b].end] = DistanceToZero[a] + list[a][b].weight;
					}	
				}
			}
		}
		if(flag == 1)
			break;
	}
	//Bellman_ford ends
	//調整邊的權重成>=0
	for(int i = 1;i < NumVertice+1;i++){
		for(int j = 0;j < list[i].size();j++){
			list[i][j].weight = list[i][j].weight + DistanceToZero[i] - DistanceToZero[list[i][j].end];
		}
	}
	int map[NumVertice+1][NumVertice+1];
	bool searched[NumVertice+1];
	for(int i = 0;i < NumVertice+1;i++)
		searched[i] = false;
	for(int q = 0;q < NumQuestion;q++){
		int s, t;
		cin >> s >> t;
		if(searched[s] == false){
			Node node[NumVertice+1];//點到s的最短距離 
			int parent[NumVertice+1];
			bool visit[NumVertice+1];
			for(int i = 1;i < NumVertice+1;i++){
				visit[i] = false;
				node[i].d = 10000000;
				node[i].idx = i;
			}
			node[s].d = 0;
			parent[s] = s;
			priority_queue<Node, vector<Node>, GreaterThanByd > Q;
			Q.push(node[s]);
			//這邊要塞priority_queue未完 
			while(!Q.empty()){
				Node tmp = Q.top();
				Q.pop();
				int a = tmp.idx;
				if(visit[a] == true)
					continue;
				visit[a] = true;
				for(int i = 0;i < list[a].size();i++){
					if(!visit[list[a][i].end] && node[a].d + list[a][i].weight < node[list[a][i].end].d){
						node[list[a][i].end].d = node[a].d + list[a][i].weight;
						parent[list[a][i].end] = a;
						Q.push(node[list[a][i].end]);
					}
				}
			}
			for(int i = 1;i < NumVertice+1;i++){
				if(node[i].d == 10000000)
					map[s][i] = 1000000000;
				else
					map[s][i] = node[i].d - DistanceToZero[s] + DistanceToZero[i];
			}
			searched[s] = true;
		}
		if(map[s][t] == 1000000000)
			cout << "no path" << endl;
		else
			cout << map[s][t] << endl;
	}
	return 0;
}
