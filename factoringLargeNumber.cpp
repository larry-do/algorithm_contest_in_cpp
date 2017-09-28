#include <iostream>
#include <string>
#include <algorithm>
std::string sumLargeNumber(std::string a, std::string b){
	if(a.length() >= b.length())
		b.insert(0,a.length()-b.length(),'0');
	else
		a.insert(0,b.length()-a.length(),'0');
	std::string c;
	int memory = 0;
	for (int i = a.length()-1; i >= 0; --i)
	{
		memory+=a[i]+b[i]-'0'-'0';
		c.push_back(memory%10+'0');
		memory/=10;
	}
	if(memory!=0) c.push_back(memory+'0');
	std::reverse(c.begin(),c.end());
	return c;
}
std::string factorNumber(std::string a, int b){
	std::string c;
	int memory = 0;
	for (int i = a.length() - 1; i >= 0; --i)
	{
		memory+=((a[i]-'0')*b);
		c.push_back(memory%10+'0');
		memory/=10;
	}
	if(memory!=0) c.push_back(memory+'0');
	std::reverse(c.begin(),c.end());
	return c;
}
std::string factorLargeNumber(std::string a, std::string b){
	std::string c;
	for(int i=a.length()-1;i>=0;i--){
		std::string tmp = factorNumber(b,a[i]-'0');
		tmp.insert(tmp.length(),a.length()-1-i,'0');
		c = sumLargeNumber(c,tmp);
	}
	return c;
}
int main(int argc, char const *argv[])
{
	std::string a = "400000000";
	std::string b = "400000000";
	std::cout<<factorLargeNumber(a,b);
	return 0;
}
