#include <bits/stdc++.h>
#define MAX 100
using namespace std;
bool checkCol[MAX], checkLeftDiagonal[MAX], checkRightDiagonal[MAX];
int n, a[MAX];
int res;
void init(){
	cin>>n;
	for(int i = 1; i <= n; i++) a[i] = i;
	res = 0;
	memset(checkCol, 1, sizeof(checkCol));
	memset(checkLeftDiagonal, 1, sizeof(checkLeftDiagonal));
	memset(checkRightDiagonal, 1, sizeof(checkRightDiagonal));
}
void Try(int u){
	for(int i = 1; i <= n; i++){
		if(checkCol[i] && checkLeftDiagonal[n-u+i] && checkRightDiagonal[u+i-1]){
			a[u] = i;
			checkCol[i] = 0; checkLeftDiagonal[n-u+i] = 0; checkRightDiagonal[u+i-1] = 0;
			if(u == n) res++;
			else Try(u+1);
			checkCol[i] = 1; checkLeftDiagonal[n-u+i] = 1; checkRightDiagonal[u+i-1] = 1;
		}
	}
}
int main(){
	init();
	Try(1);
	cout<<res;
	return 0;
}