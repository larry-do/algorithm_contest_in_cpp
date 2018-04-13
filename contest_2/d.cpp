//contest 2 bài D
// n lớn dễ bị time limited error vì O(n!)
#include <bits/stdc++.h>
using namespace std;
int n;
long int a[20][20];
int x[20];
long long res;
void init(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) x[i] = i;
	res = LONG_MAX;
}
void update(){
	long long tmp = 0;
	for(int i = 1; i <= n; i++){
		tmp += a[i][x[i]];
	}
	res = min(res, tmp);
}
bool next_permunation(){
	int j = n - 1;
	while(j > 0 && x[j] > x[j+1]) j--;
	if(j > 0){
		int k = n;
		while(x[j] > x[k]) k--;
		swap(x[j], x[k]);
		int r = j + 1, s = n;
		while(r <= s){
			swap(x[r], x[s]);
			r++; s--;
		}
	}
	else return false;
	return true;
}
int main(){
	int test; cin>>test;
	while(test--){
		init();
		update();
		while(next_permunation()) update();
		cout<<res<<endl;
	}
	return 0;
}