#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s; int n;
bool next_permunation(){
	int j = n-2;
	while(j >= 0 && s[j] >= s[j+1]) j--;
	if(j >= 0){
		int k = n - 1;
		while(s[j] >= s[k]) k--;
		swap(s[j], s[k]);
		int r = j + 1, z = n - 1;
		while(r <= z){
			swap(s[r], s[z]);
			r++; z--;
		}
	}
	else return false;
	return true;
}
int main(){
	int t; cin>>t;
	for(int tt = 0; tt < t; tt++){
		int k; cin>>k; cout<<k<<" ";
		cin>>s; n = s.length();
		if(!next_permunation()){
			cout<<"BIGGEST"<<endl;
		}
		else{
			cout<<s<<endl;
		}
	}
	return 0;
}