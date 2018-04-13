#include <bits/stdc++.h>
using namespace std;
long int n, c, d;
long int a[100009];
bool compare(long int x, long int y){
	return x > y;
}
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n>>c>>d;
		for(int i = 0; i < n; i++) cin>>a[i];
		sort(a, a+n, compare);
		double csum = 0, dsum = 0;
		if(c > d) swap(c, d);
		for(int i = 0; i < n; i++){
			if(i < c) csum+=a[i];
			if(i >= c && i < c + d) dsum+=a[i];
		}
		double res = csum/c + dsum/d;
		cout<<fixed<<setprecision(6)<<res<<endl;
	}
	return 0;
}