#include <cstdio>
// vẫn khó hiểu quá
int findTheStart(long int a[], long int c[], long int n){
	long int start = 0, end = 1;
	long long gas = a[start] - c[start];
	while(gas < 0 || start != end){
		while(gas < 0 && start != end){ 
			gas -= (a[start] - c[start]);
			start = (start + 1) % n;
			if(start == 0) return -1;
		}
		gas += (a[end] - c[end]);
		end = (end + 1) % n;
	}
	return start;
}
int main(){
	int t; scanf("%d", &t);
	for(int e = 1; e <= t; e++){
		long int n; scanf("%ld", &n);
		long int a[n], c[n];
		for(long int i = 0; i < n; i++){
			scanf("%ld%ld", &a[i], &c[i]);
		}
		if(findTheStart(a, c, n) >= 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}