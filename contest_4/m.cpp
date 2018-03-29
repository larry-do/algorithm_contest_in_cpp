/*
	LONGEST INCREASING SUBSEQUENCE USING DP
	Đầu tiên, ta cần 1 mảng 1 chiều độ dài n (k)
	Duyệt từ 1 đến n: i
		Duyệt từ 1 đến n - 1: j
			Nếu i > j thì k[i] = max(k[i], k[i]+1);
	Kết quả là max của mảng k. Tìm max luôn khi duyệt i
	---
	Để xuất dãy này, ta truy vết ngược. Lấy m làm mốc số lớn nhất (m = MAX)
	Duyệt dãy k từ n đến 1:
		nếu k[i] == res và a[i] < m:
			Xuất a[i]
			cập nhật m = a[i] và res giảm 1
*/
#include <iostream>
#include <algorithm>
using namespace std;
void TruyVet(int a[], int n, int k[], int res){
	int m = 1000000;
	for(int i = n; i >= 1; i--){
		if(k[i] == res && a[i] < m){
			cout<<a[i]<<" ";
			m = a[i];
			res--;
		} 
	}
}
int main(){
	int n; cin>>n;
	int a[n+1];
	int k[n+1];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		k[i] = 1;
	}
	int res = k[1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(a[i] > a[j]) k[i] = max(k[i], k[j] + 1);
		}
		res = max(res, k[i]);
	}
	TruyVet(a, n, k, res);
	cout<<endl<<res;
	return 0;
}