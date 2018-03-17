#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long int n, k;
	cin>>n>>k;
	long int a[n];
	long long res = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		res+=a[i];
	}
	sort(a+1, a+n);
	for(int i = 1; i <= n - k - 1; i++){
		res-=(2*a[i]);
	}
	cout<<res;
	return 0;
}