#include <iostream>
using namespace std;
struct queue
{
	int low, high;
	long int node[1010];
};
int main(){
	int t; cin>>t;
	for(int e = 1; e <= t; e++){
		queue q;
		q.low = 0; q.high = 0;
		int n; cin>>n;
		for(int i = 1; i <= n; i++){
			int a; cin>>a;
			switch(a){
				case 1:{
					cout<<q.high - q.low<<endl; break;
				}
				case 2:{
					if(q.high - q.low == 0) cout<<"YES"<<endl;
					else cout<<"NO"<<endl;
					break;
				}
				case 3:{
					long int b; cin>>b;
					q.node[++q.high] = b;
					break;
				}
				case 4:{
					if(q.high - q.low > 0){
						q.low++;
					}
					break;
				}
				case 5:{
					if(q.high - q.low == 0) cout<<"-1"<<endl;
					else cout<<q.node[q.low + 1]<<endl;
					break;
				}
				case 6:{
					if(q.high - q.low == 0) cout<<"-1"<<endl;
					else cout<<q.node[q.high]<<endl;
					break;	
				}
			}
		}
	}
	return 0;
}