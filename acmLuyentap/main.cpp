#include <iostream>
#include <map>
using namespace std;
int main(){
	map<int, int> a;
	a[1] = 1;
	for(map<int, int>::iterator i = a.begin(); i != a.end(); i++){
		cout<<i->first<<" "<<i->second<<endl;
	}
	return 0;
}