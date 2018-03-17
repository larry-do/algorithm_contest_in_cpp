#include <iostream>
#include <cstring>
using namespace std;
long long power(long long n, long long k){
	if(k == 0) return 1;
	long long tmp = power(n, k/2);
	if(k % 2 == 1) return tmp*tmp*n;
	else return tmp*tmp;
}
char find(char s[], long long n){
	long long len = strlen(s); long long tmp = len;
	if(n < len) return s[n];
	while(1){
		len = tmp;
		if(n < len) return s[n];
		int m = 1;
		long long k = tmp * power(2, m);
		while(k <= n){
			len = k;
			k = tmp*power(2, ++m);
		}
		if(len == n){
			n = len - 1;
		}
		else n = n - len - 1;
	}
}
int main(){
	char s[40];
	long long n;
	cin>>s>>n;
	cout<<find(s, n-1);
	return 0;
}
