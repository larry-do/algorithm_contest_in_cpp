#include <iostream>
using namespace std;
int a[1000] = {0}, n, k;
void init(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}
void show_next_combination(){
	for(int i = 1; i <= k; i++){
		cout<<a[i];
	}
	cout<<endl;
}
bool next_combination(){
	int j = k;
	while(j > 0 && a[j] == n - k + j) j--;
	if(j > 0){
		a[j]++;
		for(int i = j + 1; i <= k; i++){
			a[i] = a[i-1] + 1;
		}
	}
	else return false;
	return true;
}
int main(){
	cin>>n>>k;
	init();
	show_next_combination();
	while(next_combination()){
		show_next_combination();
	}
	return 0;
}
