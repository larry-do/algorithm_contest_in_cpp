// tính hệ thức truy hồi được res = 2^(n-1);
// giải thích
#include <iostream>
using namespace std;
long long mod = 123456789;
unsigned long long calculate(long long n, long long k){
	n = n % mod; // lấy phần dư
	unsigned long long result = 1;
	while(k > 0){ // chạy cho k giảm 1/2 mỗi lần
		if(k & 1){ // check k lẻ
			result = (result * n) % mod;
		}
		k>>=1; // dịch bit để giảm 1/2. giảm thời gian(theo lý thuyết)
		n = (n*n) % mod; // nhân lại
	}
	return result;
}
int main(){
	int t; cin>>t;
	for(int i = 0; i < t; i++){
		long long n; cin>>n;
		cout<<calculate(2, n-1)<<endl;
	}
	return 0;
}