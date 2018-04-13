#include <bits/stdc++.h>
using namespace std;
int n;
long int a[110];
long int b[110];
int main(){
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++) cin>>b[i];
	sort(a, a+n);
	sort(b, b+n);
	bool check = true;
	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			check = false;
			break;
		}
	}
	cout<<((check) ? "YES":"NO");
	return 0;
}