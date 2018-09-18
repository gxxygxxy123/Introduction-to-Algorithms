#include <iostream>
using namespace std;
class JOB{
	public:
		int T, S;
		double tmp;
		int x;
};
void merge(JOB job[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	JOB L[n1], R[n2];
	for(i = 0;i < n1;i++)
		L[i] = job[l+i];
	for(j = 0;j < n2;j++)
		R[j] = job[m+1+j];
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(L[i].tmp >= R[j].tmp){
			job[k] = L[i];
			i++;
		}
		else{
			job[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		job[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		job[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(JOB job[], int l, int r){
	if(l < r){
		int m = l+(r-l)/2;
		mergeSort(job, l, m);
		mergeSort(job, m+1, r);
		merge(job, l, m, r);
	}
}
int main(void){
	int test_case;
	cin >> test_case;
	for(int t = 0;t < test_case;t++){
		int num_jobs;
		long long int delay = 0;
		cin >> num_jobs;
		JOB *job = new JOB[num_jobs];
		for(int i = 0;i < num_jobs;i++){
			cin >> job[i].T;
			job[i].x = i+1;
		}
		for(int i = 0;i < num_jobs;i++){
			cin >> job[i].S;
			job[i].tmp = (double)job[i].S/job[i].T;
		}
		mergeSort(job, 0, num_jobs-1);
		for(int i = 0;i < num_jobs;i++){
			for(int j = i+1;j < num_jobs;j++){
				delay += (long long int)job[j].S * job[i].T;
			}
		}
		cout << delay << endl;
		for(int i = 0;i < num_jobs;i++){
			cout << job[i].x << " ";
		}
		cout << endl;
		delete[] job;
	}
	return 0;
} 
