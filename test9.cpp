#include<iostream>
#include<string>
int main(){
    int Count[256] = {0};
    std::string a("dodinhnhat");
    for(int i=0;i<a.length();i++){
        Count[a[i]]++;
    }
    for(int i=0;i<256;i++){
        if(Count[i]>0){
            std::cout<<char(i);
        }
    }
    return 1;
}
