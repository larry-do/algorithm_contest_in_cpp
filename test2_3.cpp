#include<iostream>
bool check_(int a[],int n,int x);
int main(){
    int a[5]={1,2,3,4,5};
    int x=5;
    std::cout<<check_(a,5,1)<<std::endl;
    return 1;
}
bool check_(int a[],int n, int x){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==x) return true;
        }
    }
    return false;
}
//chưa có cách nào ngắn hơn. Cách này độ phức tạp On2