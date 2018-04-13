#include <bits/stdc++.h>
#define MAX 50
using namespace std;
int cost[MAX][MAX], check[MAX], xopt[MAX], tmp_x[MAX];
int n, fopt, tmp_f, minCost;
void init(){
	minCost = INT_MAX;
	fopt = INT_MAX;
	tmp_f = 0;
	tmp_x[1] = 1;
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>cost[i][j];
			if(i != j) minCost = min(minCost, cost[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) check[i] = 1;
}
void update(){
	tmp_f += cost[tmp_x[n]][tmp_x[1]];
	if(tmp_f < fopt){
		fopt = tmp_f;
		for(int i = 1; i <= n; i++) xopt[i] = tmp_x[i];
	}
	tmp_f -= cost[tmp_x[n]][tmp_x[1]];
}
void Try(int i){
	for(int j = 2; j <= n; j++){
		if(check[j]){
			check[j] = 0; tmp_x[i] = j;
			tmp_f += cost[tmp_x[i-1]][tmp_x[i]];
			if(i == n) update();
			else if(tmp_f + (n - i + 1) * minCost < fopt) Try(i+1);
			check[j] = 1; tmp_f -= cost[tmp_x[i-1]][tmp_x[i]];
		}
	}
}
int main(){
	init();
	Try(2);
	cout<<fopt;
	return 0;
}