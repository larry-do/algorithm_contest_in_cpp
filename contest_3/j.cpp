#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	int q; cin>>q;
	for(int e = 1; e <= q; e++){
		string s; cin>>s;
		long int len = s.length();
		stack<char> k;
		string a;
		for(long int i = 0; i < len; i++){
			if(s[i] == '(' || s[i] == '*' || s[i] == '/') k.push(s[i]);
			if(s[i] >= 'a' && s[i] <= 'z') a.push_back(s[i]);
			if(s[i] == '+' || s[i] == '-'){
				if(k.top() == '*' || k.top() == '/'){
					a.push_back(k.top()); k.pop();
				}
				k.push(s[i]);
			}
			if(s[i] == ')'){
				while(k.top() != '('){
					a.push_back(k.top());
					k.pop();
				}
				k.pop();
			}
		}
		while(k.size() > 0){
			a.push_back(k.top()); k.pop();
		}
		cout<<a<<endl;
	}
	return 0;
}