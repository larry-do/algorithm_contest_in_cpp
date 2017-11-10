#include<iostream>
class SO_PHUC {
private:
    float a,b;
public:
    void init();
    void show();
    SO_PHUC sum(SO_PHUC x);
    SO_PHUC minuss(SO_PHUC x);
    SO_PHUC tich(SO_PHUC x);
    SO_PHUC thuong(SO_PHUC x);
    SO_PHUC luyThua(int x);
};
///////////////
void SO_PHUC::init(){
    std::cin>>a>>b;
}
void SO_PHUC::show(){
    std::cout<<a<<"+"<<b<<"*i"<<std::endl;
}
SO_PHUC SO_PHUC::sum(SO_PHUC x){
    SO_PHUC c;
    c.a = this->a+x.a;
    c.b = this->b+x.b;
    return c;
}
SO_PHUC SO_PHUC::minuss(SO_PHUC x){
    SO_PHUC c;
    c.a = this->a - x.a;
    c.b = this->b - x.b;
    return c;
}
SO_PHUC SO_PHUC::tich(SO_PHUC x){
    SO_PHUC c;
    c.a = this->a*x.a - this->b*x.b;
    c.b = this->a*x.b + this->b*x.a;
    return c;
}
SO_PHUC SO_PHUC::thuong(SO_PHUC x){
    SO_PHUC c;
    c.a = (this->a*x.a+this->b*x.b)/(x.a*x.a+x.b*x.b);
    c.b = (this->b*x.a - this->a*x.b)/(x.a*x.a+x.b*x.b);
    return c;
}
SO_PHUC SO_PHUC::luyThua(int x){
    SO_PHUC c,d;
    c.a = this->a;
    c.b = this->b;
    d = c;
    for(int i=0;i<x-1;i++){
        c = c.tich(d);
    }
    return c;
}
int main(){
    SO_PHUC a,b,c;
    a.init();
    //b.init();
    c = a.luyThua(3);
    c.show();
    return 1;
}
