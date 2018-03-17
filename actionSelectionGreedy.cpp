#include <iostream>
#include <algorithm>
using namespace std;
int partition(int a[], int b[], int low, int high){
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j < high; j++){
		if(a[j] <= pivot){
			i++;
			swap(a[j], a[i]);
			swap(b[j], b[i]);
		}
	}
	swap(a[i+1], a[high]);
	swap(b[i+1], b[high]);
	return i+1;
}
void quickSort(int a[], int b[], int low, int high){
	if(low < high){
		int pi = partition(a, b, low, high);
		quickSort(a, b, low, pi - 1);
		quickSort(a, b, pi + 1, high);
	}
}
int showMaxAct(int s[], int f[], int n){
	quickSort(f, s, 0, n-1);
	int res = 0, i = 0;
	//cout<<i<<" "; 
	res++;
	for(int j = 1; j < n; j++){
		if(f[i] <= s[j]){
			i = j;
			//cout<<i<<" ";
			res++;
		}
	}
	return res;
}
int main(){
	int n; cin>>n;
	for(int i = 0; i < n; i++){
		int k; cin>>k;
		int s[k], f[k];
		for(int i = 0; i < k; i++){
			cin>>s[i]>>f[i];
		}
		cout<<showMaxAct(s, f, k)<<endl;
	}
	return 0;
}