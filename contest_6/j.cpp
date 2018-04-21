#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <cstring>
int n, m, q;
bool matrix[1001][1001];
bool checked[1001];
std::vector< std::set<int> > vec;
void DFS(int u){
	std::set<int> k;
	std::stack<int> s; s.push(u); checked[u] = 1;
	while(!s.empty()){
		int t = s.top(); s.pop(); k.insert(t);
		for(int i = 1; i <= n; i++){
			if(!checked[i] && matrix[t][i]){
				checked[i] = 1;
				s.push(t); s.push(i); break;
			}
		}
	}
	vec.push_back(k);
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		// reset data
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++){
			memset(matrix[i], 0, (n+2)*sizeof(bool));
		}
		memset(checked, 0, (n+2)*sizeof(bool));
		vec.resize(0);
		for(int i = 1; i <= m; i++){
			int a, b; scanf("%d%d", &a, &b);
			matrix[a][b] = 1; matrix[b][a] = 1;
		}
		// find the conectived
		for(int i = 1; i <= n; i++){
			if(!checked[i]){
				DFS(i);
			}
		}
		// check  two vertex
		scanf("%d", &q);
		for(int i = 1; i <= q; i++){
			int a, b; scanf("%d%d", &a, &b);
			bool c = false;
			for(int j = 0; j < vec.size(); j++){
				if(vec[j].find(a) != vec[j].end() && vec[j].find(b) != vec[j].end()){
					c = true;
					break;
				}
			}
			if(c) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}