#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n;
vector<int> x;
long long int num = 1000000000000000001;
long long int MAX = 1000000000000000001;
int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int isPrime(int n){
    if(n==2||n==3) return 1;
    if(n%2==0||n%3==0||n<2) return 0;
    int i=-1, sqrtOf_n=(int)sqrt(n); // giảm bớt thời gian tính toán sqrt
    do{
        i+=6;
        if((n%i==0)||(n%(i+2)==0)) break;
    }while(i<=sqrtOf_n);
    return (i>sqrtOf_n);
}
long long int pow_int(int a, int b){
    long long int tmp = 1;
    for(int i = 1; i <= b; i++){
        tmp*=a;
        if(tmp > MAX) return -1;
    }
    return tmp;
}
bool compare(int a, int b){
    return a > b;
}
void update(){
    long long int tmp = 1;
    vector<int> clone = x;
    sort(clone.begin(), clone.end(), compare);
    for(int i = 0; i < clone.size() - 1; i++){
        tmp*=(pow_int(primes[i], clone[i]-1));
        if(tmp > MAX && tmp < 0) return;
    }
    if(tmp < num && tmp > 0) num = tmp;
}
void Try(int n){
    int i = 2;
    x.push_back(n);
    update();
    x.pop_back();
    while(i <= n/i){
        if(n % i == 0){
            x.push_back(i);
            int k = n/i;
            if(isPrime(k)){
                x.push_back(k);
                update();
                x.pop_back();
            }
            else{
                Try(k);
            }
            x.pop_back();
        }
        i++;
    }
}
int main(){
    int t; cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n;
        x.assign(1, 1);
        num = 1000000000000000001;
        Try(n);
        cout<<num<<endl;
    }
    return 0;
}
