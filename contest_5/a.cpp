#include <bits/stdc++.h>
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++){
		int idx = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[idx]) idx = j;
		}
		std::swap(a[i], a[idx]);
		printf("%s%d%s", "Buoc ", i+1, ": ");
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}