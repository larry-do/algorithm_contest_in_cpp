#include <bits/stdc++.h>
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		int idx = i;
		for(int j = i - 1; j >= 0; j--){
			if(a[idx] < a[j]){
				std::swap(a[idx], a[j]);
				idx = j;
			}
			else break;
		}
		printf("%s%d%s", "Buoc ", i, ": ");
		for(int k = 0; k <= i; k++) printf("%d ", a[k]);
		printf("\n");
	}
	return 0;
}