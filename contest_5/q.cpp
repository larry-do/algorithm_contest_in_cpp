#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[110];
int s[100009];
int main(){
	int test; cin>>test;
	while(test--){
		cin>>n>>k;
		for(int i = 0; i < n; i++) cin>>a[i];
		memset(s, 0, sizeof(s));
		s[0] = 1;
		for(int i = 0; i < n; i++){
			for(int j = k; j >= a[i]; j--){
				if(s[j] == 0 && s[j - a[i]] == 1) s[j] = 1;
			}
		} 
		cout<<(s[k] ? "YES":"NO")<<endl;
	}
	return 0;
}