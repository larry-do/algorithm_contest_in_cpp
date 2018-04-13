#include <bits/stdc++.h>
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++){
		bool check = true;
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j+1]) {
				check = false;
				std::swap(a[j], a[j+1]);
			}
		}
		if(check) break;
		printf("%s%d%s", "Buoc ", i+1, ": ");
		for(int k = 0; k < n; k++) printf("%d ", a[k]);
		printf("\n");
	}
	return 0;
}