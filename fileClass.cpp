#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<string.h>
#include<map>
class FAI{
private:
    char file_name[100];
    std::fstream a;
public:
    bool init(char *name);
    void copyFile(FAI &b);
    void deleteFile();
    void renameFile(char *name);
    long lengthFile();
    void listAndCountWord();
    void hopTu(FAI b);
    void giaoTu(FAI b);
    void hieuTu(FAI b);
    void closeFile();
};
bool FAI::init(char *name){
    strcpy(file_name,name);
    a.open(file_name,std::ios::in|std::ios::out);
    if(!a.is_open()){
        std::cout<<"Error! Can't open file "<<name<<std::endl;
        return false;
    }
    else{
        std::cout<<"File "<<file_name<<" has opened."<<std::endl;
        return true;
    }
}
void FAI::closeFile(){
    this->a.close();
    std::cout<<"File "<<file_name<<" closed."<<std::endl;
}
void FAI::copyFile(FAI &b){
    std::string str;
    std::getline(a,str);
    while(!a.eof()){
        b.a<<str<<std::endl;
        std::getline(a,str);
    }
    b.a<<str;
}
void FAI::deleteFile(){
    a.close();
    char c[]="del ";
    strcat(c,file_name);
    system(c);
    std::cout<<"File "<<file_name<<" is deleted."<<std::endl;
}
void FAI::renameFile(char *name){
    //create empty file
    std::ofstream f(name);
    f.close();
    // copy from original file
    FAI b;
    b.init(name);
    this->copyFile(b);
    b.closeFile();
    //delete original file
    this->deleteFile();
    //re-init file
    this->init(name);
}
long FAI::lengthFile(){

}
void FAI::listAndCountWord(){ // should delete all symbol char
    std::map<std::string,std::size_t> count_word;
    while(!a.eof()){
        std::string word;
        a>>word;
        count_word[word]++;
    }
    for(std::map<std::string,std::size_t>::iterator i = count_word.begin();i!=count_word.end();i++){
        std::cout<<i->first<<' '<<i->second<<std::endl;
    }
}
int main(){
    FAI a;
    if(a.init("a.txt")){
        a.listAndCountWord();
    }
    return 1;
}
