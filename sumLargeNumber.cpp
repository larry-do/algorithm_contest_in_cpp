#include<iostream>
#include<string>
#include<algorithm>
std::string sumLargeNumber(std::string a,std::string b);
int main(){
	std::cout<<sumLargeNumber("888","23");
	return 1;
}
std::string sumLargeNumber(std::string a,std::string b){
	if(a.length() > b.length()) b.insert(0,a.length()-b.length(),'0');
	else a.insert(0,b.length()-a.length(),'0');
	std::string c;
	int memory=0;
	for(int i=a.length()-1;i>=0;i--){
		memory+=a[i]+b[i]-'0'-'0';
		c.push_back(memory%10+'0');
		memory/=10;
	}
	if(memory!=0) c.push_back(memory+'0');
	std::reverse(c.begin(),c.end());
	return c;
}
