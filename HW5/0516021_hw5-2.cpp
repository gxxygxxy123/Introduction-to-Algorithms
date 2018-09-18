#include <iostream>
using namespace std;

int main(void){
	int n;
	int **map;
	cin >> n;
	map = new int*[n];
	for(int i = 0;i < n;i++)
		map[i] = new int[n];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> map[i][j];
	for(int i = n-1;i >= 0;i--){
		for(int j = n-1;j >= 0;j--){
			if(i == n-1 && j == n-1)
				continue;
			else if(i == n-1)
				map[i][j] += map[i][j+1];
			else if(j == n-1)
				map[i][j] += map[i+1][j];
			else
				map[i][j] += map[i+1][j] >= map[i][j+1] ? map[i+1][j] : map[i][j+1];
		}
	}
	cout << map[0][0]<<endl;
	return 0;
} 
