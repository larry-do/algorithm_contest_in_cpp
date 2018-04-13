#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k;
string a, b;
vector<string> c;
void init(){
	cin>>n>>k;
	a.assign(n, 'A');
	b.assign(k, 'A');
	c.resize(0);
}
void update(){
	int check = 0;
	for(int i = 0; i < n - k + 1; i++){
		if(a.substr(i, k) == b) check++;
	}
	if(check == 1) c.push_back(a);
}
void Try_Next_Bit(int u){
	for(int i = 0; i <= 1; i++){
		a[u] = 'A' + i;
		if(u == n-1) update();
		else Try_Next_Bit(u+1);
	}
}
int main(){
	init();
	Try_Next_Bit(0);
	cout<<c.size()<<endl;
	for(int i = 0; i < c.size(); i++){
		cout<<c[i]<<endl;
	}
	return 0;
}