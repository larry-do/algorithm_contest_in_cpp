// làm hơi ngu. nên số hóa tên người
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
struct PP{
	string name;
	int age;
};
bool compare(PP a, PP b){
	if(a.age > b.age) return true;
	if(a.age < b.age) return false;
	return a.name.compare(b.name) == -1;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test, h = 1; cin>>test;
	while(test--){
		int n; cin>>n;
		map<string, vector<PP> > mp;
		map<string, int> gg;
		string dad, son; int age;
		vector<PP> res;
		Loop(i, 1, n){
			cin>>dad>>son>>age;
			gg[dad] = 0; gg[son] = 0;
			PP tmp = {son, age};
			mp[dad].push_back(tmp);
			if(mp.count(son) < 1) mp[son].resize(0);
		}
		gg["Ted"] = 100;
		queue<string> k; k.push("Ted");
		string s;
		while(!k.empty()){
			s = k.front(); k.pop();
			PP tmp = {s, gg[s]}; res.push_back(tmp);
			for(vector<PP>::iterator i = mp[s].begin(); i != mp[s].end(); i++){
				k.push(i->name); gg[i->name] = gg[s] - (i->age);
			}
		}
		sort(res.begin()+1, res.end(), compare);
		cout<<"DATASET "<<h++<<endl;
		for(int i = 1; i < res.size(); i++){
			cout<<res[i].name<<" "<<res[i].age<<endl;
		}
	}
	return 0;
}