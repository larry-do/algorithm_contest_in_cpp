#include <cstdio>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
long int n;
long int a[100009];
long int b[100009];
int main(){
	scanf("%ld", &n);
	Loop(i, 1, n) scanf("%ld", &a[i]);
	Loop(i, 1, n) scanf("%ld", &b[i]);
	return 0;
}