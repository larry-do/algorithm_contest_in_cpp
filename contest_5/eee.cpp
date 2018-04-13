#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 getMax(i64 arr[], i64 n)
{
    i64 mx = arr[0];
    for (i64 i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(i64 arr[], i64 n, i64 exp)
{
    i64 output[n];
    i64 i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(i64 arr[], i64 n)
{
    i64 m = getMax(arr, n);
    for (i64 exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main(){
    i64 n; cin>>n;
    i64 *a = new i64[n];
    for(i64 i = 0; i < n; i++) cin>>a[i];
    radixsort(a, n);
    for(i64 i = 0; i < n; i++) cout<<a[i]<<" ";
    return 0;
}