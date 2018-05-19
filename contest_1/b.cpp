#include <iostream>
using namespace std;
int n, k;
int x[100], a[100];
bool next_combination(){
	int j = k;
	while(j > 0 && x[j] == n - k + j) j--;
	if(j > 0){
		a[j]++;
		for(int i = j + 1; i <= k; i++){
			a[i] = a[i - 1] + 1;
		}
	}
	else return false;
	return true;
}
int main(){
	int p; cin>>p;
	for(int i = 0; i < p; i++){
		cin>>n>>k;
		for(int j = 1; j <= k; j++){
			cin>>x[j];
			a[j] = x[j];
		}
		if(!next_combination()){
			cout<<k<<endl;
			continue;
		}
		int count = 0;
		for(int j = 1; j <= k; j++){
			for(int m = 1; m <= k; m++){
				if(x[j] == a[m]){
					count++;
				}
			}
		}
		cout<<k - count<<endl;
	}
	return 0;
}