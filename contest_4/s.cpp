#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long int res[100009];
long int Find(long int n, long int m){
	memset(res, 0, (n+1) * sizeof(long int));
	res[0] = 1;
	res[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m && j <= i; j++){
			res[i] = (res[i] + res[i-j]) % MOD;
		}
	}
	return res[n];
}
int main(){
	int test; cin>>test;
	while(test--){
		long int n, m; cin>>n>>m;
		cout<<Find(n, m)<<endl;
	}
	return 0;
}