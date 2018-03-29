#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;
struct phanTu{
	int heso, somu;
};
list<phanTu> getExpressInfo(string s){
	s = s + " + ";
	list<phanTu> slist;
	size_t found = s.find_first_of("+"), pos = 0;
	while(found != string::npos){
		phanTu t;
		string tmp = s.substr(pos, found - pos - 1);
		pos = found + 1;
		found = s.find_first_of("+", pos);
		size_t p = tmp.find_first_of("*");
		istringstream (tmp.substr(0, p)) >> t.heso;
		p = tmp.find_first_of("^");
		istringstream (tmp.substr(p+1, tmp.length() - p)) >> t.somu;
		slist.push_back(t);
	}
	return slist;
}
bool compare(phanTu a, phanTu b){
	return a.somu > b.somu;
}
int main(){
	string stest; getline(cin, stest);
	int test; istringstream (stest) >> test;
	while(test--){
		string a, b;
		getline(cin, a);
		getline(cin, b);
		list<phanTu> alist = getExpressInfo(a);
		list<phanTu> blist = getExpressInfo(b);
		alist.splice(alist.begin(), blist);
		alist.sort(compare);
		list<phanTu>::iterator j;
		for(list<phanTu>::iterator i = alist.begin(); i != alist.end(); i++){
			j = i; j++;
			if(i->somu == j->somu){
				i->heso += j->heso;
				alist.erase(j);
			}
		}
		for(list<phanTu>::iterator i = alist.begin(); i != alist.end(); i++){
			j = i; j++;
			if(j == alist.end()){
				cout<<i->heso<<"*x^"<<i->somu<<endl;
			}
			else cout<<i->heso<<"*x^"<<i->somu<<" + ";
		}
	}
	return 0;
}