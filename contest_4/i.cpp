#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
struct point{
	int x, y;
	int day;
};
int row, col;
short map[510][510];
bool checkMap[510][510] = {0};
int value[510][510];
vector<point> p;
//
bool check(point u){
	if(map[u.x][u.y] == 0) return false;
	if(u.x < 0 || u.y < 0 || u.x >= row || u.y >= col) return false;
	return true;
}
int Find(point u){
	queue<point> k;
	stack<point> z;
	z.push(u);
	k.push(u);
	while(!k.empty()){
		point s = k.front(); k.pop();
		value[s.x][s.y] = -1;
		if(map[s.x][s.y] == 2){
			value[s.x][s.y] = s.day;
			check[s.x][s.y] = 0;
		}
		point t = s; t.x++;
		if(check(t) && checkMap[t.x][t.y] == 0){
			checkMap[t.x][t.y] == 1;
			t.day = s.day+1;
			k.push(t);
		}
		t = s; t.x--;
		if(check(t) && checkMap[t.x][t.y] == 0){
			checkMap[t.x][t.y] == 1;
			t.day = s.day+1;
			k.push(t);
		}
		t = s; t.y++;
		if(check(t) && checkMap[t.x][t.y] == 0){
			checkMap[t.x][t.y] == 1;
			t.day = s.day+1;
			k.push(t);
		}
		t = s; t.y--;
		if(check(t) && checkMap[t.x][t.y] == 0){
			checkMap[t.x][t.y] == 1;
			t.day = s.day+1;
			k.push(t);
		}
	}
}
int main(){
	cin>>row>>col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin>>map[i][j];
			if(map[i][j] == 1){
				point a = {i, j, 0};
				p.push_back(a);
			}
		}
	}
	long int res = -1;
	for(long int i = 0; i < p.size(); i++){
		long int day = Find(p[i]);
		if(day == -1) {
			res = -1; break;
		}
		res = max(res, day);
	}
	cout<<res;
	return 0;
}