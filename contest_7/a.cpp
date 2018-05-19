#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
long int n, m;
set<long int> a[100009];
bool check[100009];

void init(){
	cin>>n>>m;
	Loop(i, 1, n) a[i].clear();
	long int u, v;
	Loop(i, 1, m){
		cin>>u>>v;
		a[u].insert(v);
		a[v].insert(u);
	}
	memset(check, 0, sizeof(check));
}
long int BFS(long int u){
	long int res = 1;
	check[u] = true;
	queue<long int> k; k.push(u);
	while(!k.empty()){
		long int s = k.front(); k.pop();
		for(set<long int>::iterator i = a[s].begin(); i != a[s].end(); i++){
			if(!check[*i]){
				res++;
				check[*i] = true;
				k.push(*i);
			}
		}
	}
	return res;
}
void find(){
	long int res = 0;
	Loop(i, 1, n){
		if(!check[i]){
			res = max(res, BFS(i));
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
