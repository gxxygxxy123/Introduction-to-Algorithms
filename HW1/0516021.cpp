#include<iostream>
#include<vector>
using namespace std;
int main(void){
	int T, ans;
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	int a = 1, b = 1, tmp = 1;
	int j;
	for(j = 3;j < 10000000;j++){
		tmp = (a + b) % 29989;
		a = b;
		b = tmp;
		arr.push_back(tmp);
		if(a == 1 && b == 1){
			break;//循環為j-2
			//arr[j-1] 應該=0 
			//arr[j] 應該=0 
		} 
	}
	cin >> T;//T筆資料
	for(int i = 0;i < T;i++){
		int n;//F(n)
		cin >> n;
		ans = arr[(n-1)%(j-2)];
		/*int a = 1, b = 1, tmp = 1, ans;
		for(int j = 3;j <= n;j++){
			tmp = (a + b) % 29989;
			a = b;
			b = tmp;
			arr[j] = tmp;
			if(a == 1 && b == 1){ 
				cout <<"循環"<< j-2<<endl;
				break;
			} 
		}
		ans = tmp; 
		cout << ans << endl;
		*/
		cout << ans << endl;
	}
	return 0;
} 
