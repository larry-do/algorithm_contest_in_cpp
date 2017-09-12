#include<iostream>
#include<string>
#include<bitset>
#include<cmath>
std::string toBinary(int n,int m);
int main(){
    int m = 5;
    int k=pow(2,m);
    for(int i=0;i<k;i++){
        std::string binary=toBinary(i,m);
        std::cout<<binary<<std::endl;
    }
    return 1;
}
std::string toBinary(int n,int m)
{
    std::string binary;
    while(n!=0) {
        binary=(n%2==0 ?"0":"1")+binary;
        n/=2;
    }
    std::string a(m-binary.length(),'0');
    binary=a+binary;
    return binary;
}
