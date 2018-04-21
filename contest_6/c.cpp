#include <iostream>
#include <queue>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
class Point {
public:
	int x, y;
	Point(int i, int j){x = i; y = j;}
	Point up(){Point tmp(x-1, y); return tmp;}
	Point bot(){Point tmp(x+1, y); return tmp;}
	Point left(){Point tmp(x, y-1); return tmp;}
	Point right(){Point tmp(x, y+1); return tmp;}
	Point upLeft(){Point tmp(x-1, y-1); return tmp;}
	Point upRight(){Point tmp(x-1, y+1); return tmp;}
	Point botLeft(){Point tmp(x+1, y-1); return tmp;}
	Point botRight(){Point tmp(x+1, y+1); return tmp;}
};
int n, m, res = 0;
short a[110][110] = {0};
queue<Point> k;
//
bool check(Point s){
	if(s.x >= 1 && s.x <= n && s.y >= 1 && s.y <= m && a[s.x][s.y] == 1) {
		a[s.x][s.y] = 0;
		return true;
	}
	return false;
}
void LeeAlgorithm(int i, int j){
	Point s(i, j);
	k.push(s);
	a[s.x][s.y] = 0;
	while(!k.empty()){
		s = k.front(); k.pop();
		Point tmp = s.up();
		if(check(tmp)) k.push(tmp);
		tmp = s.bot();
		if(check(tmp)) k.push(tmp);
		tmp = s.left();
		if(check(tmp)) k.push(tmp);
		tmp = s.right();
		if(check(tmp)) k.push(tmp);
		tmp = s.upLeft();
		if(check(tmp)) k.push(tmp);
		tmp = s.upRight();
		if(check(tmp)) k.push(tmp);
		tmp = s.botRight();
		if(check(tmp)) k.push(tmp);
		tmp = s.botLeft();
		if(check(tmp)) k.push(tmp);
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>m;
	char c;
	Loop(i, 1, n){
		Loop(j, 1, m){
			cin>>c;
			if(c == 'W') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	Loop(i, 1, n){
		Loop(j, 1, m){
			if(a[i][j]){
				res++;
				LeeAlgorithm(i, j);
			}
		}
	}
	cout<<res;
	return 0;
}