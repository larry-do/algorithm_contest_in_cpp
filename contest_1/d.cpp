/*
	Cho ma trận vuông Ci,j cấp N (1 i, j  N10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận
không nhất thiết phải khác nhau và đều không quá 1000, K không quá 105). Hãy viết chương trình lấy
mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.
Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C.
Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần
lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn.
Ví dụ:
INPUT OUTPUT
3 10
2 4 3
1 3 6
4 2 4
2
1 3 2
3 2 1
*/
#include <iostream>
#include <vector>
using namespace std;
int n, k;
int arr[100][100];
int x[100];
vector<vector<int> > res; // chả hiểu sao chỗ này sai nữa
void update(){
	vector<int> tmp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < tmp.size(); j++){
			if(x[i] == tmp[j]) return;
		}
		tmp.push_back(x[i]);
	}
	res.push_back(tmp);
}
void Try(int a){
	for(int i = 0; i < n; i++){
		x[a] = i;
		k-=arr[a][i];
		if(k > 0 && a < n-1) Try(a+1);
		if(k == 0 && a == n-1) update();
		k+=arr[a][i];
	}
}
int main(){
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	Try(0);
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout<<res[i][j]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}