#include <iostream>
using namespace std;
long long a[100]; // mảng lưu độ dài dãy fibo sau mỗi lần cộng
char Try(int n, long long k){
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k > a[n - 2]) Try(n - 1, k - a[n - 2]);
	else Try(n - 2, k);
}
int main(){
	int t; cin>>t;
	for(int e = 0; e < t; e++){
		int n; long long k;
		cin>>n>>k;
		a[1] = 1; a[2] = 1;
		for(int i = 3; i <= n; i++){
			a[i] = a[i - 2] + a[i - 1];
		}
		cout<<Try(n, k)<<endl;
	}
	return 0;
}