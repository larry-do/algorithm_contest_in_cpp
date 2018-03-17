// thuật toán
// ta cần một stack, đặt stack[0] = str[0]
// duyệt các chữ số c của số 
// nếu k > 0, xóa hết các chữ số z trong stack mà z < c. đồng thời k--;
// xong thì in ra (stack length - k) chữ số đầu trong stack là kết quả
#include <iostream>
#include <stack>
#include <string>
using namespace std;
long int n, k;
stack<char> res;
int main(){
	cin>>n>>k;
	for(long int i = 0; i < n; i++){
		char c; cin>>c;
		while(!res.empty() && k > 0 && c > res.top()){
			res.pop(); k--;
		}
		res.push(c);
	}
	while(k > 0 && !res.empty()){
		res.pop(); k--;
	}
	string a;
	while(!res.empty()){
		a.push_back(res.top());
		res.pop();
	}
	for(long int i = a.length() - 1; i >= 0; i--){
		cout<<a[i];
	}
	return 0;
}