#include <bits/stdc++.h>
long int n;
long int a[100009];
long int partition(long int a[], long int low, long int high){
	long int pi = a[high];
	long int i = low - 1;
	for(int j = low; j < high; j++){
		if(a[j] <= pi){
			i++;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i+1], a[high]);
	return i+1;
}
void quickSort(long int a[], long int low, long int high){
	if(low < high){
		long int pivot = partition(a, low, high);
		quickSort(a, low, pivot-1);
		quickSort(a, pivot+1, high);
	}
}
int main(){
	int test; scanf("%d", &test);
	while(test--){
		scanf("%ld", &n);
		for(int i = 0; i < n; i++) scanf("%ld", &a[i]);
		quickSort(a, 0, n-1);
		for(int i = 0; i < n; i++) printf("%ld ", a[i]);
		printf("\n");
	}
	return 0;
}