#include <iostream>
#include <cstring>
using namespace std;
int stack = 0;
int n;
int a[12][12];
char s[12][30];
int res = 1000, tmp = 0;
int check[12] = {0};
int countSameChar(int x, int y){
	int c[27] = {0};
	for(int i = strlen(s[x]) - 1; i >= 0; i--){
		c[s[x][i] - 'A']++;
	}
	for(int i = strlen(s[y]) - 1; i >= 0; i--){
		c[s[y][i] - 'A']++;
	}
	int k = 0;
	for(int i = 0; i < 27; i++){
		if(c[i] == 2) k++;
	}
	return k;
}
void Try(int u){
	stack++;
	if(stack == n && res > tmp) res = tmp;
	check[u] = 1;
	for(int i = 1; i <= n; i++){
		if(!check[i]){
			tmp+=a[u][i];
			Try(i);
			tmp-=a[u][i];
		}
	}
	stack--;
	check[u] = 0;
}
int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j){
				int b = countSameChar(i, j);
				a[i][j] = b;
				a[j][i] = b;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		Try(i);
	}
	cout<<res;
	return 0;
}