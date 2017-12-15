#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Nguoi{
protected:
	string hoten, diachi, phone;
};
class NhanVien : public Nguoi{
protected:
	string id;
	int bacluong;
public:
	friend void init();
	friend void operator>>(istream &in, NhanVien &a);
	friend void operator<<(ostream &out, NhanVien &a);
	friend class quanly;
};
class PhongBan{
protected:
	string id, ten, mota;
	double heso;
public:
	friend void init();
	friend void operator>>(istream &in, PhongBan &a);
	friend void operator<<(ostream &out, PhongBan a);
	friend class quanly;	
};
class quanly{
private:
	string nvien, pban;
	int day;
public:
	friend void init();
	bool create();
	void show();	
};
vector<NhanVien> nv;
vector<PhongBan> pb;
vector<quanly> ql;
void init(){
	fstream file; file.open("nv.dat", ios::in|ios::app);
	while(!file.eof()){
		NhanVien a;
		getline(file, a.hoten); getline(file, a.diachi); getline(file, a.phone);
		getline(file, a.id); string s; getline(file, s); istringstream(s)>>a.bacluong;
		if(a.hoten == "") break;
		nv.push_back(a);
	}
	file.close();
	file.open("pb.dat", ios::in|ios::app);
	while(!file.eof()){
		PhongBan a;
		getline(file, a.id); getline(file, a.ten); getline(file, a.mota);
		string s; getline(file, s); istringstream(s)>>a.heso;
		if(a.id== "") break;
		pb.push_back(a);
	}
	file.close();
	file.open("qly.dat", ios::in|ios::app);
	while(!file.eof()){
		quanly a;
		getline(file, a.nvien); if(a.nvien=="") break;
		getline(file, a.pban);
		string s; getline(file, s); istringstream(s)>>a.day;
		ql.push_back(a);
	}
	file.close();
}
void operator>>(istream &in, NhanVien &a){
	cout<<"Nhap ten: "; getline(in, a.hoten);
	cout<<"Nhap dia chi: "; getline(in, a.diachi);
	cout<<"Nhap phone: "; getline(in, a.phone);
	cout<<"Nhap id: "; getline(in, a.id); if(a.id.length() != 4) { cout<<"ID ko hop le!"; return; }
	for(int i = 0; i < nv.size(); i++){
		if(a.id == nv[i].id){
			cout<<"Trung id!"; return;
		}
	}
	cout<<"Nhap bac luong: "; string s; getline(in, s); istringstream(s)>>a.bacluong; if(a.bacluong<1 || a.bacluong>9){cout<<"Bac luong sai!"; return;}
	fstream file; file.open("nv.dat", ios::out|ios::app);
	file<<a.hoten<<endl<<a.diachi<<endl<<a.phone<<endl<<a.id<<endl<<a.bacluong<<endl;
	file.close();
}
void operator<<(ostream &out, NhanVien &a){
	out<<"Ten: "<<a.hoten<<endl;
	out<<"Dia chi: "<<a.diachi<<endl;
	out<<"Phone: "<<a.phone<<endl;
	out<<"ID: "<<a.id<<endl;
	out<<"Bac luong: "<<a.bacluong<<endl;
}
void operator>>(istream &in, PhongBan &a){
	cout<<"Nhap id: "; getline(in, a.id); if(a.id.length() != 3) return;
	for(int i = 0; i < pb.size(); i++){
		if(a.id == pb[i].id) {cout<<"Trung id!"; return;}
	}
	cout<<"Nhap ten: "; getline(in, a.ten);
	cout<<"Mo ta: "; getline(in, a.mota);
	cout<<"He so: "; cin>>a.heso; cin.ignore();
	fstream file; file.open("pb.dat", ios::out|ios::app);
	file<<a.id<<endl<<a.ten<<endl<<a.mota<<endl<<a.heso<<endl;
	file.close();
}
void operator<<(ostream &out, PhongBan a){
	out<<"ID: "<<a.id<<endl;
	out<<"Ten: "<<a.ten<<endl;
	out<<"Mo ta: "<<a.mota<<endl;
	out<<"He so cong viec"<<a.heso<<endl;
}
bool quanly::create(){
	bool check = false;
	cout<<"Nhap id nhan vien: ";getline(cin, nvien);
	for(int i = 0; i < nv.size(); i++){
		if(nvien == nv[i].id){
			check = true; break;
		}
	}
	if(!check) {
		cout<<"Khong tim thay nhan vien!"; return false;
	}
	for(int i = 0; i < ql.size(); i++){
		if(nvien == ql[i].nvien){
			cout<<"Da lap bang quan ly cho nguoi nay!"; return false;
		}
	}
	check = false;
	cout<<"Nhap id phong ban: ";getline(cin, pban);
	for(int i = 0; i < pb.size(); i++){
		if(pban == pb[i].id){
			check = true; break;
		}
	}
	if(!check) {
		cout<<"Khong tim thay phong ban!"; return false;
	}
	cout<<"Nhap so ngay lam viec: ";cin>>day; cin.ignore();
	fstream file; file.open("qly.dat", ios::out|ios::app);
	file<<nvien<<endl<<pban<<endl<<day<<endl;
	file.close();
	return true;
}
void quanly::show(){
	for(int i = 0; i < nv.size(); i++){
		if(nvien == nv[i].id){
			cout<<nv[i].hoten<<endl; break;
		}
	}
	for(int i = 0; i < pb.size(); i++){
		if(pban == pb[i].id){
			cout<<pb[i].ten<<endl<<day<<endl; break;
		}
	}
}
int main(){
	init();
    return 1;
}
