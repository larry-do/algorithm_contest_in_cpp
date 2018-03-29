/*
	Ta có C(k, n) = C(k-1, n-1) + C(k, n-1);
	=>> công thức truy hồi dynamic
*/
#include <iostream>
#define MOD 1000000007
using namespace std;
int a[1010][1010];
long long find(int k, int n){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(i == 0 || j == 0 || j == i) a[i][j] = 1;
			else{
				a[i][j] = (a[i-1][j-1] + a[i-1][j]) % MOD;
			}
		}
	}
	return a[n][k];
}
int main(){
	int test; cin>>test;
	while(test--){
		int n, k; cin>>n>>k;
		cout<<find(k, n)<<endl;
	}
	return 0;
}