#include <cstdio>
#include <cstring>
#include <queue>
bool checked[1010];
bool matrix[1010][1010];
int n, m;
void BFS(int u){
	checked[u] = 1;
	std::queue<int> k; k.push(u);
	while(!k.empty()){
		int s = k.front(); k.pop();
		for(int i = 1; i <= n; i++){
			if(!checked[i] && matrix[s][i]){
				checked[i] = 1;
				m++;
				k.push(i);
			}
		}
	}
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%d", &n); m = 0;
		memset(checked, 0, sizeof(checked));
		memset(matrix, 0, sizeof(matrix));
		for(int z = 1; z < n; z++){
			int a, b; scanf("%d%d", &a, &b);
			matrix[a][b] = 1; matrix[b][a] = 1;
		}
		BFS(1);
		if(m < n - 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}