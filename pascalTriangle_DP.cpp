#include <iostream>
using namespace std;
long int find(int n, int k){
	long int f[n+1][k+1]; f[0][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(j == 1 || j == i+1) f[i][j] = 1;
			else f[i][j] = f[i-1][j] + f[i-1][j-1];
		}
	}
	return f[n][k];
}
int main(){
	int n = 5, k = 4;
	cout<<find(n, k);
	return 0;
}