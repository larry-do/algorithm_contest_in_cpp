#include <bits/stdc++.h>
#define up 1
#define down 2
#define left 3
#define right 4
#define _default 0
using namespace std;
struct point{
	int i, j, w, move;
};
int n, m;
bool check[509][509];
point s, f;
void init(){
	cin>>n>>m;
	memset(check, 0, sizeof(check));
	char a;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>a;
			if(a == '*') check[i][j] = true;
			else if(a == 'S'){
				s.i = i; s.j = j; s.w = 0; s.move = _default;
				check[i][j] = true;
			}
			else if(a == 'T'){
				f.i = i; f.j = j; f.w = 0; f.move = _default;
			}
		}
	}
	for(int i = 0; i <= n+1; i++){
		check[i][0] = true; check[i][m+1] = true;
	}
	for(int i = 0; i <= m+1; i++){
		check[0][i] = true; check[n+1][i] = true;
	}
}
bool find(){
	queue<point> k;
	if(!check[++s.i][s.j]){
		s.move = down;
		check[s.i][s.j] = true;
		k.push(s);
		--s.i;
	}
	if(!check[--s.i][s.j]){
		s.move = up;
		check[s.i][s.j] = true;
		k.push(s);
		++s.i;
	}
	if(!check[s.i][++s.j]){
		s.move = right;
		check[s.i][s.j] = true;
		k.push(s);
		--s.j;
	}
	if(!check[s.i][--s.j]){
		s.move = left;
		check[s.i][s.j] = true;
		k.push(s);
		++s.j;
	}
	while(!k.empty()){
		point t = k.front();
		//cout<<t.i<<" "<<t.j<<endl;
		if(t.i == f.i && t.j == f.j) return true;
		if(!check[++t.i][t.j]){
			if(t.move != down){
				t.move = down; t.w++;
			}
			if(t.w <= 2){
				check[t.i][t.j] = true;
				k.push(t);
			}
		}
		t.i = k.front().i; t.j = k.front().j; t.w = k.front().w; t.move = k.front().move;
		if(!check[--t.i][t.j]){
			if(t.move != up){
				t.move = up; t.w++;
			}
			if(t.w <= 2){
				check[t.i][t.j] = true;
				k.push(t);
			}
		}
		t.i = k.front().i; t.j = k.front().j; t.w = k.front().w; t.move = k.front().move;
		if(!check[t.i][++t.j]){
			if(t.move != right){
				t.move = right; t.w++;
			}
			if(t.w <= 2){
				check[t.i][t.j] = true;
				k.push(t);
			}
		}
		t.i = k.front().i; t.j = k.front().j; t.w = k.front().w; t.move = k.front().move;
		if(!check[t.i][--t.j]){
			if(t.move != left){
				t.move = left; t.w++;
			}
			if(t.w <= 2){
				check[t.i][t.j] = true;
				k.push(t);
			}
		}
		k.pop();
	}
	return false;
}
int main(){
	int test; cin>>test;
	while(test--){
		init();
		if(find()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
