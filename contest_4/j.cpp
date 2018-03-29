#include <iostream>
#include <queue>
using namespace std;
struct Point{
	int z, y, x, dist;
};
int a, b, c;
bool map[31][31][31];
Point start, end;
Point moveZ1(Point u){
	u.z--;
	u.dist++;
	return u;
}
Point moveZ2(Point u){
	u.z++;
	u.dist++;
	return u;
}
Point moveY1(Point u){
	u.y--;
	u.dist++;
	return u;
}
Point moveY2(Point u){
	u.y++;
	u.dist++;
	return u;
}
Point moveX1(Point u){
	u.x--;
	u.dist++;
	return u;
}
Point moveX2(Point u){
	u.x++;
	u.dist++;
	return u;
}
bool checkPoint(Point u){
	if(!map[u.z][u.y][u.x]) return false;
	if(u.z < 0 || u.z >= a || u.y < 0 || u.y >= b || u.x < 0 || u.x >= c)
		return false;
	return true;
}
void Find(Point u){
	queue<Point> k;
	k.push(u);
	while(!k.empty()){
		Point s = k.front(); k.pop();
		if(s.x == end.x && s.y == end.y && s.z == end.z){
			cout<<s.dist<<endl;
			return;
		}
		Point tmp = moveX2(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
		tmp = moveX1(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
		tmp = moveY1(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
		tmp = moveY2(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
		tmp = moveZ1(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
		tmp = moveZ2(s);
		if(checkPoint(tmp)){
			k.push(tmp);
			map[tmp.z][tmp.y][tmp.x] = 0;
		}
	}
	cout<<"-1"<<endl;
}
int main(){
	int test; cin>>test;
	while(test--){
		cin>>a>>b>>c;
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				for(int k = 0; k < c; k++){
					char s; cin>>s;
					if(s == '.') map[i][j][k] = 1;
					if(s == '#') map[i][j][k] = 0;
					if(s == 'S'){
						Point tmp = {i, j, k, 0}; start = tmp;
						map[i][j][k] = 1;
					}
					if(s == 'E'){
						Point tmp = {i, j, k, 0}; end = tmp;
						map[i][j][k] = 1;
					}
				}
			}
		}
		Find(start);
	}
	return 0;
}