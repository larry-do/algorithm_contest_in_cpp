#include <iostream>
#include <map>
#include <string>
#define Loop(i, start, finish) for(int i = start; i <= finish; i++)
using namespace std;
long int n;
map<string, long int> hihi;
long long res = 0;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    string tmp;
    Loop(i, 1, n){
    	cin>>tmp;
    	hihi[tmp]++;
    }
    for(map<string, long int>::iterator ite = hihi.begin(); ite != hihi.end(); ite++){
    	long long res_tmp = 0;
        Loop(len, 1, (ite->first).length() - 1){
    		map<string, short> haha;
    		Loop(i, 0, (ite->first).length() - len){
    			tmp = (ite->first).substr(i, len);
    			if(hihi.count(tmp) > 0 && haha.count(tmp) == 0){
    				res_tmp += hihi[tmp];
    				haha[tmp] = 1;
    			}
    		}
    	}
        res += (res_tmp * ite->second);
    	res += (ite->second*(ite->second-1));
    }
    cout<<res;
	return 0;
}