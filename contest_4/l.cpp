/*
	LONGEST COMMON SUBSEQUENCE USING DP
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int f[1010][1010];
string a, b;
void Trace(int i, int j){ // xuất ngược chút. thích thì cho vào stack 
	if(i == 0 || j == 0) return;
	if(a[i-1] == b[j-1]){
		cout<<a[i-1];
		Trace(i-1, j-1);
	}
	else{
		if(f[i][j-1] > f[i-1][j]) Trace(i, j-1);
		else Trace(i-1, j);
	}
}
long int find(){
	int m = a.length(), n = b.length();
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0) f[i][j] = 0;
			else if(a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
		}
	}
	return f[m][n];
}
int main(){
	cin>>a>>b;
	cout<<find()<<endl;
	Trace(a.length(), b.length());
	return 0;
}