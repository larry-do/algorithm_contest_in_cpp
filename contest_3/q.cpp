#include <iostream>
#include <string>
using namespace std;
struct queue
{
	int low, high;
	int *node;	
};
int main(){
	queue q;
	q.low = 0; q.high = 0;
	long int t; cin>>t;
	q.node = new int[t+10];
	for(int e = 1; e <= t; e++){
		string s; cin>>s;
		if(s == "PUSH"){
			int a; cin>>a;
			q.node[++q.high] = a;
		}
		else if(s == "POP" && q.high - q.low > 0) q.low++;
		else if(s == "PRINTFRONT"){
			if(q.high - q.low <= 0) cout<<"NONE"<<endl;
			else cout<<q.node[q.low + 1]<<endl;
		}
	}
	return 0;
}