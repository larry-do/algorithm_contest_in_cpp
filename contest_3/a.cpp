#include <cstdio>
#include <algorithm>
long int n;
long int a[100010];
bool check(long int mid){
	int i = 0; // i kiểm tra phần dưới mid
	for(int j = mid + 1; j < n; j++){ // j kiểm tra phần trên mid
		if(a[j] >= 2*a[i]) i++;
		if(i > mid) return true;
	}
	return false;
}
long int Find(){
	long int low = -1, high = (n-1)/2, mid; // kiểm tra nửa dưới
	long int res; // res là số cặp kangs
	while(low <= high){
		mid = (low + high) / 2; // kiểu cứ kiểm tra chặt đôi ra ấy
		if(check(mid)){ // check số giữa
			res = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return n - res - 1;
}
int main(){
	int t; scanf("%d", &t);
	for(int e = 1; e <= t; e++){
		scanf("%ld", &n);
		for(long int i = 0; i < n; i++){
			scanf("%ld", &a[i]);
		}
		std::sort(a, a+n);
		printf("%ld\n", Find());
	}
	return 0;
}