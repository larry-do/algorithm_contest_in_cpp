//using bitset//if no using bitset, using binary string to int
//using the generation algorithm is crazy
#include<iostream>
#include<bitset>
#include<string>
#include<cmath>
long long int binaryStringToInt(std::string a){
    long long int n = 0;
    for(int i=a.length()-1;i>=0;i--){
        n+=(a[i]-'0')*pow(2,a.length()-1-i); // should assign a.length() to a variable;
    }
    return n;
}
bool check(std::string a, std::string b){
    std::bitset<1000> a_bit(a);
    std::bitset<1000> b_bit(b);
    std::cout<<a_bit.to_ulong()<<' '<<binaryStringToInt(a);
    if((b_bit.to_ulong() - a_bit.to_ulong()) == 1) return true;
    return false;
}
int main(){
    std::string a="10101";
    std::string b="10100";
    check(a,b);
    return 1;
}
