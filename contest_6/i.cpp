#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
struct point{
	int x, y;
	string sequence;
};
int m, n;
string words[209];
char net[10][10] = {0};
bool checkNet[10][10] = {0};
vector<string> vec;
bool compare(string a, string b){
	return a.compare(b) < 0;
}
void BFS(int u, int v, int k){
	checkNet[u][v] = 1;
	point t = {u, v, string(1, net[u][v])};
	if(net[u][v] == 'q') t.sequence += 'u';
	queue<point> g; g.push(t);
	while(!g.empty()){
		point s = g.front(); g.pop();
		if(s.sequence.compare(words[k]) == 0){
			vec.push_back(words[k]);
			return;
		}
		if(s.sequence.length() >= words[k].length()) continue;
		Loop(i, s.x - 1, s.x + 1){
			Loop(j, s.y - 1, s.y + 1){
				if(net[i][j] == words[k][s.sequence.size()] && !checkNet[i][j]){
					point tmp = {i, j, s.sequence + net[i][j]};
					if(net[i][j] == 'q') tmp.sequence += 'u';
					g.push(tmp);
					checkNet[i][j] = 1;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>m;
	Loop(i, 1, m) cin>>words[i];
	while(cin>>n, n !=0){
		vec.resize(0);
		Loop(i, 1, n){
			Loop(j, 1, n){
				cin>>net[i][j];
			}
		}
		Loop(i, 0, n+1){
			net[0][i] = '0';
			net[n+1][i] = '0';
			net[i][0] = '0';
			net[i][n+1] = '0';
		}
		Loop(k, 1, m){
			Loop(i, 1, n){
				Loop(j, 1, n){
					if(net[i][j] == words[k][0]){
						memset(checkNet, 0, sizeof(checkNet));
						BFS(i, j, k);
					}
				}
			}
		}
		sort(vec.begin(), vec.end(), compare);
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		if(vec.size() <= 0) {cout<<'-'<<endl; continue;}
		Loop(i, 0, vec.size()-1){
			cout<<vec[i]<<endl;
		}
		cout<<'-'<<endl;
	}
	return 0;
}