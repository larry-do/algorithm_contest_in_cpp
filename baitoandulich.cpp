#include <iostream>
using namespace std;
int n;
int cost[20][20], xopt[20], tmp_xopt[20];
int fopt, tmp_fopt, minOfCostMatrix;
bool checkedCity[20];
void init(){
	minOfCostMatrix = 1000000;
	fopt = 1000000;
	tmp_fopt = 0;
	tmp_xopt[1] = 1;
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>cost[i][j];
			if(i != j && cost[i][j] < minOfCostMatrix) minOfCostMatrix = cost[i][j]; 
		}
	}
	for(int i = 1; i <= n; i++){
		checkedCity[i] = false;
	}
}
void update(){
	tmp_fopt+=(cost[tmp_xopt[n]][tmp_xopt[1]]);
	if(tmp_fopt < fopt){
		fopt = tmp_fopt;
		for(int i = 1; i <= n; i++){
			xopt[i] = tmp_xopt[i];
		}
	}
	tmp_fopt-=(cost[tmp_xopt[n]][tmp_xopt[1]]);
}
void Try(int i){
	for(int j = 2; j <= n; j++){
		if(!checkedCity[j]){
			checkedCity[j] = true;
			tmp_xopt[i] = j;
			tmp_fopt+=(cost[tmp_xopt[i-1]][tmp_xopt[i]]);
			if(i == n) update();
			else if(tmp_fopt + (n - i + 1)*minOfCostMatrix < fopt){
				Try(i+1);
			}
			checkedCity[j] = false; tmp_fopt-=(cost[tmp_xopt[i-1]][tmp_xopt[i]]);
		}
	}
}
int main(){
	init();
	Try(2);
	cout<<fopt;
	return 0;
}