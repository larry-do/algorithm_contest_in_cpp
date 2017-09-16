//thuật toán sinh tổ hợp dựa vào thuật toán sinh
#include<iostream>
int main(){
    int n=7,k=4;
    int binary[n]={0};
    int i = n-1;
    int sum=0,_count=0;
    while(i>=0){
        if(binary[i]==0){
            binary[i]=1;
            sum++;
            for(int j=n-1;j>i;j--){
                binary[j]=0;
                sum--;
            }
            i=n-1;
            if(sum==k){
                _count++;
            }
        }
        else
            i--;
    }
    std::cout<<_count;
    return 1;
}
