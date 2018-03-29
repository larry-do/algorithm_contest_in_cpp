#include <iostream>
#define MOD 1000000007
#define MAX 10
using namespace std;
struct matrix{
	long long m[2][2];
};
matrix a;
matrix mulMatrix(matrix a, matrix b){
	matrix c;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			c.m[i][j] = 0;
			for(int k = 0; k < 2; k++){
				c.m[i][j]+=(a.m[i][k]*b.m[k][j]);
			}
			c.m[i][j] = c.m[i][j] % MOD;
		}
	}
	return c;
}
matrix power(matrix a, long long n){
	if(n == 1) return a;
	matrix b = power(a, n/2);
	matrix res = mulMatrix(b, b);
	if(n % 2) res = mulMatrix(res, a);
	return res;
}
int main(){
	a.m[0][0] = 0;
	a.m[0][1] = 1;
	a.m[1][0] = 1;
	a.m[1][1] = 1;
	int q; cin>>q;
	for(int i = 1; i <= q; i++){
		long long n; cin>>n;
		matrix tmp = power(a, n-1);
		long long f = tmp.m[1][1];
		cout<<f<<endl;	
	}
	return 0;
}