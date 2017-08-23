//should use std::vector in C++
#include<iostream>
int horner(int a[],int n,int x);
int hornerRecursive(int a[],int n,int x,int pos);
int main(){
    int b[]={4,5,6},n=3,x=2; //khai báo của người dùng, danh sách hệ số, số hệ số, và hệ số nhân x
    std::cout<<horner(b,n,x)<<std::endl;
    std::cout<<hornerRecursive(b,n,x,n-1)<<std::endl;
    return 0;
}
int horner(int a[],int n,int x){
    if(n<=0) return 0;
    if(n==1) return a[0]*x;
    int p_x=0;
    for(int i=0;i<n;i++){
        p_x=p_x*x+a[i];
    }
    return p_x;
}
int hornerRecursive(int a[],int n,int x,int pos){
    if(n<=0) return 0;
    if(pos==0) return a[0];
    return a[pos]+x*hornerRecursive(a,n,x,--pos);
}
