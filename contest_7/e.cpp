#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
struct point{
	float x, y;
};
int n;
point a[101];
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n;
		Loop(i, 1, n){
			cin>>a[i].x>>a[i].y;
		}
		
	}
	return 0;
}
