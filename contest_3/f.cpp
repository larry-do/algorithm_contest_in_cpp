#include <iostream>
#define mod 1000000007
using namespace std;
long long power(long long n, long long k){
	if(k == 0) return 1;
	long long tmp = power(n, k/2);
	if(k % 2) return (tmp*tmp*n) % mod;
	else return (tmp*tmp) % mod;
}
int main(){
	long long n; cin>>n;
	cout<<power(3, n-1);
	return 0;
}