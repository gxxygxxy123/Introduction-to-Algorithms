#include <iostream>
using namespace std;
int main(void){
	int n;
	int **map2, **map5;
	cin >> n;
	map2 = new int *[n];
	map5 = new int *[n];
	for(int i = 0;i < n;i++)
		map2[i] = new int[n];
	for(int i = 0;i < n;i++)
		map5[i] = new int[n];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			map2[i][j] = 0;
			map5[i][j] = 0;
		}
	}
	int tmp;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> tmp;
			while(tmp % 2 == 0){
				map2[i][j]++;
				tmp = tmp / 2;
			}
			while(tmp % 5 == 0){
				map5[i][j]++;
				tmp = tmp / 5;
			}
		}
	}
	for(int i = n-1;i >= 0;i--){
		for(int j = n-1;j >= 0;j--){
			if(i == n-1 && j == n-1)
				continue;
			else if(i == n-1){
				map2[i][j] += map2[i][j+1];
				map5[i][j] += map5[i][j+1];
			}
			else if(j == n-1){
				map2[i][j] += map2[i+1][j];
				map5[i][j] += map5[i+1][j];
			}
			else{
				map2[i][j] += map2[i+1][j] <= map2[i][j+1] ? map2[i+1][j] : map2[i][j+1];
				map5[i][j] += map5[i+1][j] <= map5[i][j+1] ? map5[i+1][j] : map5[i][j+1];
			}
		}
	}
	cout << ((map2[0][0] <= map5[0][0]) ? map2[0][0] : map5[0][0] )<<endl;
	return 0;
}
