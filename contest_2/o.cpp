#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	long long a, b; cin>>a>>b;
	string aa, bb;
	ostringstream as; as<<a; aa = as.str();
	ostringstream bs; bs<<b; bb = bs.str();
	for(int i = 0; i < aa.length(); i++){
		if(aa[i] == '6') aa[i] = '5';
	}
	for(int i = 0; i < bb.length(); i++){
		if(bb[i] == '6') bb[i] = '5';
	}
	istringstream (aa) >> a; istringstream (bb) >> b;
	cout<<a+b<<" ";
	for(int i = 0; i < aa.length(); i++){
		if(aa[i] == '5') aa[i] = '6';
	}
	for(int i = 0; i < bb.length(); i++){
		if(bb[i] == '5') bb[i] = '6';
	}
	istringstream (aa) >> a; istringstream (bb) >> b;
	cout<<a+b;
	return 0;
}