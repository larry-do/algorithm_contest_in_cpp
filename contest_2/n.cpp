#include <iostream>
#include <cmath>
using namespace std;
long int c[11];
long int k[11];
int a[11] = {0};
int n;
long int rs = 1000000000;
void init(){
	cin>>n;
	int i;
	for(i = 0; i < n; i++){
		cin>>c[i]>>k[i];
	}
}
int next_bit(){
	int i = n - 1;
	while(i>=0 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i>=0) a[i] = 1;
	else return 0;
	return 1;
}
void calculate(){
	int i;
	long int C = 1, K = 0;
	for(i = 0; i < n; i++){
		if(a[i]){
			C*=c[i];
			K+=k[i];
		}	
	}
	long int tmp = abs(C-K);
	if(tmp < rs) rs = tmp;
}
int main()
{
	init();
	while(next_bit()){
		calculate();
	}
	cout<<rs;
    return 0;
}