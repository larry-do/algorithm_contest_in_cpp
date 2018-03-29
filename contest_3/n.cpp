#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	int t; cin>>t;
	for(int e = 1; e <= t; e++){
		string s; cin>>s;
		long int len = s.length();
		stack<char> stk;
		int k = 0;
		for(long int i = 0; i < len; i++){
			if(s[i] == '('){
				stk.push(s[i]);
			}
			else{
				if(stk.empty() || stk.top() == ')') {stk.push(s[i]); k++;}
				else stk.pop();
			}
		}
		cout<<stk.size() / 2 + k % 2<<endl;
	}
	return 0;
}