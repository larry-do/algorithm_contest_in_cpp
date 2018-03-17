#include <iostream>
#include <algorithm>
using namespace std;
long int minCoins(long int coins[], int n, long int money){
	long int dem = 0;
	int i = n - 1;
	while(money > 0 && i >= 0){
		dem+=(money/coins[i]);
		money = money % coins[i];
		i--;
	}
	return dem;
}
int main(){
	int n; cin>>n;
	long int s; cin>>s;
	long int coins[31];
	for(int i = 0; i < n; i++){
		cin>>coins[i];
	}
	sort(coins, coins+n);
	cout<<minCoins(coins, n, s);
	return 0;
}