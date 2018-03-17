//bài toán đồng tiền quy hoạch động
//Trường hợp tổng quát
#include <iostream>
#define MAX 1000000
using namespace std;
int minCoins(int coins[], int n, int money){
	int res[money+1];
	res[0] = 0;
	for(int i = 1; i <= money; i++){
		res[i] = MAX;
	}
	for(int i = 1; i <= money; i++){
		for(int j = 0; j < n; j++){
			if(coins[j] <= i){
				int sub_res = res[i - coins[j]];
				if(sub_res != MAX && sub_res+1 < res[i]) res[i] = sub_res+1;
			}
		}
	}
	return res[money];
}
int main(){
	int n = 10;
	// phải sắp xếp nhỏ dần 
	int coins[n] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	int k; cin>>k;
	for(int i = 0; i < k; i++){
		int money; cin>>money;
		cout<<minCoins(coins, n, money)<<endl;
	}
	return 0;
}