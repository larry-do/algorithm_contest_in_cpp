#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;
struct stack{
	long int top;
	long int node[MAX];
};
stack stk;
void init(){
	stk.top = -1;
}
void pop(){
	if(stk.top >= 0) stk.top--;
}
void push(long int a){
	stk.top++;
	stk.node[stk.top] = a;
}
void show(){
	if(stk.top < 0){
		cout<<"empty"<<endl; return;
	}
	for(long int i = 0; i <= stk.top; i++){
		cout<<stk.node[i]<<' ';
	}
	cout<<endl;
}
int main(){
	init();
	string s; cin>>s;
	while(!s.empty()){
		if(s == "push"){
			long int a; cin>>a;
			push(a);
		}
		if(s == "pop") pop();
		if(s == "show") show();
		string a; cin>>a; s = a;
	}
	return 0;
}