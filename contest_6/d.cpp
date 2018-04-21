#include <iostream>
using namespace std;
#define LOOP(i, s, f) for(int i = s; i <= f; i++)
int r, c;
int a[55][55] = {0};
char b[55][55] = {0};
int check(int i, int j){
	int res = 0;
	if(b[i+1][j-1] == 'o') res++;
	if(b[i+1][j] == 'o') res++;
	if(b[i+1][j+1] == 'o') res++;
	if(b[i][j-1] == 'o') res++;
	if(b[i][j+1] == 'o') res++;
	if(b[i-1][j-1] == 'o') res++;
	if(b[i-1][j] == 'o') res++;
	if(b[i-1][j+1] == 'o') res++;
	return res;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>r>>c;
	LOOP(i, 1, r){
		LOOP(j, 1, c){
			cin>>b[i][j];
		}
	}
	int n = 0, m = 0, sum = 0, max = 0;
	LOOP(i, 1, r){
		LOOP(j, 1, c){
			a[i][j] = check(i, j);
			if(b[i][j] == 'o') sum += a[i][j];
			if(max < a[i][j] && b[i][j] != 'o'){n = i; m = j; max = a[i][j];}
		}
	}
	cout<<sum/2+max;
	return 0;
}