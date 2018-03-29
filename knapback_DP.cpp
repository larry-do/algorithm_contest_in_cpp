#include <iostream>
using namespace std;
int n, w, a[100], c[100];
int f[100][100];
void init(){
	cin>>n>>w;
	for(int i = 1; i <= n; i++){
		cin>>a[i]>>c[i];
	}
	for(int i = 0; i <= w; i++){
		f[0][i] = 0;
	}
}
void Dynamic_Programming(){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= w; j++){
			f[i][j] = f[i-1][j];
			if(j >= a[i] && f[i][j] < f[i-1][j - a[i]] + c[i]){
				f[i][j] = f[i-1][j - a[i]] + c[i];
			}
		}
	}
}
void Trace(){ // truy vết ngược để tìm phương án chọn khi đã có giá trị tối ưu
	cout<<f[n][w]<<endl;
	while(n != 0){
		if(f[n][w] != f[n-1][w]){
			cout<<n<<' ';
			w-=a[n];
			n--;
		}
	}
}
int main(){
	init();
	Dynamic_Programming();
	Trace();
	return 0;
}