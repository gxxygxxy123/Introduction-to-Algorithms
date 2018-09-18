#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		int NumFamily, NumTable;
		cin >> NumFamily >>NumTable;
		int *FamilyMember = new int[NumFamily];
		int *SeatCapacity = new int[NumTable];
		for(int i = 0;i < NumFamily;i++){
			int tmp;
			cin >> tmp;
			FamilyMember[i] = tmp;
		}
		for(int i = 0;i < NumTable;i++){
			int tmp;
			cin >> tmp;
			SeatCapacity[i] = tmp;
		}
		sort(FamilyMember, FamilyMember + NumFamily, greater<int>() );
		sort(SeatCapacity, SeatCapacity + NumTable, greater<int>() );
		int flag = 1;
		if(FamilyMember[0] > NumTable)
			flag = 0;
		for(int i = 0;i < NumFamily;i++){
			for(int j = 0;j < FamilyMember[i];j++){
				if(SeatCapacity[j] <= 0){
					flag = 0;
					break;
				}
				SeatCapacity[j]--;
			}
			if(!flag)
				break;
			sort(SeatCapacity, SeatCapacity + NumTable, greater<int>() );
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
