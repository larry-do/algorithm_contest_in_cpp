#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;
struct stack{
	long int top;
	int node[MAX];
};
stack stk;
void init(){
	stk.top = -1;
}
void pop(){
	if(stk.top >= 0) stk.top--;
}
void push(int a){
	stk.top++;
	stk.node[stk.top] = a;
}
void show(){
	if(stk.top < 0){
		cout<<"NONE"<<endl;
	}
	else cout<<stk.node[stk.top]<<endl;
}
int main(){
	init();
	long int q; cin>>q;
	for(int e = 1; e <= q; e++){
		string s; cin>>s;
		if(s == "PUSH"){
			int a; cin>>a;
			push(a);
		}
		if(s == "POP") pop();
		if(s == "PRINT") show();
	}
	return 0;
}