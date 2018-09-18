#include<iostream>
using namespace std;
int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		int n, max = 0;
		int arr[3*n];
		cin >> n;
		bool num[3*n][1024];
		for(int i = 0;i < 3*n;i++)
			for(int j = 0;j < 1024;j++)
				num[i][j] = false;
		for(int i = 0;i < 3*n;i++){
			int in;
			cin >> in;
			arr[i] = in;
			if(i == 0 || i == 1 || i == 2)
				num[i][in] = true;
		}
		for(int i = 3;i < 3*n;i++)
			for(int j = i-i%3-3;j < i-i%3;j++)
				for(int k = 0;k < 1024;k++)
					if(num[j][k])
						num[i][arr[i] ^ k] = true;
		for(int i = 3*n-3;i < 3*n;i++)
			for(int j = 0;j < 1024;j++)
				if(num[i][j])
					max = j > max ? j : max;
		cout << max << endl;
	}
	return 0;
}
