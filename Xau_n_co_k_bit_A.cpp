#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, k;
string a;
vector<string> b;
void show_next_bit(){
	int count = 0;
	string tmp; tmp.assign(k, 'A');
	for(int i = 0; i < n-k+1; i++){
		if(a.substr(i, k) == tmp){
			count++;
		}
	}
	if(count == 1) b.push_back(a);
}
bool next_bit(){
	int j = n-1;
	while(j >= 0 && a[j] == 'B'){
		a[j] = 'A';
		j--;
	}
	if(j >= 0) a[j] = 'B';
	else return false;
	return true;
}
int main(){
	cin>>n>>k; a.assign(n, 'A');
	show_next_bit();
	while(next_bit()){
		show_next_bit();
	}
	cout<<b.size()<<endl;
	for(int i = 0; i < b.size(); i++){
		cout<<b[i]<<endl;
	}
	return 0;
}