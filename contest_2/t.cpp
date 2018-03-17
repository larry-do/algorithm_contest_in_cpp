#include <cstdio>
long long n, left, right;
long long res;
long long matrix[60], k;
long long power(long long n, long long k){
	if(k == 0) return 1;
	long long tmp = power(n, k/2);
	if(k % 2 == 1) return tmp*tmp*n;
	else return tmp*tmp;
}
long long Cal(long long u){ // hàm này chỉ tìm chỉ số chẵn!!!
	while(1){
		long long p = 1, c = 0;
		while(2 * p <= u){
			p*=2; c++;
		}
		if(u == p){  // nếu trùng thì retủrn luôn
			return matrix[k - 1 - c];
		}
		else u-=p; // nếu không thì lấy tiếp với mốc khác
	}
}
void countBit(){
	// đầu tiên là các vị trí lẻ chắc chắn bằng 1
	int mL = left % 2, mR = right % 2;
	if((mL + mR) != 0) res = (right - left)/2 + 1;
	else res = (right - left)/2;
	// lấy vị trí chẵn để xét
	if(mL == 1) left++;
	if(mR == 1) right--;
	k = 0; // lấy số dư mỗi lần n / 2;
	while(n > 0){
		matrix[k++] = n%2; n/=2;
	}
	// xét các vị trí chẵn
	for(long long i = left; i <= right; i+=2){
		res+=Cal(i);
	}
	printf("%lld\n", res);
}
int main(){
	int t; scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%lld%lld%lld", &n, &left, &right);
		countBit();
	}
	return 0;
}