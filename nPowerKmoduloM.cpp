#include <iostream>
using namespace std;
unsigned long long n, k, m = 1000000007;
unsigned long long calculate(){
	n = n % m; // lấy phần dư
	unsigned long long result = 1;
	while(k > 0){ // chạy cho k giảm 1/2 mỗi lần
		if(k & 1){ // check k lẻ
			result = (result * n) % m;
		}
		k>>=1; // dịch bit để giảm 1/2. giảm thời gian(theo lý thuyết)
		n = (n*n) % m; // nhân lại
	}
	return result;
}
int main(){
	int q; cin>>q;
	for(int e = 0; e < q; e++){
		cin>>n>>k;
		cout<<calculate()<<endl;
	}
	return 0;
}