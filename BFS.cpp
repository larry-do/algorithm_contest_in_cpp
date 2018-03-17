#include <iostream>
using namespace std;
int n;
int matrix[100][100];
int isNotUsed[100];
void init(){
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>matrix[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		isNotUsed[i] = 1;
	}
}
void BFS(int node){
	int queue[100];
	int low = 0, high = 0;
	queue[low] = node;
	isNotUsed[node] = 0;
	while(low <= high){
		int s = queue[low++];
		cout<<s<<" ";
		for(int i = 0; i < n; i++){
			if(matrix[s][i] && isNotUsed[i]){
				queue[++high] = i;
				isNotUsed[i] = 0;
			}
		}
	}
}
int main(){
	init();
	BFS(2);
}