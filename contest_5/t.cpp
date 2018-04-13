#include <bits/stdc++.h>
using namespace std;
int n, a[5][10001];
long long f[9][10001];
int s[9] = {-1, 0, 1, 2, 4, 5, 8, 9, 10};
bool check(int preState, int state){
	bitset<4> k1(s[preState]);
	bitset<4> k2(s[state]);
	for(int i = 0; i < 4; i++){
		if(k1[i] & k2[i]) return false;
	}
	return true;
}
long long value(int state, int i){
	bitset<4> k(s[state]);
	long long tmp = 0;
	for(int j = 0; j < 4; j++){
		tmp += (k[j] * a[j + 1][i]);
	}
	return tmp;
}
int main(){
	int test; cin>>test;
	while(test--){
		int nmax = INT_MIN;
		cin>>n;
		for(int i = 1; i <= 4; i++){
			for(int j = 1; j <= n; j++){
				cin>>a[i][j];
				nmax = max(nmax, a[i][j]);
			}
		}
		if(nmax < 0){
			cout<<nmax<<endl; continue;
		}
		for(int i = 1; i <= 8; i++) f[i][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int state = 1; state <= 8; state++){
				f[state][i] = LLONG_MIN;
				for(int preState = 1; preState <= 8; preState++){
					if(check(preState, state)){
						f[state][i] = max(f[state][i], f[preState][i-1] + value(state, i));
					}
				}
			}
		}
		long long res = LLONG_MIN;
		for(int i = 1; i <= 8; i++){
			res = max(f[i][n], res);
		}
		cout<<res<<endl;
	}
	return 0;
}