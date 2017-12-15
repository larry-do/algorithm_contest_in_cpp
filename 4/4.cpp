#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
class Nguoi{
protected:
    string hoten, diachi, phone;
};
class NhanVien:public Nguoi{
protected:
    string id, ngay_ki;
public:
    friend void init();
    friend void operator>>(istream &in, NhanVien &a);
    friend void operator<<(ostream &out, NhanVien &a);
    friend class quanly;
};
class MatHang{
protected:
    string mahang, tenhang, nhomhang;
    int giaban, soluong;
public:
    friend void init();
    friend void operator>>(istream &in, MatHang &a);
    friend void operator<<(ostream &out, MatHang &a);
    friend class quanly;
};
class quanly{
private:
    string nv;
    vector<string> mh;
    vector<int> sl;
public:
    friend void init();
    bool create();
    void show();
};
vector<NhanVien> nvien;
vector<MatHang> mhang;
vector<quanly> qly;
void init(){
    fstream file; file.open("nv.dat", ios::in | ios::app);
    while(!file.eof()){
        NhanVien a;
        getline(file, a.hoten); getline(file, a.diachi); getline(file, a.phone);
        getline(file, a.id); getline(file, a.ngay_ki);
        if(a.hoten == "" || a.diachi == "" || a.phone == "" || a.id == "" || a.ngay_ki == "") break;
        nvien.push_back(a);
    }
    file.close();
    file.open("mh.dat", ios::in | ios::app);
    while(!file.eof()){
        MatHang a;
        getline(file, a.tenhang); getline(file, a.mahang); getline(file, a.nhomhang);
        string s; getline(file, s); istringstream(s)>>a.soluong;
        getline(file, s); istringstream(s)>>a.giaban;
        if(a.tenhang == "" || a.mahang == "" || a.nhomhang == "" || a.soluong <= 0 || a.giaban < 0 ) break;
        mhang.push_back(a);
    }
    file.close();
    file.open("ql.dat", ios::in | ios::app);
    while(!file.eof()){
        quanly a;
        getline(file, a.nv); if(a.nv == "") break;
        string s; getline(file, s);
        while(s!="*"){
            a.mh.push_back(s);
            getline(file, s); int k; istringstream(s)>>k; a.sl.push_back(k);
            getline(file, s);
        }
        qly.push_back(a);
    }
    file.close();
}
void operator>>(istream &in, NhanVien &a){
    cout<<"Nhap ten: "; getline(in, a.hoten);
    cout<<"Nhap dia chi: "; getline(in, a.diachi);
    cout<<"Nhap phone: "; getline(in, a.phone);
    cout<<"Nhap id: "; getline(in, a.id); if(a.id.length() != 4) {cout<<"ID ko hop le!"; return;}
    for(int i = 0; i < nvien.size(); i++){
        if(a.id == nvien[i].id){
            cout<<"Trung id!"; return;
        }
    }
    cout<<"Nhap ngay ki hop dong: "; getline(in, a.ngay_ki);
    nvien.push_back(a);
    fstream file; file.open("nv.dat", ios::out|ios::app);
    file<<a.hoten<<endl<<a.diachi<<endl<<a.phone<<endl<<a.id<<endl<<a.ngay_ki<<endl;
    file.close();
}
void operator<<(ostream &out, NhanVien &a){
    out<<"Ten: "<<a.hoten<<endl;
    out<<"Dia chi: "<<a.diachi<<endl;
    out<<"Phone: "<<a.phone<<endl;
    out<<"ID: "<<a.id<<endl;
    out<<"Ngay ki HD: "<<a.ngay_ki<<endl;
}
void operator>>(istream &in, MatHang &a){
    cout<<"Ten MH: "; getline(in, a.tenhang);
    cout<<"Ma MH: "; getline(in, a.mahang); if(a.mahang.length() != 4) {cout<<"ID ko hop le!"; return;}
    for(int i = 0; i < mhang.size(); i++){
        if(a.mahang == mhang[i].mahang){
            cout<<"Trung id!"; return;
        }
    }
    cout<<"Nhom hang(Dien tu/Dien lanh/May tinh/Thiet bi van phong): "; getline(in, a.nhomhang);
    cout<<"So luong: "; in >> a.soluong;
    cout<<"Gia ban: "; in >> a.giaban;
    mhang.push_back(a);
    fstream file; file.open("mh.dat", ios::out|ios::app);
    file<<a.tenhang<<endl<<a.mahang<<endl<<a.nhomhang<<endl<<a.soluong<<endl<<a.giaban<<endl;
    file.close();
}
void operator<<(ostream &out, MatHang &a){
    out<<"Ten hang: "<<a.tenhang<<endl;
    out<<"Ma hang: "<<a.mahang<<endl;
    out<<"Nhom hang: "<<a.nhomhang<<endl;
    out<<"So luong: "<<a.soluong<<endl;
    out<<"Gia ban: "<<a.giaban<<endl;
}
bool quanly::create(){
    cout<<"Nhap ID NV: "; getline(cin, nv);
    bool check_1 = false;
    for(int i = 0; i < nvien.size(); i++){
        if(nv == nvien[i].id){
            check_1 = true;
            cout<<"Nhap so loai mat hang: "; int k; cin>>k; if(k > 5) {cout<<"Khong duoc phep ban qua 5 mat hang!"; return false;}
            cin.ignore();
            for(int j = 0; j < k; j++){
                cout<<"Nhap ma mat hang: "; string s; getline(cin, s);
                bool check_2 = false;
                for(int n = 0; n < mhang.size(); n++){
                    if(s == mhang[n].mahang){
                        for(int m = 0; m < mh.size(); m++){
                            if(s == mh[m]){cout<<"Trung mat hang!";return false;}
                        }
                        check_2 = true;
                        mh.push_back(s);
                        cout<<"Nhap so luong: "; int b; cin>>b; cin.ignore();
                        sl.push_back(b);
                    }
                }
                if(!check_2) {cout<<"Khong tim thay mat hang!"; return false;}
            }
        }
    }
    if(!check_1) {cout<<"Khong tim thay nhan vien!"; return false;}
    fstream file; file.open("ql.dat", ios::out|ios::app);
    file<<nv<<endl;
    for(int i = 0; i < mh.size(); i++){
        file<<mh[i]<<endl<<sl[i]<<endl;
    }
    file<<"*"<<endl;
    file.close();
}
void quanly::show(){
    for(int i = 0; i < nvien.size(); i++){
        if(nv == nvien[i].id){
            cout<<"Ten: "<<nvien[i].hoten<<endl; break;
        }
    }
    for(int i = 0; i < mh.size(); i++){
        for(int j = 0; j < mhang.size(); j++){
            if(mh[i] == mhang[j].mahang){
                cout<<mhang[j].tenhang<<endl;
                cout<<sl[i]<<endl;
            }
        }
    }
}
int main(){
    init();
    int c = 6;
    if(c == 1){
        NhanVien a; cin>>a;
    }
    if(c == 2){
        for(int i = 0; i < nvien.size(); i++){
            cout<<nvien[i];
        }
    }
    if(c == 3){
        MatHang a; cin>>a;
    }
    if(c == 4){
        for(int i = 0; i < mhang.size(); i++){
            cout<<mhang[i];
        }
    }
    if(c == 5){
        quanly a; if(a.create()) qly.push_back(a);
    }
    if(c == 6){
        for(int i = 0; i < qly.size(); i++){
            qly[i].show();
        }
    }
    return 1;
}
