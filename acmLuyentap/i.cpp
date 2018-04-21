#include <cstdio>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
int n;
int a[5005];
int main(){
	scanf("%d", &n);
	Loop(i, 1, n) scanf("%d", &a[i]);
	
	return 0;
}