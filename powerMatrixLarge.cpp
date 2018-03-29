#include <iostream>
#define MOD 1000000007;
using namespace std;
struct matrix
{
	long long row, col;
	long long m[13][13];	
};
matrix mulMatrix(matrix a, matrix b){
	matrix c; c.row = a.row; c.col = b.col;
	for(int i = 0; i < a.row; i++){
		for(int j = 0; j < b.col; j++){
			c.m[i][j] = 0;
			for(int k = 0; k < a.col; k++){
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
	int q; cin>>q;
	for(int e = 1; e <= q; e++){
		long long n, k; cin>>n>>k;
		matrix a; a.row = n; a.col = n;
		for(int i = 0; i < a.row; i++){
			for(int j = 0; j < a.col; j++){
				cin>>a.m[i][j];
			}
		}
		matrix b = power(a, k);
		for(int i = 0; i < b.row; i++){
			for(int j = 0; j < b.col; j++){
				cout<<b.m[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}