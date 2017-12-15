#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Nguoi{
	protected:
		string ten, diachi, phone;
};
class Nhanvien:public Nguoi{
	protected:
		string id, chuyenmon;
	public:
		friend void init();
		friend void operator>>(istream &i, Nhanvien &a);
		friend void operator<<(ostream &o, Nhanvien a);
};
class Duan{
	protected:
		string id, ten, kieu;
		int tong;
	public:
		friend void init();
		friend void operator>>(istream &i, Duan &a);
		friend void operator<<(ostream &o, Duan a);
};
vector<Nhanvien> nv;
vector<Duan> duan;
void init(){
	fstream file; file.open("nv.dat", ios::in|ios::app);
	while(!file.eof()){
		Nhanvien a;
		getline(file, a.ten); if(a.ten == "") break;
		getline(file, a.diachi); getline(file, a.phone);
		getline(file, a.id); getline(file, a.chuyenmon);
		nv.push_back(a);
	}
	file.close();
	file.open("duan.dat", ios::in|ios::app);
	while(!file.eof()){
		Duan a;
		getline(file, a.id); if(a.id == "") break;
		getline(file, a.ten); getline(file, a.kieu);
		string s; getline(file, s); istringstream(s)>>a.tong;
		duan.push_back(a);
	}
	file.close();
}
void operator>>(istream &i, Nhanvien &a){
	cout<<"Nhap ten: "; getline(i, a.ten);
	cout<<"Nhap dia chi: "; getline(i, a.diachi);
	cout<<"Nhap phone: "; getline(i, a.phone);
	cout<<"Nhap id: "; getline(i, a.id);
	if(a.id.length()!=5) {
		cout<<"ID khong hop le!"; return;
	}
	for(int i = 0; i < nv.size(); i++){
		if(a.id==nv[i].id){
			cout<<"Trung ID!"; return;
		}
	}
	cout<<"Nhap chuyen mon: "; getline(i, a.chuyenmon);
	nv.push_back(a);
	fstream file; file.open("nv.dat", ios::out|ios::app);
	file<<a.ten<<endl<<a.diachi<<endl<<a.phone<<endl<<a.id<<endl<<a.chuyenmon<<endl;
	file.close();
}
void operator<<(ostream &o, Nhanvien a){
	o<<"Ten: "<<a.ten<<endl;
	o<<"Dia chi: "<<a.diachi<<endl;
	o<<"Phone: "<<a.phone<<endl;
	o<<"ID: "<<a.id<<endl;
	o<<"Chuyen mon: "<<a.chuyenmon<<endl;
}
void operator>>(istream &i, Duan &a){
	cout<<"Nhap id: "; getline(i, a.id); if(a.id.length()!=5){
		cout<<"ID khong hop le!"; return;
	}
	for(int i = 0; i < duan.size(); i++){
		if(a.id == duan[i].id){
			cout<<"Trung id!"; return;
		}
	}
	cout<<"Nhap ten: "; getline(i, a.ten);
	cout<<"Nhap kieu du an(nho/trung binh/lon): "; getline(i, a.kieu);
	cout<<"Nhap tong kinh phi: "; string s; getline(i, s); istringstream(s)>>a.tong;
	duan.push_back(a);
	fstream file; file.open("duan.dat", ios::out|ios::app);
	file<<a.id<<endl<<a.ten<<endl<<a.kieu<<endl<<a.tong<<endl;
	file.close();
}
void operator<<(ostream &o, Duan a){
	cout<<"ID: "<<a.id<<endl;
	cout<<"Ten: "<<a.ten<<endl;
	cout<<"Kieu: "<<a.kieu<<endl;
	cout<<"Tong kinh phi: "<<a.kieu<<endl;
}
int main(){
	init();
	return 1;
}
