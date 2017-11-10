#include <iostream>
#include <string>
#include <algorithm>
bool checkNegativeNumber(std::string a){
	if(a[0] == '-') return true;
	else return false;
}
std::string subtract(std::string a, std::string b){//so duong thoi
	if(a.length() > b.length())
		b.insert(0,a.length()-b.length(),'0');
	else
		a.insert(0,b.length()-a.length(),'0');
	int mem = 0;
	std::string c;
	for(int i = a.length()-1;i>=0;i--){
    	char k;
    	if(a.compare(b)>=0) k = a[i]-b[i]+mem;
    	else k = b[i]-a[i]+mem;
    	if(k >= 0){
    		c.push_back('0'+k);
            mem = 0;
    	}
    	else{
    		k+=10;
    		c.push_back('0'+k);
    		mem = -1;
    	}
    }
    while(c[c.length()-1]=='0'){
        c.erase(c.end()-1,c.end());
    }
    if(a.compare(b)<0) c.push_back('-');
	std::reverse(c.begin(),c.end());
	return c;
}
int main(int argc, char const *argv[])
{
	std::string a="123";
	std::string b="125";
	std::cout<<subtract(a,b);
	return 0;
}