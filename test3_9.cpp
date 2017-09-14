///Mình có ý tưởng này
//khi nhập mảng rồi. tạo một mảng khác có cùng độ dài với mảng cũ
//dùng thuật toán sinh sinh ra mảng nhị phân 1-0 có trên mảng mới
//lấy giá trị 1-0 đó nhân với giá trị có chỉ số tương ứng của mảng cũ
//tổng = k thì in ra
#include<iostream>
int main(){
    int n=5,k=50;
    int arr[5]={5,10,15,20,25};
    int binary[5]={0,0,0,0,0};
    int i=n-1;
    while(i>=0){
        if(binary[i]==0){ ///nếu bằng 0
            binary[i]=1;///thì cho bằng 1
            for(int k=n-1;k>i;k--)
                binary[k]=0;///và tất cả các phần tử đằng sau lại chuyển về 0
            i=n-1;///gán lại cho i là chỉ số phần tử cuối
            ///KIỂM TRA XEM CÁC CHỈ SỐ CÓ GIẢ TRỊ BẰNG 1 THÌ TỔNG CÁC HỆ SỐ TƯƠNG ỨNG CÓ BẰNG K KHÔNG
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=(binary[j]*arr[j]);
            }
            if(sum==k){///nếu đúng thì in ra những giá trị nào ( ở mảng chính ) có giá trị = 1 ở mảng phụ (cùng chỉ số)
                for(int j = 0;j<n;j++){
                    if(binary[j]==1)
                        std::cout<<arr[j]<<' ';
                }
                std::cout<<std::endl;
            }
        }
        else
            i--;
    }
    return 1;
}
