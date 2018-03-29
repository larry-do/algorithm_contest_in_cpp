#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
int a[20], b[20];
map<string,int> M;
queue<string> Q,P;
int d1[7] = {0,1,5,2,4,6,3};
int d2[7] = {0,4,1,3,5,2,6};
string xuli1(string u){
    u = '0' + u;
    string ans = "";
    for(int i=1; i<=6; i++) ans += u[d1[i]];
    return ans;
}
string xuli2(string u){
    u = '0' + u;
    string ans = "";
    for(int i=1; i<=6; i++) ans += u[d2[i]];
    return ans;
}
void solve(){
    int res = 0,i;
    string ST = "", EN = "";
    for(i=1; i<=6; i++) ST += (char)(a[i]+48);
    for(i=1; i<=6; i++) EN += (char)(b[i]+48);
    M[ST] = 1;
    Q.push(ST);

    while(!Q.empty()){
        string u = Q.front(); Q.pop();
        if(u == EN){
            res = M[EN];
            cout << res-1 << endl;
            return;
        }
        string tmp = "";
        tmp = xuli1(u);
        if(M.find(tmp) == M.end()){
            M[tmp] = M[u]+1;
            Q.push(tmp);
        }
        tmp = xuli2(u);
        if(M.find(tmp) == M.end()){
            M[tmp] = M[u]+1;
            Q.push(tmp);
        }
    }
}
main() {
    int i;
	for(i=1; i<=6; i++)  cin >> a[i];
    for(i=1; i<=6; i++)  cin >> b[i];
    solve();
}
