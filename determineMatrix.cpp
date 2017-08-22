#include<iostream>
#include<algorithm>
class matrixClass{
private:
  float **matrix; //mảng động
  int row,col; //hàng cột
public:
  void initMatrix();// nhập hàng cột ( ma trận vuông) và khởi tạo mảng động
  void getMatrixMember();//nhập các phần tử
  void showMatrix();//in ma trận
  float determineMatrix();//tìm định thức
  void cleanMatrix();//dọn bộ nhớ mảng động
};
void matrixClass::initMatrix(){
    std::cin>>row;
    col=row;
    matrix=new float* [row];
    for(int i=0;i<row;i++){
        matrix[i]=new float [col];
    }
}
void matrixClass::getMatrixMember(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            std::cin>>matrix[i][j];
        }
    }
}
void matrixClass::showMatrix(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            std::cout<<(float)matrix[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}
void matrixClass::cleanMatrix(){
    for(int i=0;i<row;i++){
        delete[] matrix[i];
    }
}
float matrixClass::determineMatrix(){
    if(row==1) return matrix[0][0]; //ma trận bậc 1
    int sign=1;//dấu của định thức ( mặc định dương nên để 1)
    float det=1; //định thức
    for(int i=0;i<row-1;i++){ //chạy từ 0 đến row-1
        if(matrix[i][i]==0){// nếu mà phần tử trên đường chéo chính bằng ko, ta phải đổi hàng khác
            int k=i+1;
            while(k<row&&matrix[k][i]==0) k++;
            if(k==row) return 0; // chạy đến hết rồi mà vẫn chưa tìm thấy, thì ma trận này có định thức bằng 0
            for(int j=i;j<row;j++){ //nếu tìm được thì đổi hàng cho nhau
                std::swap(matrix[i][j],matrix[k][j]);//hàm đổi chỗ cần thư viện algorithm
            }
            sign=-sign;//lúc này định thức đổi dấu
        }
        for(int j=i+1;j<row;j++){//rồi dùng gauss thôi
            float temp=-matrix[j][i]/matrix[i][i];//tỉ số số dưới chia cho số trên
            for(int k=i+1;k<row;k++) matrix[j][k]+=temp*matrix[i][k]; //gauss
        }
        det*=matrix[i][i];//tiện nhân luôn tính định thức
    }
    det*=matrix[row-1][row-1];// nhân nốt cái phần tử trên đường chéo chính cuối cùng
    return det; //done
}
int main(){
  matrixClass *a=new matrixClass;
  a->initMatrix();
  a->getMatrixMember();
  std::cout<<a->determineMatrix()<<std::endl;
  a->showMatrix();
  a->cleanMatrix();
  delete a;
  return 0;
}
