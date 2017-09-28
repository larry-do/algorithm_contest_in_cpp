#include<iostream>
#include<string>
int main(){
    std::string a("sdassakjdhajsdhaspzzz");
    int cc_1[256] = {0};
    for(int i=0;i<a.length();i++){
        cc_1[a[i]]++;
    }
    std::string b("ruiqowurhfdsnahjsjkhl");
    int cc_2[256] = {0};
    for(int i=0;i<b.length();i++){
        cc_2[b[i]]++;
    }
    for(int i=0;i<256;i++){
        if(cc_1[i]&&cc_2[i])
            std::cout<<char(i)<<' '<<cc_1[i]+cc_2[i]<<std::endl;
    }
    std::cout<<std::endl;
    for(int i=0;i<256;i++){
        if(cc_1[i] && !cc_2[i])
            std::cout<<char(i)<<' '<<cc_1[i]<<std::endl;
    }
    return 1;
}
