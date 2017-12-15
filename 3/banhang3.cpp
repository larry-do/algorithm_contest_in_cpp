#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class Nguoi{
protected:
    string hoten, diachi, phone;
};
class KhachHang:public Nguoi{
protected:
    string id, loaiKH;
public:
    friend void init();
    friend void operator>>(istream &input, KhachHang &a);
    friend void operator<<(ostream &output, KhachHang &b);
    friend class HoaDon;
};
class MatHang{
protected:
    string id, tenhang, giaban, nhomhang;
public:
    friend void init();
    friend void operator>>(istream &input, MatHang &a);
    friend void operator<<(ostream &output, MatHang &a);
    friend class HoaDon;
};
class HoaDon{
protected:
    string khach;
    vector<string> hang;
    vector<int> soluong;
public:
    friend void init();
    void create();
    void show();
    void lapHoaDon();
};
vector<KhachHang> kh;
vector<MatHang> mh;
vector<HoaDon> hd;
void init(){
    fstream file; file.open("KH.DAT", ios::in|ios::app);
    while(!file.eof()){
        KhachHang a;
        getline(file, a.hoten); if(a.hoten == "") break;
        getline(file, a.diachi); getline(file, a.phone);
        getline(file, a.id); getline(file, a.loaiKH);
        kh.push_back(a);
    }
    file.close();
    file.open("MH.DAT", ios::in|ios::app);
    while(!file.eof()){
        MatHang a;
        getline(file, a.tenhang); if(a.tenhang == "") break;
        getline(file, a.id); getline(file, a.nhomhang); getline(file, a.giaban);
        mh.push_back(a);
    }
    file.close();
    file.open("QL.DAT", ios::in|ios::app);
    while(!file.eof()){
        HoaDon a;
        getline(file, a.khach); if(a.khach == "") break;
        string s; getline(file, s);
        while(s!="*"){
            a.hang.push_back(s);
            int k; getline(file, s); istringstream(s)>>k; a.soluong.push_back(k);
            getline(file, s);
        }
        hd.push_back(a);
    }
    file.close();
}
void operator>>(istream &input, KhachHang &a){
    cin.ignore();
    cout<<"Nhap ten: "; getline(input, a.hoten);
    cout<<"Nhap dia chi: "; getline(input, a.diachi);
    cout<<"Nhap sdt: "; getline(input, a.phone);
    cout<<"Nhap loai khach hang(1.Mua le / 2.Mua buon):"; getline(input, a.loaiKH);
    cout<<"Nhap id: "; getline(input, a.id); if(a.id.length()!=5){cout<<"ID ko hop le!"; return;}
    for(int i = 0; i < kh.size(); i++){
        if(a.id == kh[i].id){
            cout<<"Trung id voi khach hang khac!"; return;
        }
    }
    kh.push_back(a);
    fstream file; file.open("KH.DAT", ios::out|ios::app);
    file<<a.hoten<<endl<<a.diachi<<endl<<a.phone<<endl<<a.id<<endl<<a.loaiKH<<endl;
    file.close();
}
void operator<<(ostream &output, KhachHang &a){
    output<<"Ten: "<<a.hoten<<endl;
    output<<"Dia chi: "<<a.diachi<<endl;
    output<<"Phone: "<<a.phone<<endl;
    output<<"ID: "<<a.id<<endl;
    output<<"Loai KH: "<<a.loaiKH<<endl;
}
void operator>>(istream &input, MatHang &a){
    cin.ignore();
    cout<<"Nhap ten: "; getline(input, a.tenhang);
    cout<<"Nhap id: "; getline(input, a.id); if(a.id.length() != 4){cout<<"ID ko hop le!";return;}
    for(int i = 0; i < mh.size(); i++){
        if(a.id == mh[i].id){
            cout<<"Trung id mat hang khac!"; return;
        }
    }
    cout<<"Nhap loai mat hang(1.thoi trang/2.tieu dung/3.dien may/4.gia dung): "; getline(input, a.nhomhang);
    cout<<"Nhap gia ban: "; getline(input, a.giaban);
    mh.push_back(a);
    fstream file; file.open("MH.DAT", ios::out|ios::app);
    file<<a.tenhang<<endl<<a.id<<endl<<a.nhomhang<<endl<<a.giaban<<endl;
    file.close();
}
void operator<<(ostream &output, MatHang &a){
    output<<"Ten :"<<a.tenhang<<endl;
    output<<"ID: "<<a.id<<endl;
    output<<"Nhom hang: "<<a.nhomhang<<endl;
    output<<"Gia ban: "<<a.giaban<<endl;
}
void HoaDon::create(){
    cin.ignore();
    cout<<"Nhap ma khach hang: "; getline(cin, khach);
    bool check = false;
    for(int i = 0; i < kh.size(); i++){
        if(khach == kh[i].id){
            check = true;
            break;
        }
    }
    if(check == false){cout<<"Khong tim thay khach hang!";return;}
    cout<<"Nhap so mat hang: "; int k; cin>>k;
    if(k > 10) {cout<<"Khong the mua qua 10 loai mat hang!"; return;}
    cin.ignore();
    for(int i = 0;  i < k; i++){
        cout<<"Nhap id mat hang: "; string s; getline(cin, s);
        check = false;
        for(int j = 0; j < mh.size(); j++){
            if(s == mh[j].id){
                for(int x = 0; x < hang.size(); x++){
                    if(s == hang[x]){
                        cout<<"Trung mat hang!"; return;
                    }
                }
                hang.push_back(s);
                cout<<"Nhap so luong: "; int m; cin>>m; cin.ignore();
                soluong.push_back(m);
                check = true;
            }
        }
        if(check == false){cout<<"Khong co mat hang nay!"<<endl; return;}
    }
    fstream file; file.open("QL.DAT", ios::out|ios::app);
    file<<khach<<endl;
    for(int i = 0; i < hang.size(); i++){
        file<<hang[i]<<endl<<soluong[i]<<endl;
    }
    file<<"*"<<endl;
    file.close();
}
void HoaDon::show(){
    for(int i = 0; i < kh.size(); i++){
        if(khach == kh[i].id){
            cout<<"Ten khach hang: "<<kh[i].hoten<<endl;
        }
    }
    for(int i = 0; i < hang.size(); i++){
        for(int j = 0; j < mh.size(); j++){
            if(hang[i] == mh[j].id){
                cout<<"Mat hang: "<<mh[j].tenhang<<endl;
                cout<<"So luong: "<<soluong[i]<<endl;
            }
        }
    }
}
void HoaDon::lapHoaDon(){
    for(int i = 0; i < kh.size(); i++){
        if(khach == kh[i].id){
            cout<<"Ten khach hang: "<<kh[i].hoten<<endl;
        }
    }
    int sum = 0;
    for(int i = 0; i < hang.size(); i++){
        for(int j = 0; j < mh.size(); j++){
            if(hang[i] == mh[j].id){
                cout<<"Mat hang: "<<mh[j].tenhang<<endl;
                cout<<"So luong: "<<soluong[i]<<endl;
                int k; istringstream(mh[j].giaban)>>k;
                cout<<"Gia: "<<soluong[j]<<"x"<<k<<"="<<soluong[j]*k<<endl;
                sum+=soluong[j]*k;
            }
        }
    }
    cout<<"So tien phai tra: "<<sum<<endl;
}
int main(){
    init();
    int a; cin>>a;
    if(a == 1){ KhachHang a; cin>>a; }
    if(a == 2){
        for(int i = 0; i < kh.size(); i++){
            cout<<kh[i];
        }
    }
    if(a == 3){
        MatHang a; cin>>a;
    }
    if(a == 4){
        for(int i = 0; i < mh.size(); i++){
            cout<<mh[i];
        }
    }
    if(a == 5){
        HoaDon a; a.create(); hd.push_back(a);
    }
    if(a == 6){
        for(int i = 0; i < hd.size(); i++){
            hd[i].show();
        }
    }
    if(a == 7){
        for(int i = 0; i < hd.size(); i++){
            hd[i].lapHoaDon();
        }
    }
    return 1;
}
