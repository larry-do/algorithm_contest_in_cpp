#include <stdio.h>
int main(){
	int a[26] = {0}, b[26] = {0};
	for(int i = 1; i <= 52; i++){
		char c; scanf("%c", &c);
		if(a[c - 'A']) b[c - 'A'] = i;
		else a[c - 'A'] = i;
	}
	long int res = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(a[i] < a[j] && b[i] < b[j] && b[i] > a[j]){
				res++;
				//printf("%c %c\n", i + 'A', j + 'A');
			}
		}
	}
	printf("%ld", res);
	return 0;
}