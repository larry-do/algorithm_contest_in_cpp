#include <iostream>
using namespace std;
int matrix[100][100];
int n;
int isNotUsed[100];
void init(){
	cin>>n;
	for(int i = 0; i < n; i++){
		isNotUsed[i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>matrix[i][j];
		}
	}
}
void Try(int node){
	cout<<node<<" "; isNotUsed[node] = 0;
	for(int i = 0; i < n; i++){
		if(matrix[node][i] && isNotUsed[i]){
			Try(i);
		}
	}
}
void DFS_Stack(int node){
	int stack[100];
	int head = 0;
	stack[head] = node; isNotUsed[node] = 0;
	cout<<node<<" ";
	while(head >= 0){
		int s = stack[head--];
		for(int i = 0; i < n; i++){
			if(matrix[s][i] && isNotUsed[i]){
				cout<<i<<" "; isNotUsed[i] = 0;
				stack[++head] = s;
				stack[++head] = i;
				break;
			}
		} 
	}
}
int main(){
	init();
	DFS_Stack(2);
	return 0;
}