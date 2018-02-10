#include <iostream>
using namespace std;
int a[1000] = {0}, n;
void show_next_bit(){
	for(int i = 1; i <= n; i++){
		cout<<a[i];
	}
	cout<<endl;
}
bool next_bit(){
	int j = n;
	while(j > 0 && a[j] == 1){
		a[j] = 0;
		j--;
	}
	if(j > 0) a[j] = 1;
	else return false;
	return true;
}
int main(){
	cin>>n;
	show_next_bit();
	while(next_bit()){
		show_next_bit();
	}
	return 0;
}
