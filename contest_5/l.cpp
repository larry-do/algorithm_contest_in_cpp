#include <bits/stdc++.h>
using namespace std;
struct Person{
	long int x, y;
};
int n;
Person a[110];
bool compare(Person k, Person m){
	return k.x < m.x;
}
int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a, a+n, compare);
	long int res = a[0].x + a[0].y;
	for(int i = 1; i < n; i++){
		if(res >= a[i].x) res += a[i].y;
		else res = a[i].x + a[i].y;
	}
	cout<<res;
	return 0;
}