#include <iostream>
using namespace std;
short k[40011] = {0}; //boolean
int main(){
	long int n, s;
	cin>>n>>s;
	int a[n+1];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	k[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = s; j >= a[i]; j--){
			if(k[j] == 0 && k[j - a[i]] == 1) k[j] = 1;
		}
	}
	if(k[s] == 1) cout<<"YES";
	else cout<<"NO";
	return 0;
}