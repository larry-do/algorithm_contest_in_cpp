#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cctype>
struct Student {
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string sex;
    double score;
};
void showStudent(std::vector<Student> student){
    for(int i=0;i<student.size();i++){
        std::cout<<student[i].firstName<<' '<<student[i].middleName<<' '<<student[i].lastName<<std::endl;
        std::cout<<student[i].score<<std::endl;
        std::cout<<student[i].sex<<std::endl;
    }
}
void sortStudent(std::vector<Student> &student){//dùng insertsort// vì insertsort rất nhanh khi dữ liệu ít xáo trộn
    if(student.size() >= 2){
        for(int i=1;i<student.size();i++){
            std::string key = student[i].lastName+student[i].firstName+student[i].middleName;
            Student student_clone = student[i];
            int j=i-1;
            while(j>=0){
                std::string key_clone=student[j].lastName+student[j].firstName+student[j].middleName;
                if(key.compare(key_clone)>0) break;
                student[j+1]=student[j];
                j--;
            }
            student[j+1]=student_clone;
        }
    }
}
void addStudent(std::vector<Student> &student,int &numberOfStudent){
    Student a;
    std::cout<<"Nhap ho: ";
    fflush(stdin);
    std::cin>>a.firstName;
    std::cout<<"Nhap ten dem: ";
    fflush(stdin);
    std::cin>>a.middleName;
    std::cout<<"Nhap ten: ";
    fflush(stdin);
    std::cin>>a.lastName;
    std::cout<<"Nhap diem: ";
    fflush(stdin);
    std::cin>>a.score;
    std::cout<<"Nhap gioi tinh: ";
    fflush(stdin);
    std::cin>>a.sex;
    student.push_back(a);
    numberOfStudent++;
}
void outToFile(std::vector<Student> &student, std::string path){
    std::fstream file(path,std::ios::out);
    file<<student.size()<<std::endl;
    for(int i=0;i<student.size();i++){
        file<<student[i].firstName<<' '<<student[i].middleName<<' '<<student[i].lastName<<std::endl;
        file<<student[i].score<<std::endl;
        file<<student[i].sex<<std::endl;
    }
    file.close();
    std::cout<<"DONE!"<<std::endl;
}
int searchStudent(std::vector<Student> student){
    std::string keyword;
    std::cout<<"Nhap ten cua hoc sinh: "<<std::endl;
    fflush(stdin);
    std::cin>>keyword;//nên dùng hàm đưa về tất cả các chữ cái về chữ thường để không bị tìm kiếm sót
    int k=0;
    //không dùng binary sort được. muốn nhanh hơn phải dùng hash//thôi thì dùng tìm tuần tự
    std::cout<<"Ket qua: "<<std::endl;
    for(int i=0;i<student.size();i++){
        if(keyword.compare(student[i].lastName)==0){
            std::cout<<"ID: "<<i<<std::endl;
            std::cout<<student[i].firstName<<' '<<student[i].middleName<<' '<<student[i].lastName<<std::endl;
            std::cout<<student[i].score<<std::endl;
            std::cout<<student[i].sex<<std::endl;
            k++;
        }
    }
    if(!k) std::cout<<"Khong tim thay hoc sinh"<<std::endl;
    return k;
}
void deleteStudent(std::vector<Student> &student){
    if(searchStudent(student)){
        std::cout<<"Nhap ID sinh vien can xoa: ";
        int k;
        std::cin>>k;
        student.erase(student.begin()+k);
    }
}
void editStudent(std::vector<Student> &student){
    if(searchStudent(student)){
        std::cout<<"Nhap ID sinh vien can sua: ";
        int k;
        std::cin>>k;
        Student a;
        std::cout<<"Nhap ho: ";
        fflush(stdin);
        std::cin>>a.firstName;
        std::cout<<"Nhap ten dem: ";
        fflush(stdin);
        std::cin>>a.middleName;
        std::cout<<"Nhap ten: ";
        fflush(stdin);
        std::cin>>a.lastName;
        std::cout<<"Nhap diem: ";
        fflush(stdin);
        std::cin>>a.score;
        std::cout<<"Nhap gioi tinh: ";
        fflush(stdin);
        std::cin>>a.sex;
        student[k]=a;
    }
}
void sortScore(std::vector<Student> student){
    if(student.size() >= 2){
        for(int i=1;i<student.size();i++){
            double key = student[i].score;
            Student student_clone = student[i];
            int j=i-1;
            while(j>=0&&student[j].score<key){
                student[j+1]=student[j];
                j--;
            }
            student[j+1]=student_clone;
        }
    }
    showStudent(student);
}
void sortSex(std::vector<Student> student){
    if(student.size() >= 2){
        for(int i=1;i<student.size();i++){
            std::string key = student[i].sex;
            Student student_clone = student[i];
            int j=i-1;
            while(j>=0){
                std::string key_clone=student[j].sex;
                if(key.compare(key_clone)>0) break;
                student[j+1]=student[j];
                j--;
            }
            student[j+1]=student_clone;
        }
    }
    showStudent(student);
}
int main(){
    ///
    std::string path = "sinhvien.data";
    std::fstream file(path,std::ios::in);
    if(!file.is_open()){
        std::cout<<"Error. Not found data"<<std::endl;
        return 0;
    }
    int numberOfStudent=0;
    file>>numberOfStudent;
    std::vector<Student> student;
    for(int i=0;i<numberOfStudent;i++){
        Student a;
        //file.ignore();
        file>>a.firstName;
        file>>a.middleName;
        file>>a.lastName;
        file>>a.score;
        file>>a.sex;
        student.push_back(a);
    }
    file.close();
    sortStudent(student);
    ///
    int key = 0;
    std::cout<<"================================================"<<std::endl;
    std::cout<<"+        CHUONG TRINH QUAN LY SINH VIEN        +"<<std::endl;
    std::cout<<"================================================"<<std::endl;
    do{
        std::cout<<"================================================"<<std::endl;
        std::cout<<"1. THEM SINH VIEN"<<std::endl;
        std::cout<<"2. XOA SINH VIEN "<<std::endl;
        std::cout<<"3. SUA SINH VIEN"<<std::endl;
        std::cout<<"4. TIM KIEM SINH VIEN"<<std::endl;
        std::cout<<"5. DANH SACH SINH VIEN THEO TEN"<<std::endl;
        std::cout<<"6. DANH SACH SINH VIEN THEO DIEM"<<std::endl;
        std::cout<<"7. DANH SACH SINH VIEN THEO GIOI TINH"<<std::endl;
        std::cout<<"CHON CHUC NANG: ";
        std::cin>>key;
        switch(key){
            case 1:{
                std::cout<<"---Them sinh vien---"<<std::endl;
                addStudent(student,numberOfStudent);//nên chuẩn hóa string
                sortStudent(student);
                outToFile(student,path);
                break;
            }
            case 2:{
                std::cout<<"---Xoa sinh vien---"<<std::endl;
                deleteStudent(student);
                outToFile(student,path);
                break;
            }
            case 3:{
                std::cout<<"---Sua thong tin sinh vien---"<<std::endl;
                editStudent(student);
                sortStudent(student);
                outToFile(student,path);
                break;
            }
            case 4:{
                std::cout<<"---Tim kiem sinh vien---"<<std::endl;
                searchStudent(student);
                break;
            }
            case 5:{
                std::cout<<"---Hien thi danh sach theo ten---"<<std::endl;
                showStudent(student);
                break;
            }
            case 6:{
                std::cout<<"---Hien thi danh sach theo diem(giam)---"<<std::endl;
                sortScore(student);
                break;
            }
            case 7:{
                std::cout<<"---Hien thi danh sach theo gioi tinh---"<<std::endl;
                sortSex(student);
                break;
            }
            case 8:{
                std::cout<<"EXITED!"<<std::endl;
                break;
            }
            default:{
                std::cout<<"Khong hop le. Moi nhap lai"<<std::endl;
                return 0;
            }
        }

    }while(key != 8);
    return 1;
}
