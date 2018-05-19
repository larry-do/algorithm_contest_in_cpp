#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
struct edge {
	long int u, v, w;
};
long int n, m;
edge *e;
long int *parent;
void init(){
	cin>>n>>m;
	delete[] parent;
	delete[] e;
	e = new edge[m + 1];
	parent = new long int[n + 1];
	memset(parent, -1, (n+1)*sizeof(long int)); parent[0] = 0;
	Loop(i, 1, m){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
}
bool compare(edge a, edge b){
	return a.w < b.w;
}
long int findSet(long int x){
	while(parent[x] > 0){
		x = parent[x];
	}
	return x;
}
void Union(long int i, long int j){
	long long x = parent[i] + parent[j];
	if(parent[i] > parent[j]){
		parent[j] = x;
		parent[i] = j;
	}
	else{
		parent[j] = i;
		parent[i] = x;
	}
}
void find(){
	long long res = 0;
	sort(e + 1, e + m + 1, compare);
	Loop(i, 1, m){
		long int u = findSet(e[i].u);
		long int v = findSet(e[i].v);
		if(u != v){
			res += e[i].w;
			Union(u, v);
		}
	}
	cout<<res<<endl;
}
int main(){
	int test; cin>>test;
	while(test--){
		init();
		find();
	}
	return 0;
}
/*
1
6 9
1 2 1
1 3 1
2 4 1
2 3 2
2 5 1
3 5 1
3 6 1
4 5 2
5 6 2
*/
