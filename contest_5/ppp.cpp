#include<bits/stdc++.h>
#define MAX 510
int n, m, a[MAX][MAX], f[MAX][MAX];
void init(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
            f[i][j] = a[i][j];
        }
    }
}
void find(){
    int res = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            if(a[i][j] && a[i][j] == a[i-1][j-1] 
                && a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1]){
                f[i][j] = std::min(f[i-1][j-1], std::min(f[i-1][j], f[i][j-1])) + 1;
            }
            res = std::max(f[i][j], res);
        }
    }
    printf("%d\n", res);
}
int main(){
    int test; scanf("%d", &test);
    while(test--){
        init();
        find();
    }
    return 0;
}