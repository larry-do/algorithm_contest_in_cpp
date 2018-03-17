#include <iostream>
using namespace std;
long long power(long long n, long long k){
	if(k == 0) return 1;
	long long tmp = power(n, k/2);
	if(k % 2 == 1) return tmp*tmp*n;
	else return tmp*tmp;
}
long long atTheKPos(long long n, long long k){
	long long length = power(2, n) - 1;
	long long mid = length/2 + 1;
	while(1){
		if(k == mid) return n;
		if(k > mid) k-=mid;
		length = power(2, --n) - 1;
		mid = length/2 + 1;
	}
}
int main(){
	int q; cin>>q;
	for(int e = 0; e < q; e++){
		long long n, k;
		cin>>n>>k;
		cout<<atTheKPos(n, k)<<endl;
	}
	return 0;
}
