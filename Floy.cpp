#include <iostream>
#define MAX_VALUE 32000
using namespace std;
int n, start, finish;
int a[50][50], dist[50][50], trace[50][50];
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
		for(int j = 1; j <= n; j++){
			dist[i][j] = a[i][j];
			if(dist[i][j] == MAX_VALUE) trace[i][j] = 0;
			else trace[i][j] = j;
		}
	}
}
void runFloy(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(dist[j][i] != MAX_VALUE && dist[j][k] > dist[j][i] + dist[i][k]){
					dist[j][k] = dist[j][i] + dist[i][k];
					trace[j][k] = trace[j][i];
				}
			}
		}
	}
}
void showResult(){
	cout<<"Start: "<<start<<endl;
	cout<<"Finish: "<<finish<<endl;
	if(dist[start][finish] >= MAX_VALUE){
		cout<<"Couldn't find the path."<<endl;
		return;
	}
	else{
		cout<<"Minimum distance: "<<dist[start][finish]<<endl;
		cout<<"The shortest path: ";
		while(start != finish){
			cout<<start<<" ";
			start = trace[start][finish];
		}
		cout<<finish<<endl;
	}
}
int main(){
	Initialize();
	runFloy();
	showResult();
	return 0;
}