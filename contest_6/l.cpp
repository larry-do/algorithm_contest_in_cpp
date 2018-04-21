#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
int n, m;
std::vector<int> dsk[1009];
int markColor[1009];
bool BFS(int start){
	std::queue<int> k; k.push(start);
	markColor[start] = 1;
	while(!k.empty()){
		int s = k.front(); k.pop();
		Loop(i, 0, dsk[s].size() - 1){
			if(markColor[dsk[s][i]] == -1) {
				k.push(dsk[s][i]); 
				markColor[dsk[s][i]] = 1 - markColor[s];
			}
			if(markColor[s] == markColor[dsk[s][i]]) return false;
		}
	}
	return true;
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%d%d", &n, &m);
		Loop(i, 1, n) dsk[i].resize(0);
		memset(markColor, -1, sizeof(markColor));
		Loop(i, 1, m){
			int a, b; scanf("%d%d", &a, &b);
			dsk[a].push_back(b); dsk[b].push_back(a);
		}
		bool check = true;
		Loop(i, 1, n){
			if(markColor[i] != -1) continue;
			if(!BFS(i)){ check = false; break; }
		}
		if(check) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}