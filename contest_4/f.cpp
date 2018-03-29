#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, m;
short matrix[510][510];
int nleft[510];
int nright[510];
void Find_Right(int sum[]){
	stack<int> k;
	for(int i = 1; i <= m; i++){
		while(k.size() > 0 && sum[k.top()] > sum[i]){
			nright[k.top()] = i; k.pop();
		}
		k.push(i);
	}
	while(k.size() > 0){
		nright[k.top()] = m+1; k.pop();
	}
}
void Find_Left(int sum[]){
	stack<int> k;
	for(int i = m; i >= 1; i--){
		while(k.size() > 0 && sum[k.top()] > sum[i]){
			nleft[k.top()] = i; k.pop();
		}
		k.push(i);
	}
	while(k.size() > 0){
		nleft[k.top()] = 0; k.pop();
	}
}
void Find(int sum[]){
	long int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(matrix[i][j]) sum[j]++;
			else sum[j] = 0;
		}
		Find_Right(sum);
		Find_Left(sum);
		for(int i = 1; i <= m; i++){
			long int area = sum[i] * (nright[i] - nleft[i] - 1);
			res = max(res, area);
		}
	}
	cout<<res<<endl;
}
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n>>m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin>>matrix[i][j];
			}
		}
		int sum[510] = {0};
		Find(sum);
	}
	return 0;
}