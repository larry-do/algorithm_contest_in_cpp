#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
	std::string a = "ABCD";
	std::string b = "DCBA";
	int kount_1[256]={0};
	int kount_2[256]={0};
	for(int i=0;i<a.length();i++){
		kount_1[a[i]]++;
	}
	for(int i=0;i<b.length();i++){
		kount_2[a[i]]++;
	}
	for(int i=0;i<256;i++){
		if(kount_1[i]!=kount_2[i]){
			std::cout<<"NO"<<std::endl;
			return 0;
		}
	}
	std::cout<<"YES"<<std::endl;
	return 0;
}