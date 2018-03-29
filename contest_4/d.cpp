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
		long long res = 0;
		long int i = 0;
		while(i < n){
			if(k.empty() || a[i] >= a[k.top()]){
				k.push(i++);
			}
			else{
				long int tmp = k.top(); k.pop();
				long long area = 1LL * a[tmp] * (k.empty() ? i : (i - k.top() - 1));
				res = max(res, area);
			}
		}
		while(!k.empty()){
			long int tmp = k.top(); k.pop();
			long long area = 1LL * a[tmp] * (k.empty() ? i : (i - k.top() - 1));
			res = max(res, area);
		}
		cout<<res<<endl;
	}
	return 0;
}