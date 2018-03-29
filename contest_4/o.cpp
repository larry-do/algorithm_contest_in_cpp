#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, k; cin>>n>>k;
	int a[1010];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		a[i] = a[i] % k;
	}
	int (*f)[1010] = new int[k][1010];
	f[0][0] = 0;
	for(int i = 1; i < k; i++){
		f[i][0] = -10000; // âm vô cùng
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			int tmp = (j + a[i]) % k;
			f[tmp][i] = max(f[tmp][i-1], f[j][i-1] + 1);
		}
	}
	cout<<f[0][n];
	return 0;
}