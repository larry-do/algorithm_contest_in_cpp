#include <cstdio>
#include <queue>
class point{
public:
	int x, y;
	point(int i, int j){x = i; y = j;}
	point move1(){
		point t(x-1, y); return t;
	}
	point move2(){
		point t(x+1, y); return t;
	}
	point move3(){
		point t(x, y-1); return t;
	}
	point move4(){
		point t(x, y+1); return t;
	}
};
class dot{
public:
	short data;
	short up, down, left, right;
	dot(){up = 0; down = 0; left = 0; right = 0; data = 0;}
};
int n, k, m;
dot map[110][110];
dot fake[110][110];
long int Find(point a){
	long int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			fake[i][j] = map[i][j];
		}
	}
	fake[a.x][a.y].data = 1;
	std::queue<point> st; st.push(a);
	while(!st.empty()){
		point s = st.front(); st.pop();
		point t(0, 0);
		t = s.move1();
		if(!fake[s.x][s.y].up && s.x > 1 && fake[t.x][t.y].data != 1){
			st.push(t);
			if(fake[t.x][t.y].data == 2) res++;
			fake[t.x][t.y].data = 1;
		}
		t = s.move2(); 
		if(!fake[s.x][s.y].down && s.x < n && fake[t.x][t.y].data != 1){
			st.push(t);
			if(fake[t.x][t.y].data == 2) res++;
			fake[t.x][t.y].data = 1;
		}
		t = s.move3(); 
		if(!fake[s.x][s.y].left && s.y > 1 && fake[t.x][t.y].data != 1){
			st.push(t);
			if(fake[t.x][t.y].data == 2) res++;
			fake[t.x][t.y].data = 1;
		}
		t = s.move4();
		if(!fake[s.x][s.y].right && s.y < n && fake[t.x][t.y].data != 1){
			st.push(t);
			if(fake[t.x][t.y].data == 2) res++;
			fake[t.x][t.y].data = 1;
		}
	}
	return res;
}
int main(){
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= m; i++){
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		if(a == c && b < d){
			map[a][b].right = 1; map[c][d].left = 1;
		}
		if(a == c && b > d){
			map[a][b].left = 1; map[c][d].right = 1;
		}
		if(b == d && a < c){
			map[a][b].down = 1; map[c][d].up = 1;
		}
		if(b == d && a > c){
			map[a][b].up = 1; map[c][d].down = 1;
		}
	}
	std::queue<point> st;
	for(int i = 1; i <= k; i++){
		int a, b; scanf("%d%d", &a, &b);
		map[a][b].data = 2;
		point t(a, b);
		st.push(t);
	}
	long int res = 0;
	while(!st.empty()){
		res += Find(st.front());
		st.pop();
	}
	printf("%ld", ((k*(k-1)) - res)/2);
	return 0;
}