#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;
class QuanLy;
class Nguoi{
protected:
    string hoTen, diaChi, sdt;
};
class BanDoc:public Nguoi{
protected:
    string id;
    int loaiBandoc;
public:
    friend void initProgram();
    friend void operator>>(istream &input, BanDoc &a);
    friend void operator<<(ostream &output, BanDoc &a);
    friend void addQL();
    friend void searchQL();
    friend bool nameCompare(QuanLy a, QuanLy b);
    friend void sortName();
    friend class QuanLy;
};
class Sach{
private:
    string id, tenSach, tacGia;
    int loaiSach, namXuatBan;
public:
    friend void initProgram();
    friend void operator>>(istream &input, Sach &a);
    friend void operator<<(ostream &output, Sach &a);
    friend void addQL();
    friend class QuanLy;
};
class QuanLy{
private:
    BanDoc bd;
    vector<Sach> bk;
    vector< vector<string> > stt;
public:
    friend void addQL();
    friend void initProgram();
    friend void showQL();
    friend void searchQL();
    friend bool nameCompare(QuanLy a, QuanLy b);
    friend bool numberCompare(QuanLy a, QuanLy b);
    friend void sortName();
    friend void sortBooksNumber();
};
vector<BanDoc> reader;
vector<Sach> book;
vector<QuanLy> manager;
void initProgram(){
    fstream file; file.open("BD.DAT", ios::in|ios::app); // nen them cai kiem tra file da mo chua
    while(!file.eof()){
        BanDoc a;
        getline(file, a.hoTen); getline(file, a.diaChi); getline(file, a.sdt); getline(file, a.id);
        string type; getline(file, type); istringstream(type)>>a.loaiBandoc;
        if(a.hoTen == "" || a.diaChi == "" || a.sdt == "" || a.id == "" || a.loaiBandoc == 0) break;
        reader.push_back(a);
    }
    file.close();
    file.open("SACH.DAT", ios::in|ios::app);
    while(!file.eof()){
        Sach a;
        getline(file, a.tenSach); getline(file, a.tacGia); getline(file, a.id);
        string ss; getline(file, ss); istringstream(ss)>>a.loaiSach;
        getline(file, ss); istringstream(ss)>>a.namXuatBan;
        if(a.tenSach == "" || a.tacGia == "" || a.id == "" || a.loaiSach == 0 || a.namXuatBan == 0) break;
        book.push_back(a);
    }
    file.close();
    file.open("QL.DAT", ios::in|ios::app);
    while(!file.eof()){
        QuanLy a;
        getline(file, a.bd.id); if(a.bd.id == "") break;
        int k; istringstream(a.bd.id) >> k; a.bd = reader[k - 1];
        string ss; getline(file, ss);
        while(ss != "*"){
            int k; istringstream(ss) >> k;
            a.bk.push_back(book[k - 1]);
            getline(file, ss); istringstream(ss) >> k;
            vector<string> b;
            for(int i = 0; i < k; i++){
                getline(file, ss); b.push_back(ss);
            }
            a.stt.push_back(b);
            getline(file, ss);
        }
        manager.push_back(a);
    }
    file.close();
}
void operator>>(istream &input, BanDoc &a){
    input.ignore();
    cout<<"Nhap ten: "; getline(input, a.hoTen);
    cout<<"Nhap dia chi: "; getline(input, a.diaChi);
    cout<<"Nhap SDT: ";getline(input, a.sdt);
    ostringstream s; s<<reader.size()+1; a.id = s.str(); a.id.insert(0,5 - a.id.length(), '0');
    cout<<"Nhap loai ban doc(1.Sinh vien/2.Hoc vien cao hoc/3.Giao vien): "; input>>a.loaiBandoc;
    fstream banDocFile; banDocFile.open("BD.DAT", ios::out|ios::app); // nen co them kiem tra file da mo duoc chua
    banDocFile<<a.hoTen<<endl<<a.diaChi<<endl<<a.sdt<<endl<<a.id<<endl<<a.loaiBandoc<<endl;
    banDocFile.close();
    reader.push_back(a);
}
void operator<<(ostream &output, BanDoc &a){
    output<<"Ten: "<<a.hoTen<<endl;
    output<<"Dia chi: "<<a.diaChi<<endl;
    output<<"SDT: "<<a.sdt<<endl;
    output<<"ID: "<<a.id<<endl;
    output<<"Loai ban doc: ";
    if(a.loaiBandoc == 1) output<<"Sinh vien"<<endl;
    if(a.loaiBandoc == 2) output<<"Hoc vien cao hoc"<<endl;
    if(a.loaiBandoc == 3) output<<"Giao vien"<<endl;
}
void operator>>(istream &input, Sach &a){
    input.ignore();
    cout<<"Nhap ten sach: "; getline(input, a.tenSach);
    cout<<"Nhap tac gia: "; getline(input, a.tacGia);
    ostringstream s; s<<book.size()+1; a.id = s.str(); a.id.insert(0,5 - a.id.length(), '0');
    cout<<"Nhap nam xuat ban: "; input>>a.namXuatBan;
    cout<<"Nhap loai sach (1.KH_TN/2.VH_NT/3.DT_VT/4.CN_TT): "; input>>a.loaiSach;
    book.push_back(a);
    fstream file; file.open("SACH.DAT", ios::out|ios::app);
    file<<a.tenSach<<endl<<a.tacGia<<endl<<a.id<<endl<<a.loaiSach<<endl<<a.namXuatBan<<endl;
    file.close();
}
void operator<<(ostream &output, Sach &a){
    output<<"Ten sach: "<<a.tenSach<<endl;
    output<<"Tac gia: "<<a.tacGia<<endl;
    output<<"ID: "<<a.id<<endl;
    output<<"Loai sach: ";
    if(a.loaiSach == 1) output<<"KH_TN"<<endl;
    if(a.loaiSach == 2) output<<"VH_NT"<<endl;
    if(a.loaiSach == 3) output<<"DT_VT"<<endl;
    if(a.loaiSach == 4) output<<"CN_TT"<<endl;
    output<<"Nam xuat ban: "<<a.namXuatBan<<endl;
}
void addQL(){
    cout<<"Nhap ID ban doc: "; cin.ignore(); string s; getline(cin, s);
    int k; istringstream(s) >> k;
    if(k > reader.size() || k < 1){
        cout<<"Khong tim thay ban doc"<<endl; return;
    }
    bool flag = false;
    for(int i = 0; i < manager.size(); i++){
        if(s == manager[i].bd.id){
            cout<<"Nhap ID sach: "; string s; getline(cin, s);
            istringstream(s) >> k;
            if(k > book.size() || k < 1){
                cout<<"Khong tim thay sach!"<<endl; return;
            }
            bool check = false;
            for(int j = 0; j < manager[i].bk.size(); j++){
                if(s == manager[i].bk[j].id){
                    if(manager[i].stt[j].size() >= 3){
                        cout<<"Ban doc nay da muon qua 3 quyen cung dau sach!"<<endl; return;
                    }
                    cout<<"Ghi tinh trang sach: "; getline(cin, s);
                    manager[i].stt[j].push_back(s); check = true; break;
                }
            }
            if(!check){
                if(manager[i].bk.size() >=5 ){
                    cout<<"Ban doc nay da muon qua 5 dau sach!"<<endl; return;
                }
                manager[i].bk.push_back(book[k-1]);
                cout<<"Ghi tinh trang sach: "; getline(cin, s);
                vector<string> b; b.push_back(s);
                manager[i].stt.push_back(b);
            }
            flag = true; break;
        }
    }
    if(!flag){
        QuanLy a; a.bd = reader[k - 1];
        cout<<"Nhap ID sach: "; string s; getline(cin, s);
        istringstream(s) >> k;
        if(k > book.size() || k < 1){
            cout<<"Khong tim thay sach!"<<endl; return;
        }
        a.bk.push_back(book[k - 1]);
        cout<<"Ghi tinh trang sach: "; getline(cin, s);
        vector<string> b; b.push_back(s);
        a.stt.push_back(b);
        manager.push_back(a);
    }
    fstream file; file.open("QL.DAT", ios::out|ios::trunc);
    for(int i = 0; i < manager.size(); i++){
        file<<manager[i].bd.id<<endl;
        for(int j = 0; j < manager[i].bk.size(); j++){
            file<<manager[i].bk[j].id<<endl<<manager[i].stt[j].size()<<endl;
            for(int k = 0; k < manager[i].stt[j].size(); k++){
                file<<manager[i].stt[j][k]<<endl;
            }
        }
        file<<"*"<<endl;
    }
    file.close();
}
void showQL(){
    for(int i = 0; i < manager.size(); i++){
        cout<<"======================="<<endl;
        cout<<"--Ban doc--"<<endl;
        cout<<manager[i].bd;
        cout<<"--Sach muon--"<<endl;
        for(int j = 0; j < manager[i].bk.size(); j++){
            cout<<manager[i].bk[j];
            cout<<"So luong: "<<manager[i].stt[j].size()<<endl;
            cout<<"Tinh trang: "<<endl;
            for(int k = 0; k < manager[i].stt[j].size(); k++){
                cout<<k+1<<". "<<manager[i].stt[j][k]<<endl;
            }
        }
    }
}
void searchQL(){
    cout<<"Nhap ten ban doc: ";
    string name; cin.ignore(); getline(cin, name);
    bool check = false;
    for(int i = 0; i < manager.size(); i++){
        if(name == manager[i].bd.hoTen){
            cout<<"--Ban doc--"<<endl;
            cout<<manager[i].bd;
            cout<<"--Sach muon--"<<endl;
            for(int j = 0; j < manager[i].bk.size(); j++){
                cout<<manager[i].bk[j];
                cout<<"So luong: "<<manager[i].stt[j].size()<<endl;
                cout<<"Tinh trang: "<<endl;
                for(int k = 0; k < manager[i].stt[j].size(); k++){
                    cout<<k+1<<". "<<manager[i].stt[j][k]<<endl;
                }
            }
            check = true; break;
        }
    }
    if(!check) cout<<"Khong tim thay ban doc!"<<endl;
}
bool nameCompare(QuanLy a, QuanLy b){
    if(a.bd.hoTen.compare(b.bd.hoTen) < 0) return true;
    else return false;
}
bool numberCompare(QuanLy a, QuanLy b){
    int m = 0,n = 0;
    for(int i = 0; i < a.stt.size(); i++){
        m+=a.stt[i].size();
    }
    for(int i = 0; i < b.stt.size(); i++){
        n+=b.stt[i].size();
    }
    return m > n;
}
void sortName(){
    sort(manager.begin(), manager.end(), nameCompare);
    showQL();
}
void sortBooksNumber(){
    sort(manager.begin(), manager.end(), numberCompare);
    showQL();
}
int main(){
    initProgram();
    int choose = 0;
    cout<<"QUAN LY THU VIEN"<<endl;
    cout<<"1.Them ban doc"<<endl;
    cout<<"2.In danh sach ban doc"<<endl;
    cout<<"3.Them dau sach"<<endl;
    cout<<"4.In danh sach cac dau sach"<<endl;
    cout<<"5.Them sach muon"<<endl;
    cout<<"6.In danh sach quan ly"<<endl;
    cout<<"7.Tim kiem quan ly"<<endl;
    cout<<"8.Sap xep quan ly theo ten ban doc"<<endl;
    cout<<"9.Sap xep quan ly theo so luong sach muon"<<endl;
    cout<<"Chon chuc nang: "; cin>>choose;
    cout<<"++++++++++++++++++++++"<<endl;
    switch(choose){
    case 1:{
        BanDoc a; cin>>a; reader.push_back(a); break;
    }
    case 2:{
        for(int i = 0; i < reader.size(); i++){
            cout<<"===================="<<endl;
            cout<<reader[i];
        }
        break;
    }
    case 3:{
        Sach a; cin>>a; book.push_back(a); break;
    }
    case 4:{
        for(int i = 0; i < book.size(); i++){
            cout<<"===================="<<endl;
            cout<<book[i];
        }
        break;
    }
    case 5:{
        addQL(); break;
    }
    case 6:{
        showQL(); break;
    }
    case 7:{
        searchQL(); break;
    }
    case 8:{
        sortName(); break;
    }
    case 9:{
        sortBooksNumber(); break;
    }
    default: cout<<"Khong hop le";
    }
    return 1;
}
