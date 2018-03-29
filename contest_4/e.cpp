#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
long int n;
long int a[100010];
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n;
		for(long int i = 0; i < n; i++){
			cin>>a[i];
		}
		stack<long int> k;
		long int res = 0;
		long int i = 0;
		while(i < n){
			if(k.empty() || a[i] >= a[k.top()]){
				k.push(i++);
			}
			else{
				long int top = k.top(); k.pop();
				long int num = k.empty() ? i : (i - k.top() - 1);
				if(num >= a[top]){
					res = max(res, a[top]);
				}
			}
		}
		while(!k.empty()){
			long int top = k.top(); k.pop();
			long int num = k.empty() ? i : (i - k.top() - 1);
			if(num >= a[top]){
				res = max(res, a[top]);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
