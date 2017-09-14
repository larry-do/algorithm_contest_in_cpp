#include<iostream>
#include<string>
#include<bitset>
#include<cmath>
void nextBinaryString(int n);
std::string toBinary(int n,int m);
int main(){
    int m = 3;
    //cách 1
    /*
    int k=pow(2,m);
    for(int i=0;i<k;i++){
        std::string binary=toBinary(i,m);
        std::cout<<binary<<std::endl;
    }*/
    //cách 2
    nextBinaryString(m);
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
///cách 2 dùng thuật toán sinh
void nextBinaryString(int n){
    std::string a(n,'0');
    int i=a.length()-1;
    while(i>=0){
        if(a[i]=='0'){
            a[i]='1';
            for(int j=a.length()-1;j>i;j--){
                a[j]='0';
            }
            std::cout<<a<<std::endl;
            i=a.length()-1;
        }
        else
            i--;
    }
}
