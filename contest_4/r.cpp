#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool k[5000][5000];
int main(){
	int test; cin>>test;
	while(test--){
		string s; cin>>s;
		int len = s.length();
		int res = 1;
		for(int i = 0; i < len; i++) k[i][i] = true;
		for(int substringLen = 2; substringLen <= len; substringLen++){
			for(int i = 0; i < len - substringLen + 1; i++){
				int j = i + substringLen - 1;
				if(s[i] == s[j] && substringLen == 2){
					res = 2;
					k[i][j] = true;
				}
				else if(s[i] == s[j] && k[i+1][j-1]){
					k[i][j] = true;
					res = max(substringLen, res);
				}
				else k[i][j] = false;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}