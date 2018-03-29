#include <iostream>
#include <stack>
using namespace std;
int main(){
	int test; cin>>test;
	while(test--){
		long int n; cin>>n;
		long int a[n];
		stack<long int> k;
		for(long int i = 0; i < n; i++){
			cin>>a[i];
			while(k.size() > 0 && a[k.top()] < a[i]){
				a[k.top()] = a[i]; k.pop();
			}
			k.push(i);
		}
		while(k.size() > 0){
			a[k.top()] = -1; k.pop();
		}
		for(long int i = 0; i < n; i++){
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}