#include<iostream>
#include<string>
#include<fstream>
#include<vector>
int main(){
    std::fstream infile,outfile;
    infile.open("in.txt",std::ios::in);
    outfile.open("out.txt",std::ios::out);
    if(!infile.is_open()){
        std::cout<<"error";
        return 0;
    }
    std::vector<std::string> a;
    while(!infile.eof()){
        std::string word;
        infile>>word;
        std::cout<<word;
        if(word!="")
            a.push_back(word);
    }
    for(int i=0;i<a.size();i++){
        int k=0;
        for(int j=0;j<a.size();j++){
            if(a[j]==a[i]&&j<i){
                break;
            }
            if(a[j]==a[i]&&j>=i){
                k++;
            }
        }
        if(k>0){
            outfile<<a[i]<<' '<<k<<std::endl;
        }
    }
    infile.close();
    outfile.close();
    return 1;
}
