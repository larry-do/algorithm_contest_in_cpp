#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct point{
	int x, y;
	int dist;
};
int n;
int map[110][110];
point start, end;
bool checkPoint(point u){
	if(!map[u.x][u.y]) return false;
	if(u.x < 0 || u.x >= n || u.y < 0 || u.y >= n) return false;
	return true;
}
void Find(point u){
	u.dist = 0;
	queue<point> k;
	k.push(u);
	map[u.x][u.y] = 0;
	while(!k.empty()){
		point s = k.front(); k.pop();
		if(s.x ==  end.x && s.y == end.y){
			cout<<s.dist;
			return;
		}
		for(int i = 1; i <= 4; i++){
			if(i == 1){
				point tmp = s; tmp.x++;
				while(checkPoint(tmp)){
					tmp.dist = s.dist + 1;
					k.push(tmp);
					map[tmp.x][tmp.y] = 0;
					tmp.x++;
				}
			}
			else if(i == 2){
				point tmp = s; tmp.x--;
				while(checkPoint(tmp)) {
					tmp.dist = s.dist + 1;
					k.push(tmp);
					map[tmp.x][tmp.y] = 0;
					tmp.x--;
				}
			}
			else if(i == 3){
				point tmp = s; tmp.y++;
				while(checkPoint(tmp)){
					tmp.dist = s.dist + 1;
					k.push(tmp);
					map[tmp.x][tmp.y] = 0;
					tmp.y++;
				}
			}
			else{
				point tmp = s; tmp.y--;
				while(checkPoint(tmp)){
					tmp.dist = s.dist + 1;
					k.push(tmp);
					map[tmp.x][tmp.y] = 0;
					tmp.y--;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c; cin>>c;
			if(c == '.') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	cin>>start.x>>start.y>>end.x>>end.y;
	Find(start);
	return 0;
}