// Chú ý chú ý!!!!!!!!!!
// Không khi sinh ra các tổ hợp dấu, ta không cần hoán vị dấu này
// Bỏ đi
#include <iostream>
#include <algorithm>
using namespace std;
int n = 5;
int x[10];
int a[10];
int b[10];
int y[10];
bool check = false;
const int NUM = 23;
int res = 0;
void init_a(){
	for(int i = 1; i <= n; i++){
		cin>>x[i];
	}
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}
void init_b(){
	for(int i = 1; i <= n-1; i++){
		b[i] = i;
	}
}
bool next_permunation_b(){
	int j = n - 2;
	while(j > 0 && b[j] > b[j+1]) j--;
	if(j > 0){
		int k = n-1;
		while(b[j] > b[k]) k--;
		swap(b[j], b[k]);
		int r = j + 1, s = n-1;
		while(r <= s){
			swap(b[r], b[s]);
			r++; s--;
		}
	}
	else return false;
	return true;
}
void calculate(){
	int res = x[a[1]];
	if(y[b[1]] == 0) res+=x[a[2]];
	if(y[b[1]] == 1) res-=x[a[2]];
	if(y[b[1]] == 2) res*=x[a[2]];
	if(y[b[2]] == 0) res+=x[a[3]];
	if(y[b[2]] == 1) res-=x[a[3]];
	if(y[b[2]] == 2) res*=x[a[3]];
	if(y[b[3]] == 0) res+=x[a[4]];
	if(y[b[3]] == 1) res-=x[a[4]];
	if(y[b[3]] == 2) res*=x[a[4]];
	if(y[b[4]] == 0) res+=x[a[5]];
	if(y[b[4]] == 1) res-=x[a[5]];
	if(y[b[4]] == 2) res*=x[a[5]];
	if(res == NUM) check = true;
}
void handle(){
	init_b();
	calculate();
	while(next_permunation_b()){
		calculate();
	}
}
void Try(int i){
	for(int j = 0; j <= 2; j++){
		y[i] = j;
		if(i == n - 1) handle();
		else Try(i+1);
	}
}
bool next_permunation_a(){
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
	int t; cin>>t;
	for(int r = 1; r <= t; r++){
		init_a();
		Try(1);
		while(next_permunation_a()){
			Try(1);
		}
		if(check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		check = false;
	}
	return 0;
}