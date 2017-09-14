#include<iostream>
#include<fstream>
int main(){
    ///
    std::fstream file_in("in.txt",std::ios::in);
    if(!file_in.is_open()){
        std::cout<<"error";
        return 1;
    }
    int n,w;
    file_in>>n>>w;
    int ai[n];
    int ci[n];
    int binary[n]={0};
    int binary_clone[n]={0};
    for(int i=0;i<n;i++){
        file_in>>ai[i]>>ci[i];
    }
    ///
    int i=n-1;
    int maxCI=0;
    while(i>=0){
        if(binary[i]==0){
            binary[i]=1;
            for(int j=n-1;j>i;j--){
                binary[j]=0;
            }
            i=n-1;
            ///
            int sumAI=0,sumCI=0;
            for(int k=0;k<n;k++){
                sumAI+=(ai[k]*binary[k]);
                sumCI+=(ci[k]*binary[k]);
            }
            if(sumAI<=w && sumCI>=maxCI){
                for(int p=0;p<n;p++) {
                    binary_clone[p]=binary[p];
                }
                maxCI=sumCI;
            }
            ///
        }
        else
            i--;

    }
    ///
    std::fstream file_out("out.txt",std::ios::out);
    file_out<<maxCI<<std::endl;
    for(int i=0;i<n;i++){
        file_out<<binary_clone[i]<<std::endl;
    }
    file_in.close();
    file_out.close();
    return 1;
}
