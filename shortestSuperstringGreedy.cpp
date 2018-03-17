#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<string> arr;
string calculateOverlapping(string a, string b){
	int max = 0;
	int alen = a.length(), blen = b.length();
	int minLen = alen < blen ? alen : blen;
	string str = a + b;
	for(int i = 1; i <= minLen; i++){
		if(a.substr(alen - i, i) == b.substr(0, i)){
			if(i > max){
				max = i;
				str = a + b.substr(i, blen - i);
			}
		}
	}
	for(int i = 1; i <= minLen; i++){
		if(b.substr(blen - i, i) == a.substr(0, i)){
			if(i > max){
				max = i;
				str = b + a.substr(i, alen - i);
			}
		}
	}
	return str;
}
string findShortestSuperstring(){
	while(arr.size() != 1){
		int max = -1;
		int idx1, idx2;
		string resStr;
		for(int i = 0; i < arr.size(); i++){
			for(int j = i + 1; j < arr.size(); j++){
				string str = calculateOverlapping(arr[i], arr[j]);
				int k = arr[i].length() + arr[j].length() - str.length();
				if(k > max){
					max = k; resStr = str;
					idx1 = i; idx2 = j;
				}
			}
		}
		arr[idx1] = resStr;
		arr.erase(arr.begin() + idx2);
	}
	return arr[0];
}
int main(){
	cin>>n;
	arr.resize(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<findShortestSuperstring();
	return 0;
}