#include<iostream>
unsigned long long int GCD_Of(unsigned long long int a,unsigned long long int b);
int main(){
    std::cout<<GCD_Of(25,35);
    return 0;
}
unsigned long long int GCD_Of(unsigned long long int a,unsigned long long int b){
    if(a==b) return a;
    if(a>b) return GCD_Of(a-b,b);
    return GCD_Of(a,b-a);
}
