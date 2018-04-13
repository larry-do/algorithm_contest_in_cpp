#include <stdio.h>
#include <algorithm>
#define loop(x, n) for(long long x = 0; x < n; x++)
typedef long long i64;
i64 n, a[100009];
i64 min(i64 x, i64 y){return (x<y)?x:y;}
void mergeArray(i64 arr[], i64 low, i64 mid, i64 high){
	i64 len1 = mid - low + 1;
	i64 len2 = high - mid;
	i64 *L = new i64[len1];
	i64 *R = new i64[len2];
	loop(i, len1) L[i] = arr[low + i];
	loop(i, len2) R[i] = arr[mid + 1 + i];
	int i = 0, j = 0, k = low;
	while(i < len1 && j < len2){
		if(L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	while(i < len1) arr[k++] = L[i++];
	while(j < len2) arr[k++] = R[j++];
}
void mergeSort(i64 arr[], i64 low, i64 high){
	if(low < high){
		i64 mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		mergeArray(arr, low, mid, high);
	}
}
int main(){
	scanf("%lld", &n);
	loop(i, n) scanf("%lld", &a[i]);
	mergeSort(a, 0, n-1);
	loop(i, n) printf("%lld ", a[i]);
	printf("\n");
	return 0;
}