#include <cstdio>
long int a[1000][1000];
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	if(n == 2){
		printf("1 1"); return 0;
	}
	for(int i = 0; i < n; i++){
		long int sum, substract;
		int a1 = i, a2 = i+1, a3 = i+2;
		if(a2 >= n){
			a2 = 0; a3 = 1;
		}
		if(a3 >=n && a2 < n) a3 = 0;
		sum = a[a1][a2];
		substract = a[a1][a3] - a[a2][a3];
		printf("%d ", (sum+substract)/2);
	}
	return 0;
}