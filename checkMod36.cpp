#include<iostream>
#include<string>
long sumDigit(std::string n);
bool checkMod36(std::string s);
int main(){
    std::string s="123456789926";
    std::cout<<checkMod36(s);
    return 0;
}
bool checkMod36(std::string s){
    if(s=="0") return true;
    if(s.length()<2) return false;
    int n=(s[s.length()-2]-'0')*10+s[s.length()-1]-'0';
    return (n%4==0)&&(sumDigit(s)%9==0);
}
long sumDigit(std::string n){
    long sum=0;
    for(int i=0;i<n.length();i++){
        sum+=(n[i]-'0');
    }
    return sum;
}
//Chỉ cần kiểm tra chia hết cho 9 và 4 là chia hết cho 6
//Số chia hết cho 4 là số có 2 chữ số cuối chia hết 4
//Số chia hết cho 9 là số có tổng các chữ số chia hết 9
