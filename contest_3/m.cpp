#include <iostream>
#include <string>
using namespace std;
int main(){
	int q; cin>>q;
	for(int e = 1; e <= q; e++){
		string s; cin>>s;
		long int len = s.length();
		char k[len+10]; long int top = 0;
		for(long int i = 0; i < len; i++){
			if(s[i] == ')'){
				if(k[top] == '(') top--;
				else k[++top] = s[i];
			}
			else if(s[i] == ']'){
				if(k[top] == '[') top--;
				else k[++top] = s[i];
			}
			else if(s[i] == '}'){
				if(k[top] == '{') top--;
				else k[++top] = s[i];
			}
			else k[++top] = s[i];
		}
		if(top == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}