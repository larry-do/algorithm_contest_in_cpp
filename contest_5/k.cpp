#include <bits/stdc++.h>
using namespace std;
struct Goods{
	long int x, y;
};
long int n, k;
Goods a[100009];
bool compare(Goods m, Goods k){
	return (m.y - m.x) > (k.y - k.x);
}
int main(){
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i].x;
	for(int i = 0; i < n; i++) cin>>a[i].y;
	sort(a, a+n, compare);
	long long res = 0;
	long int i = 0;
	while(i < k) res += a[i++].x;
	while(i < n) res += a[i++].y;
	cout<<res;
	return 0;
}