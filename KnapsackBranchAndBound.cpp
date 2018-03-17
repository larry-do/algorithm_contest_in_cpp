// đây là bài toán cái túi có nhiều hơn cùng 1 loại đồ vật
#include <iostream>
using namespace std;
int a[1000], c[1000], x[1000], xopt[1000];
int n, weight, fopt, remainWeight, cost;
void init(){
	cin>>n>>weight;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
	}
	fopt = 0; remainWeight = weight;
	cost = 0;
}
void show(){
	cout<<fopt<<endl;
	for(int i = 1; i <= n; i++){
		cout<<xopt[i]<<" ";
	}
}
void update(){
	if(cost > fopt){
		fopt = cost;
		for(int i = 1; i <= n; i++){
			xopt[i] = x[i];
		}
	}
}
void Try(int i){
	int t = (int)remainWeight/a[i];
	for(int j = t; j >= 0; j--){
		x[i] = j;
		remainWeight-=(a[i]*x[i]);
		cost+=(c[i]*x[i]);
		if(i == n) update();
		else if(cost + c[i+1]*remainWeight/a[i+1] > fopt) Try(i+1);
		remainWeight+=(a[i]*x[i]);
		cost-=(c[i]*x[i]);
	}
}
int main(){
	init();
	Try(1);
	show();
	return 0;
}