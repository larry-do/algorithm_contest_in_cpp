#include <stdio.h>
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	bool a[n+1] = {0};
	for(int i = 1; i <= m; i++){
		int b; scanf("%d", &b);
		for(int j = b - k; j <= b + k; j++){
			if(j >= 1 && j <= n) a[j] = 1;
		}
	}
	int res = 0, i = 1, j;
	k = 2*k + 1;
	while(i <= n){
		if(!a[i]){
			j = i;
			while(j <= n && !a[j]) j++;
			res += ((j-i)/k + (((j-i)%k) ? 1 : 0));
			i = j;
		}
		i++;
	}
	printf("%d", res);
	return 0;
}