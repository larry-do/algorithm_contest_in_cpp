#include <iostream>
int findNonDuplicate(int a[], int size){// su dung khi lap k = 2
	int result = 0;
	for (int i = 0; i < size; ++i){
		result^=a[i];
	}
	return result;
}
int findSingleNumber(int a[], int size, int k){// k = bat ki
	int result = 0;
	for (int i = 0; i < 32; ++i){
		int curr = 0;
		for (int j = 0; j < size; ++j){
			curr += (a[j] >> i) & 1;
		}
		result += (curr % k) << i;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int a[]={6,6,6,6,2,2,2,2,3,3,3,3,999};
	std::cout<<findSingleNumber(a,13,4)<<std::endl;
	return 0;
}