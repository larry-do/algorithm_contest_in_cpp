#include <iostream>
#include <string>
#include <algorithm>
std::string ToBinary(int a){
	std::string b;
	while(a>0){
		b.push_back(a%2+'0');
		a/=2;
	}
	std::reverse(b.begin(),b.end());
	return b;
}
int main(int argc, char const *argv[])
{
	int a = 12, b = 7;
	std::string c = ToBinary(a);
	std::string d = ToBinary(b);
	int sum = 0;
	for(int i=0;i<c.length();i++){
		sum+=(c[i]-'0');
	}
	for (int i = 0; i < d.length(); ++i)
	{
		sum-=(d[i]-'0');
	}
	if(sum == 0){
		std::cout<<"YES";
	}
	else{
		std::cout<<"NO";
	}
	return 0;
}