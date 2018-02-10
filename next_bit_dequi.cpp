#include <iostream>
using namespace std;
int a[1000] = {0}, n;
void show(){
	for(int i = 1; i <= n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n) show();
		else Try(i+1);
	}
}
int main(){
	cin>>n;
	Try(1);
	return 0;
}