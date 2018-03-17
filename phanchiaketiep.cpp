//phân chia kế tiếp
#include <iostream>
using namespace std;
int n, k, a[1000];
void show(){
	for(int i = 1; i <= k; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
bool next_division(){
	int i = k, R, S, D;
	while(i > 0 && a[i] == 1) i--;
	if(i > 0){
		a[i]--;
		D = k - i + 1;
		R = D / a[i];
		S = D % a[i];
		k = i;
		if(R > 0){
			for(int j = i + 1; j <= i + R; j++) 
				a[j] = a[i];
			k+=R;
		}
		if(S > 0){
			k++; a[k] = S;
		}
	}
	else return false;
	return true;
}
int main(){
	cin>>n; k = 1; a[k] = n;
	show();
	while(next_division()){
		show();
	}
	return 0;
}