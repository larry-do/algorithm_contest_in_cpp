#include <iostream>
using namespace std;
long long binarySearch(long long a[], long long n, long long k){
	long long high = n-1;
	long long low = 0;
	long long mid = (low+high)/2;
	while(low <= high){
		if(k > a[mid]){
			low = mid + 1;
		}
		else if(k < a[mid]){
			high = mid - 1;
		}
		else{
			return mid;
		}
		mid = (low + high)/2;
	}
	return -1;
}
int main(){
	int t; cin>>t;
	for(int q = 0; q < t; q++){
		long long n, k; cin>>n>>k;
		long long a[n];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		long long res = binarySearch(a, n ,k);
		if(res >= 0) cout<<res+1<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}