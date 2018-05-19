#include <algorithm>
#include <vector>
#include <cstdio>
#include <priority_queue>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
long int n, m;
std::vector<long int> dsk[100009];
long long dist[100009];
long long pathNum[100009];
bool check[100009];
long int s, f;

void init(){
	scanf("%ld%ld", &n, &m);
	s = 1; f = n;
	long int u, v, w;
	Loop(i, 1, m){
		scanf("%ld%ld%ld", &u, &v, &w);
		dsk[u].push_back(v);
		dsk[u].push_back(w);
		dsk[v].push_back(u);
		dsk[v].push_back(w);
	}
	Loop(i, 1, n){
		dist[i] = INT_MAX;
	}
	for(int i = 0; i < dsk[s].size(); i += 2){
		dist[dsk[s][i]] = dsk[s][i+1];
		pathNum[dsk[s][i]] = 1;
	}
}
void Dijkstra(){
	check[s] = true;
	dist[s] = 0;
	pathNum[s] = 1;
	long long u, min;
	while(!check[f]){
		u = 0, min = INT_MAX;
		Loop(i, 1, n){
			if(!check[i] && dist[i] < min){
				u = i;
				min = dist[i];
			}
		}
		check[u] = true;
		if(!check[f]){
			for(int i = 0; i < dsk[u].size(); i += 2){
				if(!check[dsk[u][i]]){
					if(dsk[u][i+1] + dist[u] < dist[dsk[u][i]]){
						dist[dsk[u][i]] = dsk[u][i+1] + dist[u];
						pathNum[dsk[u][i]] = 1;
					}
					else if(dsk[u][i+1] + dist[u] == dist[dsk[u][i]]){
						pathNum[dsk[u][i]] += pathNum[u];
					}
				}
			}
		}
	}
}
int main(){
	init();
	Dijkstra();
	printf("%lld %lld", dist[f], pathNum[f]);
	return 0;
}
