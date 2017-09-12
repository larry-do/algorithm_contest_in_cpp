//là cách biết thì dùng, cho thì dùng. không cho thì sử dụng struct/class
#include<iostream>
#include<string>
#include<map>
#include<fstream>
int main(){
    std::fstream file;
    file.open("in.txt",std::ios::in);
    std::map<std::string,std::size_t> count_word;//khai báo map
    while(!file.eof()){
        std::string word;
        file>>word;
        count_word[word]++;
    }
    for(std::map<std::string,std::size_t>::iterator i = count_word.begin();i!=count_word.end();i++){
        std::cout<<i->first<<' '<<i->second<<std::endl;
    }
    return 1;
}
