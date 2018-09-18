#include <iostream>

using namespace std;

int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		long long int p, q, r, x, y, z;
		int N;
		cin >> p >> q >> r;
		cin >> x >> y >> z;
		cin >> N;
		int m = N, n = N;
		long long int max_left, min_right;
		int i, j, imin = 0, imax = N;
		while(imin <= imax){
			i = (imin + imax)/2;
			j = N - i;//i + j = half_len
			if(i < N && j > 0 && x*(j-1)*(j-1)+y*(j-1)+z > p*i*i+q*i+r)
				imin = i + 1;//i is too small
			else if(i > 0 && p*(i-1)*(i-1)+q*(i-1)+r > x*j*j+y*j+z)
				imax = i - 1;//i is too big
			else{//i is perfect,bingo

				if(i == 0)
					max_left = x*(j-1)*(j-1)+y*(j-1)+z;//???
				
				else if(j == 0)
					max_left = p*(i-1)*(i-1)+q*(i-1)+r;
				else
					max_left = (p*(i-1)*(i-1)+q*(i-1)+r >= x*(j-1)*(j-1)+y*(j-1)+z) ? p*(i-1)*(i-1)+q*(i-1)+r : x*(j-1)*(j-1)+y*(j-1)+z;
				cout << max_left << endl;//N-th
				break;
			}
		}
	}
	return 0;
}
