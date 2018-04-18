#include <iostream>
#include <bitset>
using namespace std;
string showBits(long long i, int n){
	bitset<64> s(i);
	return s.to_string().substr(64 - n, n);
}
string Multiple_Bits(long long M, long long Q, int n){
	long long A = 0;
	bool C = false;
	int step = n;
	cout<<C<<" "<<showBits(A, n)<<" "<<showBits(Q, n)<<endl;
	while(step != 0){
		if((Q & (1<<0))){
			A += M;
			C = (A & (1<<n));
			cout<<C<<" "<<showBits(A, n)<<" "<<showBits(Q, n)<<endl;
		}
		long long theLastBitOfA = (A & (1<<0));
		C = false;
		A = A >> 1;
		Q = Q >> 1;
		if(theLastBitOfA) Q = (Q | (1<<(n-1)));
		cout<<C<<" "<<showBits(A, n)<<" "<<showBits(Q, n)<<endl;
		step--;
	}
	return showBits(A, n) + showBits(Q, n);
}
long long BinToDec(string s){
	bitset<64> b(s);
	return b.to_ulong();
}
int main(){
	string s = Multiple_Bits(116, 197, 8);
	cout<<s<<endl;
	long long a = BinToDec(s);
	cout<<a<<endl;
	return 0;
}