#include <cstdio>
long int k = 0;
long int *a;
void Try(long int i, long int j){
	while(i < j){
		if(a[i] < a[j]){
			a[i+1]+=a[i]; k++;
			if(a[i+1] != a[j]) i++;
			else {i+=2; j--;}
		}
		else if(a[i] > a[j]){
			a[j-1]+=a[j]; k++;
			if(a[i] != a[j-1]) j--;
			else {i++; j-=2;}
		}
		else {i++; j--;}
	}
	/*
	if(i > j) return;
	if(a[i] < a[j]){
		a[i+1]+=a[i]; k++;
		if(a[i+1] != a[j]) Try(i+1, j);
		else Try(i+2, j-1);
	}
	else if(a[i] > a[j]){
		a[j-1]+=a[j]; k++;
		if(a[i] != a[j-1]) Try(i, j-1);
		else Try(i+1, j-2);
	}
	else Try(i+1, j-1);
	*/
}
int main(){
	long int n; scanf("%ld", &n);
	a = new long int[n+1];
	for(long int i = 1; i <= n; i++){
		scanf("%ld", &a[i]);
	}
	Try(1, n);
	printf("%ld", k);
	delete(a);
	return 0;
}