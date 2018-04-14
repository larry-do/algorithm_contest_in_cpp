#include <iostream>
using namespace std;
#define MAX_VALUE 32000
int a[50][50], dist[50], trace[50];
int n, start, finish;
void Initialize(){
	n = 7;
	start = 7; finish = 5;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = MAX_VALUE;
		}
		a[i][i] = 0;
	}
	a[1][2] = -7 ;
	a[1][3] = -1 ;
	a[1][4] = 2 ;
	a[3][5] = -4 ;
	a[3][6] = -1 ;
	a[4][3] = -1 ;
	a[4][2] = -1 ;
	a[4][6] = 1 ;
	a[7][3] = 3 ;
	a[4][6] = 1 ;
	a[5][4] = 8 ;
//	a[5][4] = 3; // add this edge to make a negative cycle 
	a[6][5] = -5 ;	
	a[7][1] = 2 ;
	a[7][2] = 5 ;
	for(int i = 1; i <= n; i++){
		dist[i] = a[start][i];
		trace[i] = start;
	}
}
void showResult(){
	cout<<"Start: "<<start<<endl;
	cout<<"Finish: "<<finish<<endl;
	for(int v = 1; v <= n; v++){
		for(int u = 1; u <= n; u++){
			if(dist[v] > dist[u] + a[u][v]){
				cout<<"Couldn't find path due to negative cycle."<<endl;
				return;
			}
		}
	}
	cout<<"Minimum distance: "<<dist[finish]<<endl;
	cout<<"The shortest path: ";
	while(finish != start){
		cout<<finish<<" ";
		finish = trace[finish];
	}
	cout<<start<<endl;
}
void runBellman_Ford(){
	dist[start] = 0;
	for(int i = 1; i <= n-2; i++){
		for(int v = 1; v <= n; v++){
			for(int u = 1; u <= n; u++){
				if(dist[v] > dist[u] + a[u][v]){
					dist[v] = dist[u] + a[u][v];
					trace[v] = u;
				}
			}
		}
	}
}
int main(){
	Initialize();
	runBellman_Ford();
	showResult();
	return 0;
}
