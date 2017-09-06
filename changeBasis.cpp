#include<iostream>
#include<string>
#include<algorithm>
std::string changeBasis(int n,int k);
int main(){
    std::cout<<changeBasis(15,16);
    return 0;
}
std::string changeBasis(int n,int k){
    std::string a;
    while(n>0){
        if(n%k<10)
            a.push_back('0'+n%k);
        else
            a.push_back('a'+n%k-10);
        n/=k;
    }
    std::reverse(a.begin(),a.end());
    return a;
}
