/*
* Để bài 
* Cho n items cùng với trọng lượng của nó
* Cần bao nhiều túi để chứa tất cả các items
* Túi có giới hạn trọng lượng tối đa c
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a > b;
}
int bestFit(int weight[], int n, int c){
    sort(weight, weight+n, compare); // sắp xếp tham lam
    int res = 0; // kết quả
    int bin_remain[n]; // giả sử cần tối đa n cái túi
    for (int i = 0; i < n; i++){ // duyệt tất cả items
        int min = c+1, bi = 0;
        for (int j = 0; j < res; j++){ // xét tất cả các túi hiện có và chọn cái nào phù hợp nhất với item
            if (bin_remain[j] >= weight[i] && bin_remain[j] - weight[i] < min){
                bi = j;
                min = bin_remain[j] - weight[i];
            }
        }
        if (min == c+1){ // nếu mà không chọn được túi nào thì thiết lập túi mới
            bin_remain[res] = c - weight[i];
            res++;
        }
        else bin_remain[bi] -= weight[i]; // chọn được thì giảm trọng lượng còn lại của túi
    }
    return res;
}
int main(){
    int n, c; cin>>n>>c;
    int weight[n];
    for(int i = 0; i < n; i++){
        cin>>weight[i];
    }
    cout<<bestFit(weight, n, c);
    return 0;
}