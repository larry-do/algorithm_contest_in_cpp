#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<ctime>
using namespace std;
class Nguoi{
protected:
    string hoTen, diaChi, sdt;
};
class SinhVien:public Nguoi{
protected:
    string maSV, lopHoc;
public:
    friend class BangDangKi;
    friend void initProgram();
    friend void operator>>(istream &input, SinhVien &a);
    friend void operator<<(ostream &output, SinhVien &a);
    friend void addDK();
};
class MonHoc{
private:
    string maMH, tenMH;
    int tongSoTiet, loaiMH;
public:
    friend class BangDangKi;
    friend void initProgram();
    friend void operator>>(istream &input, MonHoc &a);
    friend void operator<<(ostream &output, MonHoc &a);
    friend void addDK();
};
class BangDangKi{
private:
    SinhVien sivi;
    vector<string> moho;
    time_t tg;
public:
    friend void initProgram();
    friend void addDK();
    friend void showDK();
};
vector<SinhVien> sv;
vector<MonHoc> mh;
vector<BangDangKi> bdk;
void initProgram(){
    fstream file; file.open("SV.DAT", ios::in);
    while(!file.eof()){
        SinhVien a;
        getline(file, a.hoTen); getline(file, a.diaChi); getline(file, a.sdt);
        getline(file, a.maSV); getline(file, a.lopHoc);
        if(a.hoTen == "" || a.diaChi == "" || a.sdt == "" || a.maSV == "" || a.lopHoc == "") break;
        sv.push_back(a);
    }
    file.close();
    file.open("MH.DAT", ios::in);
    while(!file.eof()){
        MonHoc a;
        getline(file, a.tenMH); getline(file, a.maMH);
        string ss; getline(file, ss); istringstream(ss)>>a.tongSoTiet;
        getline(file, ss); istringstream(ss)>>a.loaiMH;
        if(a.tenMH == "" || a.maMH == ""|| a.tongSoTiet == 0 || a.loaiMH == 0) break;
        mh.push_back(a);
    }
    file.close();
    file.open("QL.DAT", ios::in);
    while(!file.eof()){
        BangDangKi a;
        getline(file, a.sivi.maSV); if(a.sivi.maSV == "") break;
        for(int i = 0; i < sv.size(); i++){
            if(a.sivi.maSV == sv[i].maSV){
                a.sivi = sv[i];
            }
        }
        string t; getline(file, t); istringstream(t)>>a.tg;
        string ss; getline(file, ss);
        while(ss!="*"){
            a.moho.push_back(ss);
            getline(file, ss);
        }
        bdk.push_back(a);
    }
    file.close();
}
void operator>>(istream &input, SinhVien &a){
    input.ignore();
    cout<<"Nhap ten sinh vien: "; getline(input, a.hoTen);
    cout<<"Nhap dia chi: "; getline(input, a.diaChi);
    cout<<"Nhap SDT: "; getline(input, a.sdt);
    cout<<"Nhap ma sinh vien: "; getline(input, a.maSV);
    if(a.maSV.size() != 5){
        cout<<"Ma sinh vien khong hop le"<<endl; return;
    }
    for(int i = 0; i < sv.size(); i++){
        if(a.maSV == sv[i].maSV){
            cout<<"Trung ma sinh vien"<<endl; return;
        }
    }
    cout<<"Nhap lop hoc: "; getline(input, a.lopHoc);
    fstream file; file.open("SV.DAT", ios::out|ios::app);
    file<<a.hoTen<<endl<<a.diaChi<<endl<<a.sdt<<endl<<a.maSV<<endl<<a.lopHoc<<endl;
    file.close();
    sv.push_back(a);
}
void operator<<(ostream &output, SinhVien &a){
    output<<"Ho ten: "<<a.hoTen<<endl;
    output<<"Dia chi: "<<a.diaChi<<endl;
    output<<"SDT: "<<a.sdt<<endl;
    output<<"Ma SV: "<<a.maSV<<endl;
    output<<"Lop hoc: "<<a.lopHoc<<endl;
}
void operator>>(istream &input, MonHoc &a){
    input.ignore();
    cout<<"Nhap ten mon hoc: "; getline(input, a.tenMH);
    cout<<"Nhap ma mon hoc: "; getline(input, a.maMH);
    if(a.maMH.size() != 3){
        cout<<"Ma mon hoc khong hop le"<<endl; return;
    }
    for(int i = 0; i < mh.size(); i++){
        if(a.maMH == mh[i].maMH){
            cout<<"Trung ma mon hoc"<<endl; return;
        }
    }
    cout<<"Nhap tong so tiet: "; input>>a.tongSoTiet;
    cout<<"Nhap loai mon hoc(1.Dai cuong / 2.Co so nganh / 3. Bat buoc / 4.Tu chon): "; input>>a.loaiMH;
    fstream file; file.open("MH.DAT", ios::out|ios::app);
    file<<a.tenMH<<endl<<a.maMH<<endl<<a.tongSoTiet<<endl<<a.loaiMH<<endl;
    file.close();
    mh.push_back(a);
}
void operator<<(ostream &output, MonHoc &a){
    output<<"Ten mon hoc: "<<a.tenMH<<endl;
    output<<"ID: "<<a.maMH<<endl;
    output<<"Tong so tiet: "<<a.tongSoTiet<<endl;
    output<<"Loai mon hoc: ";
    if(a.loaiMH == 1) cout<<"Dai cuong"<<endl;
    if(a.loaiMH == 2) cout<<"Co so nganh"<<endl;
    if(a.loaiMH == 3) cout<<"Bat buoc"<<endl;
    if(a.loaiMH == 4) cout<<"Tu chon"<<endl;
}
void addDK(){
    cin.ignore();
    BangDangKi a;
    cout<<"Nhap ma sinh vien: "; string s; getline(cin, s);
    bool check_1 = false;
    for(int i = 0; i < sv.size(); i++){
        if(s == sv[i].maSV){
            check_1 = true;
            a.sivi = sv[i];
            cout<<"Nhap so mon hoc: "; int k; cin >> k;
            if(k > 8){
                cout<<"Khong the dang ki qua 8 mon 1 ki!"<<endl; return;
            }
            cin.ignore();
            for(int j = 0; j < k; j ++){
                cout<<"Nhap ma mon hoc: "; getline(cin, s);
                bool check_2 = false;
                for(int n = 0; n < mh.size(); n++){
                    if(s == mh[n].maMH){
                        check_2 = true;
                        for(int m = 0; m < a.moho.size(); m++){
                            if(s == a.moho[m]){
                                cout<<"Da dang ki mon nay"; break;
                            }
                        }
                        a.moho.push_back(s);
                        break;
                    }
                }
                if(!check_2){ cout<<"Khong tim thay mon hoc!"; return;}
            }
            a.tg = time(0);
            bdk.push_back(a);
            break;
        }
    }
    if(!check_1){cout<<"Khong tim thay sinh vien!"; return;}
    fstream file; file.open("QL.DAT", ios::out);
    file<<a.sivi.maSV<<endl<<a.tg<<endl;
    for(int i = 0; i < a.moho.size(); i++){
        file<<a.moho[i]<<endl;
    }
    file<<"*"<<endl;
    file.close();
}
void showDK(){
    for(int i = 0; i < bdk.size(); i++){
        cout<<bdk[i].sivi;
        for(int j = 0; j < bdk[i].moho.size(); j++){
            cout<<bdk[i].moho[j]<<endl;
        }
        char *dt = ctime(&bdk[i].tg);
        cout<<dt<<endl;
    }
}
int main(){
    initProgram();
    cout<<"CHUONG TRINH DANG KI TIN CHI"<<endl;
    cout<<"1.Them sinh vien"<<endl;
    cout<<"2.In danh sach sinh vien"<<endl;
    cout<<"3.Them mon hoc"<<endl;
    cout<<"4.In danh sach mon hoc"<<endl;
    cout<<"Chon chuc nang: "; int choose; cin>>choose;
    cout<<"++++++++++++++++++++++"<<endl;
    switch(choose){
    case 1:{
        SinhVien a; cin>>a; break;
    }
    case 2:{
        for(int i = 0; i < sv.size(); i++){
            cout<<sv[i];
        }
        break;
    }
    case 3:{
        MonHoc a; cin>>a; break;
    }
    case 4:{
        for(int i = 0; i < mh.size(); i++){
            cout<<mh[i];
        }
        break;
    }
    case 5:{
        addDK();
        break;
    }
    case 6:{
        showDK();
        break;
    }
    }
    return 1;
}
