#include <iostream>
#include <bitset>
using namespace std;
string showBits(long long i, int n){
	bitset<64> s(i);
	return s.to_string().substr(64 - n, n);
}
string Divide(int Q, int M, int n){
	int A = 0, step = n;
	cout<<showBits(A, n)<<' '<<showBits(Q, n)<<' '<<showBits(M, n)<<endl;
	while(step != 0){
		bool theFirstBitOf_Q = (Q & (1<<(n-1)));
		A = A << 1;
		Q = Q << 1;
		if(theFirstBitOf_Q) A = (A | (1<<0));
		cout<<showBits(A, n)<<' '<<showBits(Q, n)<<endl;
		A -= M;
		cout<<showBits(A, n)<<endl;
		if(A < 0) {Q = (Q & ~(1<<0)); A += M;}
		else Q = (Q | (1<<0));
		cout<<showBits(A, n)<<' '<<showBits(Q, n)<<endl;
		step--;
	}
	return showBits(Q, n);
}
int main(){
	Divide(4, 9, 4);
	return 0;
}