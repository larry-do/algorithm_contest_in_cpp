#include <iostream>
using namespace std;
int a[1000] = {0}, n;
bool uncheck[1000];
void init(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
		uncheck[i] = true;
	}
}
void show(){
	for(int i = 1; i <= n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int i){
	for(int j = 1; j <= n; j++){
		if(uncheck[j]){
			uncheck[j] = false;
			a[i] = j;
			if(i == n) show();
			else Try(i+1);
			uncheck[j] = true;
		}
	}
}
int main(){
	cin>>n;
	init();
	Try(1);
	return 0;
}