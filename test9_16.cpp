#include <iostream>
#include <string>
bool checkPalidrome(std::string a){
	return a == std::string(a.rbegin(),a.rend());
}
int main(int argc, char const *argv[])
{
	std::string s = "abaaabaaaba";
	int a = 5, b = 8;
	std::string ss = s.substr(a,b-a+1);
	std::cout<<checkPalidrome(ss);
	return 0;
}