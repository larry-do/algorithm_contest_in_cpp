#include <iostream>
#include <bitset>
using namespace std;
string showBits(long long i, int n){
	bitset<64> s(i);
	return s.to_string().substr(64 - n, n);
}
long long BinToDec(string s){
	bitset<64> b(s);
	return b.to_ulong();
}
string Multi_Use_Booth(long long M, long long Q, int n){
	long long step = n, A = 0;
	bool C = false; // C là Q_-1
	cout<<showBits(A, n)<<' '<<showBits(Q, n)<<' '<<C<<endl;
	while(step != 0){
		bool theLastBitOf_Q = (Q & (1<<0)); // lấy Q_0
		if(theLastBitOf_Q == false && C == true) {
			A += M;
			cout<<showBits(A, n)<<' '<<showBits(Q, n)<<' '<<C<<endl;
		}
		else if(theLastBitOf_Q == true && C == false) {
			A -= M;
			cout<<showBits(A, n)<<' '<<showBits(Q, n)<<' '<<C<<endl;
		}
		bool theFirstBitOf_A = (A & (1<<(n-1)));
		bool theLastBitOf_A = (A & (1<<0));
		A = A >> 1;
		if(theFirstBitOf_A) A = (A | (1<<(n-1)));
		else A = (A & ~(1<<(n-1)));
		C = theLastBitOf_Q;
		Q = Q >> 1;
		if(theLastBitOf_A) Q = (Q | (1<<(n-1)));
		cout<<showBits(A, n)<<' '<<showBits(Q, n)<<' '<<C<<endl;
		step--;
	}
	return showBits(A, n) + showBits(Q, n);
}
int main(){
	string s = Multi_Use_Booth(82, 112, 8);
	cout<<s<<endl;
	int a = BinToDec(s);
	cout<<a<<endl;
	return 0;
}