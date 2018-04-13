#include <bits/stdc++.h>
struct Point{
	long int data, pos;
};
long int n;
Point a[100009];
bool compare(Point x, Point y){
	return x.data < y.data;
}
int main(){
	int test; scanf("%ld", &test);
	while(test--){
		scanf("%ld", &n);
		for(int i = 0; i < n; i++){
			scanf("%ld", &a[i].data);
			a[i].pos = i;
		}
		std::sort(a, a+n, compare);
		long int low = INT_MAX, high = -1;
		for(int i = 0; i < n; i++){
			if(a[i].pos != i){
				low = std::min(low, a[i].pos);
				high = std::max(high, a[i].pos);
			}
		}
		if(high == -1) printf("YES\n");
		else printf("%ld\n", high - low + 1);
	}
	return 0;
}