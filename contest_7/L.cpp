#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	map<string, long int> mp;
	while(cin>>s){
		mp[s]++;
	}
	cout<<mp.size()<<endl;
	for(map<string, long int>::iterator i = mp.begin(); i != mp.end(); i++){
		cout<<i->first<<' '<<i->second<<endl;
	}
	return 0;
}
