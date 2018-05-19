#include <bits/stdc++.h>
using namespace std;
struct node{
	long int key;
	long int left;
};
long int n, m;
node *a;
long int res;
void init(){
	delete[] a;
	a = new node[n+1];
	for(int i = 1; i <= n; i++){
		a[i].key = 1;
		a[i].left = i;
	}
	res = 1;
}
long int find(long int x){
	while(x != a[x].left){
		x = a[x].left;
	}
	return x;
}
void Union(long int x, long int y){
	a[y].left = x;
	a[x].key += a[y].key;
	res = max(res, a[x].key);
}
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n>>m;
		init();
		long int x, y;
		for(int i = 1; i <= m; i++){
			cin>>x>>y;
			x = find(x);
			y = find(y);
			if(x != y) Union(x, y);
		}
		cout<<res<<endl;
	}
	return 0;
}
