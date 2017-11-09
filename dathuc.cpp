#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
struct SO_HANG{
    float heSo;
    int soMu;
};
class DA_THUC{
private:
    SO_HANG *a;
    int bac;
public:
    void init();
    void show();
    float valueCalculate(float x);
    DA_THUC daoHam();
    DA_THUC sumHam(DA_THUC b);
    DA_THUC minusHam(DA_THUC b);
    DA_THUC nhanHam(DA_THUC b);
    DA_THUC thuongHam(DA_THUC b);
};
///
void DA_THUC::init(){
    std::cout<<"Nhap so bac da thuc: ";
    std::cin>>bac;
    a = new SO_HANG[bac + 1];
    for(int i = bac;i>=0;i--){
        std::cout<<"Nhap he so bac"<<i<<":";
        a[i].soMu = i;
        std::cin>>a[i].heSo;
    }
}
///
std::vector<float> arrayToVector(float *a, int n){
	//trong truong hop nay n la so phan tu. ko phai he so
	std::vector<float> b;
	for(int i = 0; i < n; i++){
		b.push_back(a[i]);
	}
	return b;
}
void vectorToArray(std::vector<float> a, float *b, int &size){
	size = a.size();
	for(int i = 0; i < size; i++){
		b[i] = a[i];
	}
}
///
void DA_THUC::show(){
    for(int i=bac;i>0;i--){
        std::cout<<a[i].heSo<<"*x^"<<a[i].soMu<<'+';
    }
    std::cout<<a[0].heSo<<std::endl;
}
///
float DA_THUC::valueCalculate(float x){
	float value = 0;
	for(int i = 0; i <= bac; i++){
		value+=(a[i].heSo*pow(x,i));
	}
	return value;
}
///
DA_THUC DA_THUC::daoHam(){
    DA_THUC b;
    b.bac = bac - 1;
    b.a = new SO_HANG[b.bac+1];
    for(int i=1;i<=bac;i++){
        b.a[i-1].heSo = a[i].heSo*i;
        b.a[i-1].soMu = i - 1;
    }
	return b;
}
DA_THUC DA_THUC::sumHam(DA_THUC b){
    DA_THUC c;
    if(this->bac > b.bac){
        c.bac = this->bac;
        c.a = new SO_HANG[c.bac+1];
        for(int i=0;i<=b.bac;i++){
            c.a[i].heSo = (this->a[i].heSo+b.a[i].heSo);
            c.a[i].soMu = this->a[i].soMu;
        }
        for(int i=b.bac+1;i<=this->bac;i++){
            c.a[i].heSo = this->a[i].heSo;
            c.a[i].soMu = this->a[i].soMu;
        }
    }
    else{
        c.bac = b.bac;
        c.a = new SO_HANG[c.bac+1];
        for(int i=0;i<=this->bac;i++){
            c.a[i].heSo = (this->a[i].heSo+b.a[i].heSo);
            c.a[i].soMu = b.a[i].soMu;
        }
        for(int i=this->bac+1;i<=b.bac;i++){
            c.a[i].heSo = b.a[i].heSo;
            c.a[i].soMu = b.a[i].soMu;
        }
    }
    return c;
}
///
DA_THUC DA_THUC::minusHam(DA_THUC b){
    DA_THUC c;
    if(this->bac > b.bac){
        c.bac = this->bac;
        c.a = new SO_HANG[c.bac+1];
        for(int i=0;i<=b.bac;i++){
            c.a[i].heSo = (this->a[i].heSo-b.a[i].heSo);
            c.a[i].soMu = this->a[i].soMu;
        }
        for(int i=b.bac+1;i<=this->bac;i++){
            c.a[i].heSo = this->a[i].heSo;
            c.a[i].soMu = this->a[i].soMu;
        }
    }
    else{
        c.bac = b.bac;
        c.a = new SO_HANG[c.bac+1];
        for(int i=0;i<=this->bac;i++){
            c.a[i].heSo = (this->a[i].heSo-b.a[i].heSo);
            c.a[i].soMu = b.a[i].soMu;
        }
        for(int i=this->bac+1;i<=b.bac;i++){
            c.a[i].heSo = (0-b.a[i].heSo);
            c.a[i].soMu = b.a[i].soMu;
        }
    }
    return c;
}
DA_THUC DA_THUC::nhanHam(DA_THUC b){
    DA_THUC c;
    c.bac = this->bac+b.bac;
    c.a = new SO_HANG[c.bac+1];
    for(int i = 0; i<=c.bac;i++){
        c.a[i].heSo = 0;
        c.a[i].soMu = i;
    }
    for(int i=0;i<=this->bac;i++){
        for(int j=0;j<=b.bac;j++){
            c.a[i+j].heSo += this->a[i].heSo*b.a[j].heSo;
        }
    }
    return c;
}
DA_THUC DA_THUC::thuongHam(DA_THUC b){
    DA_THUC c;
    float result[100],du[100];
    for(int i=0;i<=this->bac;i++){
        du[i]=this->a[i].heSo;
    }
    if(this->bac<b.bac){
        c.bac = 0;
        c.a = new SO_HANG[1];
        c.a[0].heSo = 0;
        c.a[0].soMu = 0;
    }
    else{
        int x=this->bac;
        int z=this->bac-b.bac;
        if(this->bac==b.bac){
            result[z]=this->a[this->bac].heSo/b.a[this->bac].heSo;
            z++;
        }
        else{
            while(z>=0){
                result[z]=du[x]/b.a[b.bac].heSo;
                int y=b.bac;
                for(int i=x;i>=x-b.bac;i--){
                    du[i]=du[i]-result[z]*b.a[y].heSo;
                    y--;
                }
                x--;
                z--;
            }
        }
        c.bac = this->bac - b.bac;
        c.a = new SO_HANG[c.bac+1];
        for(int i=0;i<=this->bac - b.bac;i++){
            c.a[i].heSo = result[i];
            c.a[i].soMu = i;
        }
    }
    // so du thi size  = x
    return c;
}
int main(int argc, char const *argv[])
{
    DA_THUC a;
    a.init();
    DA_THUC b;
    b.init();
    DA_THUC c = a.thuongHam(b);
    c.show();
	return 0;
}
