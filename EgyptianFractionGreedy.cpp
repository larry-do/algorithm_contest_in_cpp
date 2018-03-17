#include <iostream>
using namespace std;
int showEgyptianFraction(int n, int m){
	if(n == 0 || m == 0) return 0;
	if(n % m == 0){
		cout<<n/m;
		return 0;
	}
	if(m % n == 0){
		cout<<"1/"<<m/n;
		return 0;
	}
	if(n > m){
		cout<<1<<" + ";
		showEgyptianFraction(n%m, m);
		return 0;
	}
	int a = m/n+1;
	cout<<"1/"<<a<<" + ";
	showEgyptianFraction(n*a - m, m*a);
	return 0;
}
int main(){
	int n, m; cin>>n>>m;
	showEgyptianFraction(n, m);
	return 0;
}