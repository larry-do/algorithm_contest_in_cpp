#include <cstdio>
#include <queue>
class point{
public:
	int x, y, step;
	point(int i, int j, int s){x = i; y = j; step = s;}
	point move1(){point t(x+1, y+2, step+1); return t;}
	point move2(){point t(x+1, y-2, step+1); return t;}
	point move3(){point t(x+2, y+1, step+1); return t;}
	point move4(){point t(x+2, y-1, step+1); return t;}
	point move5(){point t(x-1, y+2, step+1); return t;}
	point move6(){point t(x-1, y-2, step+1); return t;}
	point move7(){point t(x-2, y+1, step+1); return t;}
	point move8(){point t(x-2, y-1, step+1); return t;}
	bool check(){
		if(x >= 1 && x <= 8 && y >= 1 && y <= 8) return true;
		return false;
	}
};
int main(){
	int test; scanf("%d", &test);
	char s[4];
	while(test--){
		int a[10][10] = {0};
		scanf("%s", s);
		point start(9 - s[1] + '0', s[0] - 'a' + 1, 0);
		scanf("%s", s);
		point finish(9 - s[1] + '0', s[0] - 'a' + 1, 0);
		std::queue<point> k; k.push(start);
		a[start.x][start.y] = 1;
		while(!k.empty()){
			point s = k.front(); k.pop();
			if(s.x == finish.x && s.y == finish.y) {finish.step = s.step; break;}
			point t = s.move1();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move2();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move3();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move4();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move5();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move6();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move7();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
			t = s.move8();
			if(t.check() && !a[t.x][t.y]){k.push(t); a[t.x][t.y] = 1;}
		}
		printf("%d\n", finish.step);
	}
	return 0;
}