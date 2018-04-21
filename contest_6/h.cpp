#include <cstdio>
#include <cstring>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
int k, n, m;
int a[110];
int matrix[1009][1009];
int res = 0;
bool check[1009];
int count[1009] = {0};
void DFS(int u){
	check[u] = 1;
	count[u]++;
	Loop(i, 1, n){
		if(!check[i] && matrix[u][i]){
			DFS(i);
		}
	}
}
int main(){
	scanf("%d%d%d", &k, &n, &m);
	Loop(i, 1, k) scanf("%d", &a[i]);
	Loop(i, 1, m){
		int x, y; scanf("%d%d", &x, &y);
		matrix[x][y] = 1;
	}
	Loop(i, 1, k){
		memset(check, 0, sizeof(check));
		DFS(a[i]);
	}
	Loop(i, 1, n){
		if(count[i] == k) res++;
	}
	printf("%d", res);
	return 0;
}