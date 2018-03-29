#include <iostream>
#include <string>
#include <stack>
using namespace std;
int priorityOfOperator(char c){
	if(c == '+' || c == '-') return 1;
	if(c == '*' || c == '/') return 2;
	if(c == '^') return 3;
	else return -1;
}
int main(){
	int q; cin>>q;
	for(int e = 1; e <= q; e++){
		string s; cin>>s;
		long int len = s.length();
		stack<char> k;
		string a;
		for(long int i = 0; i < len; i++){
			if(s[i] == '(') k.push(s[i]);
			else if(s[i] >= 'a' && s[i] <= 'z') a.push_back(s[i]);
			else if(s[i] == ')'){
				while(k.top() != '('){
					a.push_back(k.top()); k.pop();
				}
				k.pop();
			}
			else{
				while(k.size() > 0 && priorityOfOperator(s[i]) <= priorityOfOperator(k.top())){
					a.push_back(k.top()); k.pop();
				}
				k.push(s[i]);
			}
		}
		while(k.size() > 0){
			a.push_back(k.top()); k.pop();
		}
		cout<<a<<endl;
	}
	return 0;
}