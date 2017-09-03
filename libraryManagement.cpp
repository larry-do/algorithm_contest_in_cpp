#include<iostream>
#include<string>
#include<fstream>
using namespace std;
enum careerEnum {HIGH_STUDENT,STUDENT,TEACHER};
enum subjectEnum {SCIENCE,SOCIAL,ELECTRONIC,IT};
class person {
private:
    string name;
    string address;
    string phone;
public:
    person(string _name,string _address,string _phone);
    ~person();
    string getName();
    string getAddress();
    string getPhone();
    void setName();
    void setAddress();
    void setPhone();
};
class libraryManagement;
class reader:public person{
private:
    int id;
    careerEnum career;
public:
    reader(string _name,string _address,string _phone,careerEnum _career);
    ~reader();
    int getID();
    careerEnum getCareer();
    void setCareer();
    friend class libraryManagement;
};
class book {
private:
    int id;
    string name;
    string author;
    string publishYear;
    subjectEnum subject;
public:
    book(string _name, string _author,string _publishYear,subjectEnum _subject);
    ~book();
    int getID();
    string getName();
    string getAuthor();
    string getPublishYear();
    subjectEnum getSubject();
    void setName();
    void setAuthor();
    void setPublishYear();
    void setSubject();
    friend class libraryManagement;
};
class libraryManagement{
public:
    void limitNumber();
    void statusOfBook();
};
//Methods
person::person(string _name,string _address,string _phone){
    name=_name;
    address=_address;
    phone=_phone;
}
person::~person(){
}
string person::getName(){
    return name;
}
string person::getAddress(){
    return address;
}
string person::getPhone(){
    return phone;
}
void person::setName(){
    cout<<"Nhap ho va ten: ";
    getline(cin,name);
}
void person::setAddress(){
    cout<<"Nhap dia chi: ";
    getline(cin,address);
}
void person::setPhone(){
    cout<<"Nhap so dien thoai: ";
    getline(cin,phone);
}
reader::reader(string _name,string _address,string _phone,careerEnum _career):person(_name,_address,_phone){
    career=_career;
}
reader::~reader(){
}
int reader::getID(){
    return id;
}
careerEnum reader::getCareer(){
    return career;
}
void reader::setCareer(){
    cout<<"Nhap loai ban doc: ";
    cout<<"1.Sinh vien"<<endl;
    cout<<"2.Hoc vien cao hoc"<<endl;
    cout<<"3.Giang vien"<<endl;
    int a;
    cin>>a;
    if(a==1) career=STUDENT;
    if(a==2) career=HIGH_STUDENT;
    if(a==3) career=TEACHER;
}
book::book(string _name, string _author,string _publishYear,subjectEnum _subject){
    name=_name;
    author=_author;
    publishYear=_publishYear;
    subject=_subject;
}
book::~book(){
}
int book::getID(){
    return id;
}
string book::getName(){
    return name;
}
string book::getAuthor(){
    return author;
}
string book::getPublishYear(){
    return publishYear;
}
subjectEnum book::getSubject(){
    return subject;
}
void book::setName(){
    cout<<"Nhap ten sach: ";
    getline(cin,name);
}
void book::setAuthor(){
    cout<<"Nhap ten tac gia: ";
    getline(cin,author);
}
void book::setPublishYear(){
    cout<<"Nhap nam xuat ban: ";
    getline(cin,publishYear);
}
void book::setSubject(){
    cout<<"Nhap ten chuyen nganh: "<<endl;
    cout<<"1.KHOA HOC"<<endl;
    cout<<"2.XA HOI"<<endl;
    cout<<"3.DIEN TU"<<endl;
    cout<<"4.CNTT"<<endl;
    int a;
    cin>>a;
    if(a==1) subject=SCIENCE;
    if(a==2) subject=SOCIAL;
    if(a==3) subject=ELECTRONIC;
    if(a==4) subject=IT;
}
//Main
int main(){

    return 0;
}
void importBook(){
    book a;
    a.setName();
    a.setAuthor();
    a.setSubject();
    a.setPublishYear();
}
