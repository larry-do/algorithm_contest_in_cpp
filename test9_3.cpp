#include<iostream>
#include<string>
int main(){
    std::string a("sdassakjdhajsdhas");
    int cc[256] = {0};
    for(int i=0;i<a.length();i++){
        cc[a[i]]++;
    }
    int mx = 0;
    int idx = 0;
    for(int i=255;i>=0;i--){
        if(cc[i]>0 && cc[i] >= mx){
            mx = cc[i];
            idx = i;
        }
    }
    std::cout<<char(idx)<<' '<<mx;
    return 1;
}
