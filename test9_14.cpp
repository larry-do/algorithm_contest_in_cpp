#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
	std::string a = "ABCDEFABCDEFABCDEF";
	int kount[256]={0};
	for(int i=0;i<a.length();i++){
		kount[a[i]]++;
	}
	int c = 0;
	for (int i = 0; i < 256; ++i)
	{
		if(kount[i]%2 == 1)
			c++;
	}
	if(c == 0 || c == 1){
		std::cout<<"YES";
	}
	else{
		std::cout<<"NO";
	}
	return 0;
}