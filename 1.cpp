#include<iostream>
#include<cmath>
#include<fstream>
bool isPrime(long long int n);
long long int reverseDigit(long long int n);
long long int sumDigit(long long int n);
bool checkPrimeDigit(long long int n);
int main(){
	std::fstream file_in,file_out;
	file_in.open("data.in",std::ios::in);
	file_out.open("data.out",std::ios::out);
	long long int n;
	file_in>>n;
	for(int i=0;i<n;i++){
		long long int a;
		file_in>>a;
		if(isPrime(a)&&isPrime(reverseDigit(a))&&isPrime(sumDigit(a))&&checkPrimeDigit(a)){
			file_out<<"YES"<<std::endl;
		}
		else file_out<<"NO"<<std::endl;
	}
	file_in.close();
	file_out.close();
	return 0;
}
bool isPrime(long long int n){
	if(n==2||n==3) return true;
	if(n<2||n%2==0||n%3==0) return false;
	long long int i=-1,sqrt_n=int(sqrt(n));
	do{
		i+=6;
		if(n%i==0||n%(i+2)==0) break;
	}while(i<=sqrt_n);
	return i>sqrt_n;
}
long long int reverseDigit(long long int n){
	long long int a=0;
	while(n>0){
		a=a*10+n%10;
		n/=10;
	}
	return a;
}
long long int sumDigit(long long int n){
	long long int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
bool checkPrimeDigit(long long int n){
	while(n>0){
		if(!isPrime(n%10)) return false;
		n/=10;
	}
	return true;
}
