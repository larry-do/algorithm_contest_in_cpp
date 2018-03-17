#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Character
{
	char c;
	int k;
};
int search(char c, Character a[], int m){
	for(int i = 0; i < m; i++){
		if(a[i].c == c){
			return i;
		}
	}
	return m;
}
void countChar(string s, Character a[], int &m){
	for(int i = 0; i < s.length(); i++){
		int pos = search(s[i], a, m);
		if(pos < m){
			a[pos].k++;
		}
		else{
			m++; a[pos].c = s[i]; a[pos].k = 1;
		}
	}
}
bool compare(Character a, Character b){
	return a.k > b.k;
}
int main(){
	string s, str; cin>>s;
	int d; cin>>d;
	Character a[256];
	int m = 0, n = s.length(); str.resize(n);
	int check[1000] = {0};
	countChar(s, a, m);
	sort(a, a+m, compare);
	for(int i = 0; i < m; i++){
		int pos = 0;
		while(check[pos]) pos++;
		for(int j = 0; j < a[i].k; j++){
			if(pos + j*d >= n){
				cout<<"Vo nghiem"<<endl;
				return 0;
			}
			str[pos+j*d] = a[i].c;
			check[pos+j*d] = 1;
		}
	}
	cout<<str<<endl;
	return 0;
}