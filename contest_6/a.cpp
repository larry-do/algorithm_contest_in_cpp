#include <cstdio>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
int main(){
	int n; scanf("%d", &n);
	int a;
	Loop(i, 1, n){
		Loop(j, 1, n){
			scanf("%d", &a);
			if(a) printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}