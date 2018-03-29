#include <iostream>
using namespace std;
int main(){
	int f[100][100], n;
	cin>>n;
	for(int i = 1; i <= n; i++) f[0][i] = 0;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i > j) f[i][j] = f[i-1][j];
			else f[i][j] = f[i-1][j] + f[i][j-i];
		}
	}
	cout<<f[n][n];
	return 0;
}