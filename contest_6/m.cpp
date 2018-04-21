#include <cstdio>
#include <queue>
#include <cstring>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
struct point{
	int x, y;
};
int n, m;
short map[1009][1009];
void BFS(int u, int v){
	map[u][v] = 0;
	point t = {u, v};
	std::queue<point> k; k.push(t);
	while(!k.empty()){
		point s = k.front(); k.pop();
		Loop(i, s.x-1, s.x+1){
			Loop(j, s.y-1, s.y+1){
				if(map[i][j]){
					map[i][j] = 0;
					point g = {i, j};
					k.push(g);
				}
			}
		}
	}
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		memset(map, 0, sizeof(map));
		scanf("%d%d", &n, &m);
		Loop(i, 1, n){
			Loop(j, 1, m){
				scanf("%d", &map[i][j]);
			}
		}
		long int res = 0;
		Loop(i, 1, n){
			Loop(j, 1, m){
				if(map[i][j] == 1){
					res++;
					BFS(i, j);
				}
			}
		}
		printf("%ld\n", res);
	}
	return 0;
}