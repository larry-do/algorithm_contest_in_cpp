#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string a;
int n;
bool next_bit(){
	int j = a.length() - 1;
	while(j >= 0 && a[j] == '9'){
		a[j] = '0';
		j--;
	}
	if(j >= 0) a[j] = '9';
	else return false;
	return true;
}
void init(int k){
	a.resize(0);
	a.assign(k, '0');
}
bool check(){
	long long tmp;
	istringstream (a) >> tmp;
	if(tmp % n == 0){
		cout<<tmp<<endl;
		return true;
	}
	return false;
}
void find(int n){
	int k = 1;
	while(1){
		init(k++);
		while(next_bit()){
			if(check()) return;
		}
	}
}
int main(){
	int q; cin>>q;
	for(int j = 0; j < q; j++){
		cin>>n;
		find(n);
	}
	return 0;
}