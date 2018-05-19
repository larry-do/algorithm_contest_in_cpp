#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int result, tmp;
int matrix[30][30];
void init(){
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		int a, b; cin>>a>>b;
		matrix[a][b] = 1; matrix[b][a] = 1;
	}
	result = 0; tmp = 0;
}
void Try(int a){
	for(int i = 0; i < n; i++){
		if(matrix[a][i]){
			matrix[a][i] = 0; matrix[i][a] = 0;
			tmp++;
			result = max(result, tmp);
			Try(i);
			tmp--;
			matrix[a][i] = 1; matrix[i][a] = 1;
		}
	}
}
int main(){
	int q; cin>>q;
	for(int e = 0; e < q; e++){
		init();
		for(int i = 0; i < n; i++){
			Try(i);
		}
		cout<<result<<endl;
	}
	return 0;
}