#include <iostream>
#include <string>
#include <sstream>
#define Loop(i, s, f) for(int i = s; i <= f; i++)
using namespace std;
short a[1001][1001] = {0};
int main(){
	string s; int n, pos, found, vertex;
	getline(cin, s); istringstream (s) >> n;
	Loop(i, 1, n){
		getline(cin, s); s += " ";
		found = s.find_first_of(" ");
		pos = 0;
		while(found != string::npos){
			istringstream (s.substr(pos, found - pos)) >> vertex;
			a[i][vertex] = 1;
			pos = found + 1;
			found = s.find_first_of(" ", pos);
		}
	}
	Loop(i, 1, n){
		Loop(j, 1, n){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}