#include <bits/stdc++.h>
#define MAX 102
#define MOD 1000000007
using namespace std;
long long f[10][MAX];
long long find(){
	memset(f, 0, sizeof(f));
	for(int i = 0; i <= 9; i++) f[i][1] = 1;
	for(int i = 2; i < MAX; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = j; k <= 9; k++){
				f[k][i] += f[j][i - 1];
				f[k][i] = f[k][i] % MOD;
			}
		}
	}
}
int main(){
	find();
	int test; cin>>test;
	while(test--){
		int n; cin>>n;
		long long res = 0;
		for(int i = 0; i <= 9; i++) {
			res += f[i][n];
			res = res % MOD;
		}
		cout<<res<<endl;
	}
	return 0;
}