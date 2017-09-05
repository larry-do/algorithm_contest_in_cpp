void eratosthenes(long n){
    bool *prime = new bool[n+1];
    for(int i=0;i<=n;i++) prime[i]=true;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*2;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]){
            std::cout<<i<<' ';
        }
    }
    delete prime;
}
/*
Hiển thị các số nguyên tố bé hớn N với n<=10^12
*/
