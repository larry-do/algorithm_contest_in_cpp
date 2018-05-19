#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
long int n, m;
long int a[109][109];
long int dist[109][109];
int main(){
	cin>>n>>m;
	Loop(i, 1, n){
		Loop(j, 1, n){
			a[i][j] = 1010000;
		}
	}
	Loop(i, 1, m){
		long int x, y, z; cin>>x>>y>>z;
		a[x][y] = z;
		a[y][x] = z;
	}
	Loop(i, 1, n){
		Loop(j, 1, n){
			dist[i][j] = a[i][j];
		}
	}
	Loop(k, 1, n){
		Loop(i, 1, n){
			Loop(j, 1, n){
				if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != 1010000){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	long int q, x, y; cin>>q;
	Loop(i, 1, q){
		cin>>x>>y;
		if(x == y) cout<<0<<endl;
		else cout<<dist[x][y]<<endl;
	}
	return 0;
}
