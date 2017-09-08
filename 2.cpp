#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
bool _check(long long int n,int k);
std::string intToString(long long int n);
int main(){
	std::cout<<_check(3,2);
	return 0;
}
bool _check(long long int n,int k){
	std::vector<std::string> a,c;
	while(n>0){
		std::string b = intToString(n%k);
		a.push_back(b);
		n/=k;
	}
	c=a;
	std::reverse(c.begin(),c.end());
	return c==a;
}
std::string intToString(long long int n){
    std::ostringstream temp;
    temp<<n;
    return temp.str();
}
