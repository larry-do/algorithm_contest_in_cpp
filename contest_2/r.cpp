#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int k;
string calculate(){
	if(a.length() > b.length()) b.insert(0,a.length()-b.length(),'0');
	else a.insert(0,b.length()-a.length(),'0');
	string c;
	int memory = 0;
	for(int i = a.length()-1;i>=0;i--){
		memory+=a[i]+b[i]-'0'-'0';
		c.push_back(memory%k+'0');
		memory/=k;
	}
	if(memory!=0) c.push_back(memory+'0');
	std::reverse(c.begin(),c.end());
	return c;
}
int main(){
	cin>>k>>a>>b;
	cout<<calculate();
	return 0;
}