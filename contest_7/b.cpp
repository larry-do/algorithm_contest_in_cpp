#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
long int n, m;
set<long int> *a;
bool *check;
void init(){
	cin>>n>>m;
	delete[] a;
	a = new set<long int>[n + 9];
	check = new bool[n + 9];
	memset(check, 0, sizeof(check));
	long int x, y;
	Loop(i, 1, m){
		cin>>x>>y;
		a[x].insert(y);
		a[y].insert(x);
	}
}
bool BFS(long int u){
	check[u] = true;
	queue<long int> k; k.push(u);
	long int tmp = a[u].size();
	while(!k.empty()){
		long int s = k.front(); k.pop();
		for(set<long int>::iterator i = a[s].begin(); i != a[s].end(); i++){
			if(!check[*i]){
				if(a[*i].size() != tmp) return false;
				k.push(*i);
				check[*i] = true;
			}
		}
	}
	return true;
}
bool find(){
	Loop(i, 1, n){
		if(!check[i]){
			if(!BFS(i)) return false;
		}
	}
	return true;
}
int main(){
	int test; cin>>test;
	while(test--){
		init();
		if(find()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
