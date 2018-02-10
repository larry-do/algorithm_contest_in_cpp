#include <iostream>
using namespace std;
int a[1000], n;
void swap(int &a, int &b){
	int tmp = a; a = b; b = tmp;
}
void init(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}
void show_next_permunation(){
	for(int i = 1; i <= n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
bool next_permunation(){
	int j = n - 1;
	while(j > 0 && a[j] > a[j+1]) j--;
	if(j > 0){
		int k = n;
		while(a[j] > a[k]) k--;
		swap(a[j], a[k]);
		int r = j + 1, s = n;
		while(r <= s){
			swap(a[r], a[s]);
			r++; s--;
		}
	}
	else return false;
	return true;
}
int main(){
	cin>>n;
	init();
	show_next_permunation();
	while(next_permunation()){
		show_next_permunation();
	}
	return 0;
}