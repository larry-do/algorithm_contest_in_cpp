#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m;
short matrix[510][510];
int *nleft;
int *nright;
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
void Find(){
	int res = 0;
	int *sum = new int[510];
	nright = new int[510];
	nleft = new int[510];
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(matrix[i][j]) sum[j]++;
			else sum[j] = 0;
		}
		Find_Right(sum);
		Find_Left(sum);
		for(int i = 1; i <= m; i++){
			res = max(res, min(sum[i], nright[i] - nleft[i] - 1));
		}
	}
	delete[] sum; delete[] nright; delete[] nleft;
	printf("%d\n", res);
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		Find();
	}
	return 0;
}