#include <bits/stdc++.h>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
string s;
int base[210]; // danh dau ki tu nao trong chuoi se xuat hien
int len, index[25]; // index danh dau vi tri cua ( hoac )
int n, x[25]; // danh dau so cap (_)
bool checkEnd; //kiem tra xem da het cap (_) chua
void init(){
	checkEnd = false;
	n = 0;
	len = s.length();
	Loop(i, 0, len-1){
		base[i] = 0; // danh dau 0 la se duoc xuat hien
		if(s[i] == '(' || s[i] == ')'){
			index[n++] = i; // danh dau vi tri ( hoac )
		}
	}
	n /= 2;
	Loop(i, 0, n-2) x[i] = 0; // danh dau cap (_) duoc xuat hien khong
	x[n-1] = 1;
}
void next(){
	int i = n-1;
	while(x[i] == 1){
		x[i--] = 0;
	}
	if(i < 0) checkEnd = true;
	else x[i] = 1;
}
void result(){
	int k = n-1;
	Loop(i, n, 2*n-1){
		x[i] = x[k--]; // danh dau doi xung cua bo cap (_)
	}
	Loop(i, 0, 2*n-1) base[index[i]] = x[i]; // danh dau (_) co duoc xuat hien khong
	Loop(i, 0, len-1){
		if(base[i] == 0) cout<<s[i]; // xuat nhung ki tu nao co base = 0
	}
	cout<<endl;
}
int main(){
	cin>>s;
	init();
	while(!checkEnd){
		result();
		next();
	}
}
