#include <iostream>
using namespace std;
int a[1000] = {0}, n, k;
void init(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}
void show(){
	for(int i = 1; i <= k; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int i){
	for(int j = a[i-1]+1; j <= n - k + i; j++){
		a[i] = j;
		if(i == k) show();
		else Try(i+1);
	}
}
int main(){
	cin>>n>>k;
	init();
	Try(1);
	return 0;
}