#include <iostream>
#include <string>
using namespace std;
struct queue
{
	int head, tail;
	int *node;
};
int main(){
	queue q;
	long int t; cin>>t;
	q.head = t; q.tail = t;
	q.node = new int[2 * t + 10];
	for(long int e = 1; e <= t; e++){
		string s; cin>>s;
		if(s == "PUSHBACK"){
			int a; cin>>a;
			q.node[q.tail--] = a;
		}
		else if(s == "PUSHFRONT"){
			int a; cin>>a;
			q.node[++q.head] = a;
		}
		else if(s == "POPBACK" && q.head - q.tail > 0){
			q.tail++;
		}
		else if(s == "POPFRONT" && q.head - q.tail > 0){
			q.head--;
		}
		else if(s == "PRINTFRONT"){
			if(q.head - q.tail > 0) cout<<q.node[q.head]<<endl;
			else cout<<"NONE"<<endl;
		}
		else if(s == "PRINTBACK"){
			if(q.head - q.tail > 0) cout<<q.node[q.tail + 1]<<endl;
			else cout<<"NONE"<<endl;
		}
	}
	return 0;
}