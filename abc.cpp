#include<iostream>
//cách này bị limit time chắc
int countSS(int number,int a[]);
int main(){
    int n=1000000000;
    int a[5]={9,11,13,17,19};
    std::cout<<countSS(n,a);
    return 0;
}
int countSS(int number,int a[]){
    int k=number+1;
    bool *eratos = new bool[number+1];
    for(int i=0;i<number+1;i++) eratos[i]=true;
    for(int i=0;i<5;i++){
        for(int j=0;j<number+1;j+=a[i]){
            if(eratos[j]){
                eratos[j]=false;
                k--;
            }
        }
    }
    return k;
}
/*
    Cho 5 số tự nhiên a, b, c, d, e là các số nguyên tố cùng nhau từng đôi một. Hãy cho biết có bao
nhiêu số nhỏ hơn hoặc bằng N không chia hết cho bất kỳ số nào trong các số a, b, c, d, e
(N<263)
*/
