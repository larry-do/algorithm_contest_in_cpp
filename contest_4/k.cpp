#include <iostream>
#include <algorithm>
using namespace std;
void show(int a[], int n, int idx1, int idx2){
	for(int i = 0; i < n; i++){
		if(i != idx1 && i != idx2) cout<<a[i];
	}
	cout<<endl;
}
bool compare(int a, int b){
	return a > b;
}
int main(){
	int test; cin>>test;
	while(test--){
		long int n; cin>>n;
		int a[n];
		long long sum = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			sum+=a[i];
		}
		//cout<<sum<<endl;
		sort(a, a+n, compare);
		if(sum % 3 == 0){
			show(a, n, -1, -1);
			continue;
		}
		else if(sum % 3 == 1){
			long int i = n-1;
			while(a[i] % 3 != 1 && i >= 0) i--;
			if(i >= 0){
				show(a, n, i, -1);
				continue;
			}
			long int idx1 = -1, idx2 = -1;
			i = n-1;
			while(a[i] % 3 != 2 && i >= 0) i--;
			if(i >= 0){
				idx1 = i--;
				while(a[i] % 3 != 2 && i >= 0) i--;
				if(i >= 0 && n > 2){
					idx2 = i;
					show(a, n, idx1, idx2);
					continue;
				}
				else cout<<-1<<endl;
			}
			else cout<<-1<<endl;
		}
		else{
			long int i = n-1;
			while(a[i] % 3 != 2 && i >= 0) i--;
			if(i >= 0){
				show(a, n, i, -1);
				continue;
			}
			long int idx1 = -1, idx2 = -1;
			i = n-1;
			while(a[i] % 3 != 1 && i >= 0) i--;
			if(i >= 0){
				idx1 = i--;
				while(a[i] % 3 != 1 && i >= 0) i--;
				if(i >= 0 && n > 2){
					idx2 = i;
					show(a, n, idx1, idx2);
					continue;
				}
				else cout<<-1<<endl;
			}
			else cout<<-1<<endl;
		}
	}
	return 0;
}