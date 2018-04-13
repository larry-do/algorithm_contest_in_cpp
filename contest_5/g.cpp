#include <bits/stdc++.h>
long int n;
long int a[100009];
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%ld", &n);
		for(int i = 0; i < n; i++) scanf("%ld", &a[i]);
		std::sort(a, a + n);
		std::map<long int, long int> k;
		for(int i = 0; i < n - 1; i++){
			k[a[i+1] - a[i]]++;
		}
		std::map<long int, long int>::iterator m = k.begin();
		printf("%ld %ld\n", m->first, m->second);
	}
	return 0;
}