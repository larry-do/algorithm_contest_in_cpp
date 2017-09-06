#include<iostream>
#include<algorithm>
bool checkPalindrome(std::string a);
int main(){
    std::string n="112211";
    std::cout<<checkPalindrome(n);
    return 0;
}
bool checkPalindrome(std::string a) {
    return a == std::string(a.rbegin(),a.rend());
}
