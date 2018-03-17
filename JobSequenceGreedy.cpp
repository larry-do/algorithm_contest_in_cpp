/*
Nói chung đề bài như thế này
Có n tác vụ
Mỗi tác vụ có id, deadline, profit và thời gian hoàn thành 1 tác vụ là 1 đơn vị thời gian
Chọn các tác vụ để được max profit
Chú ý deadline của các tác vụ là nhỏ hơn n
Ví dụ
5
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
ta chọn a, c, e. Đầu tiên làm a, ta mất 1 đơn vị thời gian. Làm thêm c ta mất 2 đơn vị thời gian
mà vẫn kịp deadline của c. Lúc này đã quá deadline của b và d (là 1), ta chọn thêm e
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
	char id;
	int deadline;
	int profit;
};
bool compare(Job a, Job b){
	return a.profit > b.profit;
}
int showJobSequence(Job arr[], int n){
	sort(arr, arr+n, compare);
	bool check[n];
	int res[n];
	for(int i = 0; i < n; i++){
		check[i] = false;
	}
	for(int i = 0; i < n; i++){
		for(int j = min(n, arr[i].deadline) - 1; j >= 0; j--){ // chỗ min kia thừa
			if(!check[j]){
				res[j] = i;
				check[j] = true;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(check[i]){
			cout<<arr[res[i]].id<<" ";
		}
	}
}
int main(){
	int n; cin>>n;
	Job arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
	}
	showJobSequence(arr, n);
	return 0;
}