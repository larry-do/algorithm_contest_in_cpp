#include <bits/stdc++.h>
#define MOD 1000000007
long int n, k;
long long f[101][50009];
long long Count(long int m, long int s){
	if(m == 0) return s == 0; // trường hợp cơ sở
	if(f[m][s] != -1) return f[m][s]; // nếu đã xét rồi thì thôi không xét nữa
	long long tmp = 0;
	for(int i = 0; i <= 9; i++){ // đệ quy về f(n-1, k-i)
		if(s >= i){
			tmp += Count(m-1, s-i);
			tmp = tmp % MOD;
		}
	}
	f[m][s] = tmp;
	return f[m][s];
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%ld%ld", &n, &k);
		memset(f, -1, sizeof(f)); // dùng để đánh dấu các vị trí chưa xét
		long long res = 0;
		for(int i = 1; i <= 9; i++){ // đệ quy về f(n-1, k - i);
			if(k >= i){
				res += Count(n - 1, k - i);
				res = res % MOD;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}