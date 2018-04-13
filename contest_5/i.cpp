#include <bits/stdc++.h>
using namespace std;
struct Pair{
	long int low, high;
};
long int n, q;
long int a[100009];
Pair b[100009];
int compare(Pair t, long int k){
	if(a[t.low] <= k && k < a[t.high]) return 0;
	if(k < a[t.low]) return -1;
	if(k >= a[t.high]) return 1;
}
long int binarySearch(Pair c[], long int n, long int k){
	long int h = n-1;
	long int l = 0;
	long int m = (l+h)/2;
	while(l <= h){
		if(compare(c[m], k) == 1){
			l = m + 1;
		}
		else if(compare(c[m], k) == -1){
			h = m - 1;
		}
		else{
			return c[m].low;
		}
		m = (l + h)/2;
	}
	return -1;
}
int main(){
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	std::sort(a, a+n);
	a[n] = INT_MAX;
	for(int i = 0; i < n; i++){
		Pair tmp = {i, i+1};
		b[i] = tmp;
	}
	cin>>q;
	for(int i = 0; i < q; i++){
		long int m; cin>>m;
		long int pos = binarySearch(b, n, m);
		cout<<pos + 1<<endl;
	}
	return 0;
}