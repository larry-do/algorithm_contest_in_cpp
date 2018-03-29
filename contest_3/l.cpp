#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
	int q; cin>>q;
	for(int e = 1; e <= q; e++){
		string s; cin>>s;
		long int len = s.length();
		long int res = 0;
		stack<long int> k; k.push(-1);
		for(long int i = 0; i < len; i++){
			if(s[i] == '(') k.push(i);
			else{
				k.pop();
				if(k.empty()) k.push(i);
				else res = max(res, i - k.top());
			}
		}
		cout<<res<<endl;
	}
	return 0;
}