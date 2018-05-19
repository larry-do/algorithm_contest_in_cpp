#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
struct point{
	double x, y;
};
int n;
point a[101];
bool check[101];
void init(){
	cin>>n;
	Loop(i, 1, n){
		check[i] = false;
		cin>>a[i].x>>a[i].y;
	}
}
double dist(point a, point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double Find(){
	check[1] = true; // bat dau tu 1
	double res = 0;
	Loop(k, 1, n-1){ // n dinh thif cos n canhj
		int u = 1;
		double _min = 1e9+7;
		Loop(i, 1, n){
			if(check[i]){
				Loop(j, 2, n){
					if(!check[j] && _min > dist(a[i], a[j])){
						_min = dist(a[i], a[j]);
						u = j;
					}
				}
			}
		}
		check[u] = true;
		res += _min;
	}
	return res;
}
int main(){
	int test; cin>>test;
	while(test--){
		init();
		cout<<setprecision(6)<<fixed<<Find()<<endl;
	}
	return 0;
}
