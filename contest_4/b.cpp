#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;
int priority(string s){
	if(s == "+" || s == "-") return 1;
	if(s == "*" || s == "/") return 2;
	return -1;
}
int main(){
	int test; cin>>test;
	while(test--){
		string s; cin>>s;
		stack<string> k;
		vector<string> res_vec;
		for(int i = 0; i < s.length(); i++){
			if(s[i] >= '0' && s[i] <= '9'){
				int j = i;
				while(s[j] >= '0' && s[j] <= '9') j++;
				res_vec.push_back(s.substr(i, j-i));
				i = j-1;
			}
			else if(s[i] == '(') k.push("(");
			else if(s[i] == ')'){
				while(k.size() > 0 && k.top() != "("){
					res_vec.push_back(k.top()); k.pop();
				}
				k.pop();
			}
			else{
				string tmp(1, s[i]);
				while(k.size() > 0 && priority(k.top()) >= priority(tmp)){
					res_vec.push_back(k.top()); k.pop();
				}
				k.push(tmp);
			}
		}
		while(k.size() > 0){
			res_vec.push_back(k.top()); k.pop();
		}
		for(int i = 0; i < res_vec.size(); i++){
			if(res_vec[i] != "+" && res_vec[i] != "-" && res_vec[i] != "*" && res_vec[i] != "/"){
				k.push(res_vec[i]);
			}
			else{
				long long a; istringstream (k.top()) >> a; k.pop();
				long long b; istringstream (k.top()) >> b; k.pop();
				long long c;
				if(res_vec[i] == "+") c = b+a;
				if(res_vec[i] == "-") c = b-a;
				if(res_vec[i] == "*") c = b*a;
				if(res_vec[i] == "/") c = b/a;
				ostringstream stream; stream<<c;
				k.push(stream.str());
			}
		}
		cout<<k.top()<<endl;
	}
	return 0;
}