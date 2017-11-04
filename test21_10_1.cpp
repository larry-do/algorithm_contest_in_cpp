#include<iostream>
#include <fstream>
int main(int argc, char const *argv[])
{
	std::fstream file_in;
	file_in.open("input.txt",std::ios::in);
	if(!file_in.is_open()){
		std::cout<<"Error! Can't open file input"<<std::endl;
		return 0;
	}
	int t = 0;
	file_in>>t;
	while(t > 0){
		int n = 0, k = 0;
		file_in>>n>>k;
		int bs[n],tx[n];
		for (int i = 0; i < n; ++i){
			file_in>>bs[i];
		}
		for (int i = 0; i < n; ++i){
			file_in>>tx[i];
		}
		int sum = 0;
		for (int i = 0; i < n; ++i){
			if((k%2)^(bs[i]%2)){
				sum+=tx[i];
			}
		}
		std::cout<<sum<<std::endl;
		t--;
	}
	return 0;
}