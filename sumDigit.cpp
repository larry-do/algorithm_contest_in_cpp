#include<iostream>
int sumDigit(std::string n);
int main(){
    std::string n="12345012345123450123450";
    std::cout<<sumDigit(n);
    return 0;
}
int sumDigit(std::string n){
    int sum=0;
    for(int i=0;i<n.length();i++){
        sum+=(n[i]-'0');
    }
    return sum;
}
