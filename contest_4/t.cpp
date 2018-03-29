#include <iostream>
using namespace std;
int n;
int cost[26][26];
void init(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>cost[i][j];
		}
	}
}
int main(){
	init();
	
	return 0;
}