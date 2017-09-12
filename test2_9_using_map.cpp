//các thông thường cực lâu khi phần tử lớn. ở đây mình dùng map//nếu không muốn sử dụng map, hãy sử dụng class hoặc struct
#include<iostream>
#include<map>
#include<vector>
int main(){
    std::vector<long long int> a={214000000,0};//số phần tử không quá range của int (hơn 2 tỉ một chút)
    std::map<int,int> count_int;
    for(int i=0;i<a.size();i++){
            count_int[a[i]]++;
    }
    for(std::map<int,int>::iterator i=count_int.begin();i!=count_int.end();i++){
        if(i->first!=0){
            std::cout<<i->first<<' '<<i->second<<std::endl;
        }
    }
    return 1;
}
