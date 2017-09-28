#include<iostream>
#include<string>
bool checkPangram(std::string a){
    int Count[256]={0};
    for(int i=0;i<a.length();i++){
        Count[a[i]]++;
    }
    bool check_1 = true;
    for(int i = 'a';i<= int('z');i++){
        if(Count[i]<1)
            check_1 = false;
    }
    bool check_2 = true;
    for(int i = 'A';i<= int('Z');i++){
        if(Count[i]<1)
            check_2 = false;
    }
    return check_1 || check_2;
}
int main(){
    std::string a("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::cout<<checkPangram(a);
    return 1;
}

