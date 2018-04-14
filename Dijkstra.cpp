#include <stdio.h>
#define MAX_VALUE 32000
int n, start, finish;
int a[50][50], dist[50], previousVertex[50];
bool checkVertex[50];
void Initialize(){
	n = 13; start = 1; finish = 13;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			a[i][j] = MAX_VALUE;
		}
		a[i][i] = 0;
	}
	a[1][2] = 2; a[1][3] = 8;
	a[2][3] = 2; a[2][7] = 9;
	a[3][4] = 6; a[3][6] = 8; a[3][7] = 1;
	a[4][1] = 7;
	a[5][3] = 1; a[5][4] = 7;
	a[6][5] = 1; a[6][8] = 9; a[6][9] = 8;
	a[7][6] = 2; a[7][8] = 2;
	a[8][9] = 9; a[8][12] = 2;
	a[9][10] = 6; a[9][12] = 9; a[9][13] = 8;
	a[10][5] = 7; a[10][6] = 6;
	a[11][9] = 6; a[11][10] = 7;
	a[12][13] = 2;
	a[13][11] = 7;
	for(int i = 1; i <= n; i++){
		dist[i] = a[start][i];
		previousVertex[i] = start;
		checkVertex[i] = false;
	}
	previousVertex[start] = 0;
	dist[start] = 0;
	checkVertex[start] = true;
}
void showResult(){
	printf("Start: %d\n", start);
	printf("Finish: %d\n", finish);
	printf("Minimum Distance: %d\n", dist[finish]);
	printf("The Shortest Path: \n");
	while(finish != start){
		printf("%d ", finish);
		finish = previousVertex[finish];
	}
	printf("%d\n", start);
}
void runDijkstra(){
	while(!checkVertex[finish]){
		int u = 0, minDist = MAX_VALUE;
		for(int i = 1; i <= n; i++){
			if(!checkVertex[i] && minDist > dist[i]){
				minDist = dist[i];
				u = i;
			}
		}
		checkVertex[u] = true;
		if(!checkVertex[finish]){
			for(int i = 1; i <= n; i++){
				if(!checkVertex[i] && dist[i] > dist[u] + a[u][i]){
					dist[i] = dist[u] + a[u][i];
					previousVertex[i] = u;
				}
			}
		}
	}
}
int main(){
	Initialize();
	runDijkstra();
	showResult();
	return 0;
}