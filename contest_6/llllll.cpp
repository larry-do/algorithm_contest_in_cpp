#include <bits/stdc++.h>
#define Loop(i,a,b) for(int i = (a); i <= (b); i++)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define RESET(c,val) memset(c,val,sizeof(c))
#define sz(a) int(a.size())
using namespace std;

int n, m, mark[1009];
vector<int> adj[1009], cl[2];

bool dfs(int u, int color = 1) {
    mark[u] = color;
    cl[2 - color].push_back(u);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!mark[v] && !dfs(v, 3 - mark[u])) return false;
        if (mark[v] == color) return false;
    }
    return true;
}
int main() {
    int test; cin>>test;
    while(test--){
        RESET(mark, 0);
        Loop(i, 1, n) adj[i].resize(0);
        cl[0].resize(0); cl[1].resize(0);
        cin>>n>>m;
        Loop(i, 1, m) {
            int u, v; cin>>u>>v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        bool check = true;
        Loop(i, 1, n) {
            if (mark[i]) continue;
            if (!sz(adj[i])) {
                mark[i] = 1;
                cl[2-mark[i]].push_back(i);
                continue;
            }
            if (!dfs(i)) {check = false; break;}
        }
        if(!check) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

















