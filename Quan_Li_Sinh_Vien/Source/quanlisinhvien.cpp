/*
* File: quanlikhachsan.cpp
* Author: Le Duy Hao
* Date: 1/09/2023
* Description: This is a file which implements the methods of the classes and function in the program.
*/

#include "quanlisinhvien.h"

//--------------------------------CLASS--------------------------------

SinhVien::SinhVien(){
    this->ID = 0;

    this->NAME = "";
    this->TUOI = 0;
    this->GIOITINH = NAM;
    this->DIEM_TOAN = 0;
    this->DIEM_LY = 0;
    this->DIEM_HOA = 0;
}

SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa){
    this->ID = id;
    id++;

    this->NAME = name;
    this->TUOI = tuoi;
    this->GIOITINH = gioitinh;
    this->DIEM_TOAN = diem_toan;
    this->DIEM_LY = diem_ly;
    this->DIEM_HOA = diem_hoa;
}

void SinhVien::setName(string name){
    this->NAME = name;
}

void SinhVien::setTuoi(int tuoi){
    this->TUOI = tuoi;
}

void SinhVien::setGioiTinh(typeGioiTinh gioitinh){
    this->GIOITINH = gioitinh;
}

void SinhVien::setDiemToan(double diem_toan){
    this->DIEM_TOAN = diem_toan;
}

void SinhVien::setDiemLy(double diem_ly){
    this->DIEM_LY = diem_ly;
}

void SinhVien::setDiemHoa(double diem_hoa){
    this->DIEM_HOA = diem_hoa;
}

int SinhVien::getID(){
    return this->ID;
}

string SinhVien::getName(){
    return this->NAME;
}

int SinhVien::getTuoi(){
    return this->TUOI;
}

typeGioiTinh SinhVien::getGioiTinh(){
    return this->GIOITINH;
}

double SinhVien::getDiemToan(){
    return this->DIEM_TOAN;
}

double SinhVien::getDiemLy(){
    return this->DIEM_LY;
}

double SinhVien::getDiemHoa(){
    return this->DIEM_HOA;
}

double SinhVien::getDiemTb(){
    return (double)((this->DIEM_TOAN + this->DIEM_LY + this->DIEM_HOA) / 3);
}

//--------------------------FUNCTION------------------------------------

/*
* Function: addAStudent
* Description: This function performs the functionality of adding a student information.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void addAStudent(vector<SinhVien>& databaseSV){
    string name;
    int tuoi;
    int key;
    typeGioiTinh gioitinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    int doNext;
    cout << "Nhap ten: ";
    cin >> name; 
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap gioi tinh: \n1. Nam      2.Nu\n";
    cin >> key;
    switch (key)
    {
    case NAM:
        gioitinh = NAM;
        break;
    case NU:
        gioitinh = NU;
        break;
    default:
        break;
    }
    cout << "Nhap diem toan: ";
    cin >> diemToan;
    cout << "Nhap diem ly: ";
    cin >> diemLy;
    cout << "Nhap diem hoa: ";
    cin >> diemHoa;

    SinhVien sv = {name, tuoi, gioitinh, diemToan, diemLy, diemHoa};
    databaseSV.push_back(sv);
    cout << "---------ADD SUCCESSFULLY---------------\n";
    while (1){
        cout << "1.Tiep tuc them\n0.Quay lai\n";
        cin >> doNext;
        switch (doNext)
        {
        case 1:
            addAStudent(databaseSV);
            return;
            break;
        case 0:
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

/*
* Function: updateInfoStudent
* Description: This function performs the functionality of modifying a student information.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void updateInfoStudent(vector<SinhVien>& databaseSV){
    int id;
    string name;
    int tuoi;
    int key1, key2;
    typeGioiTinh gioitinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    int doNext;
    cout << "Nhap ID: ";
    cin >> id;
    unsigned int i;

    for (i = 0; i < databaseSV.size(); i++){
        if (databaseSV[i].getID() == id){
            break;
        }
    }

    if (i == databaseSV.size()){
        cout << "Khong tim thay ID\n";
    }else{
        cout <<"1.Thay doi ten\n2.Thay doi tuoi\n3.Thay doi gioi tinh\n4.Thay doi diem\n";
        cin >> key1;
        switch (key1)
        {
        case 1:
            cout << "Nhap ten: ";
            cin >> name;
            databaseSV[i].setName(name);
            break;
        case 2:
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            databaseSV[i].setTuoi(tuoi);
            break;
        case 3:
            cout << "Nhap gioi tinh: \n1. Nam      2.Nu\n";
            cin >> key2;
            switch (key2)
            {
            case NAM:
                gioitinh = NAM;
                break;
            case NU:
                gioitinh = NU;
                break;
            default:
                break;
            }
            databaseSV[i].setGioiTinh(gioitinh);
            break;
        case 4:
            cout << "Nhap diem toan: ";
            cin >> diemToan;
            databaseSV[i].setDiemToan(diemToan);
            cout << "Nhap diem ly: ";
            cin >> diemLy;
            databaseSV[i].setDiemLy(diemLy);
            cout << "Nhap diem hoa: ";
            cin >> diemHoa;
            databaseSV[i].setDiemHoa(diemHoa);
            break;
        default:
            break;
        }
        cout << "--------------------UPDATE SUCCESSFUL------------------\n";
    }
    while (1){
        cout << "1.Tiep tuc update\n0.Quay lai\n";
        cin >> doNext;
        switch (doNext)
        {
        case 1:
            updateInfoStudent(databaseSV);
            return;
            break;
        case 0:
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

/*
* Function: eraseAStudent
* Description: This function performs the functionality of deleting a student information.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void eraseAStudent(vector<SinhVien>& databaseSV){
    int id;
    unsigned int i;
    int doNext;
    int key;
    int columnWidth = 20;
    SinhVien temp;
    cout << "Nhap ID: ";
    cin >> id;

    for (i = 0; i < databaseSV.size(); i++){
        if (databaseSV[i].getID() == id){
            break;
        }
    }

    if (i == databaseSV.size()){
        cout << "Khong tim thay ID\n";
    }else{
        cout << "Thong tin sinh vien\n";
        std::cout << std::setw(columnWidth) << std::left << "ID";
        std::cout << std::setw(columnWidth) << std::left << "Ten";
        std::cout << std::setw(columnWidth) << std::left << "Tuoi";
        std::cout << std::setw(columnWidth) << std::left << "Gioi tinh";
        std::cout << std::setw(columnWidth) << std::left << "Diem toan";
        std::cout << std::setw(columnWidth) << std::left << "Diem ly"; 
        std::cout << std::setw(columnWidth) << std::left << "Diem hoa";
        std::cout << std::setw(columnWidth) << std::left << "Diem trung binh";   
        std::cout << std::endl;
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getID();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getName();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getTuoi();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getGioiTinh();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemToan();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemLy(); 
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemHoa();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemTb();    
        std::cout << std::endl;
        cout << "Ban co chac chan muon xoa khong?       1.Yes    2.No\n";
        cin >> key;
        if (key == 1){
            databaseSV.erase(databaseSV.begin() + i);
            cout << "---------ERASE SUCCESSFULLY---------------\n";
        }else{
            cout << "---------NOT ERASE---------------\n";
        }
    }

    while (1){
        cout << "1.Tiep tuc xoa\n0.Quay lai\n";
        cin >> doNext;
        switch (doNext)
        {
        case 1:
            eraseAStudent(databaseSV);
            return;
            break;
        case 0:
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

/*
* Function: eraseAStudent
* Description: This function helps looking up a student information by name.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void lookupAStudent(vector<SinhVien> databaseSV){
    string name;
    unsigned int i;
    int columnWidth = 20;
    int doNext;
    cout << "Nhap ten: ";
    cin >> name;
    for (i = 0; i < databaseSV.size(); i++){
        if (databaseSV[i].getName() == name){
            break;
        }
    }

    if (i == databaseSV.size()){
        cout << "Khong tim thay ID\n";
    }else{
        cout << "Thong tin sinh vien\n";
        std::cout << std::setw(columnWidth) << std::left << "ID";
        std::cout << std::setw(columnWidth) << std::left << "Ten";
        std::cout << std::setw(columnWidth) << std::left << "Tuoi";
        std::cout << std::setw(columnWidth) << std::left << "Gioi tinh";
        std::cout << std::setw(columnWidth) << std::left << "Diem toan";
        std::cout << std::setw(columnWidth) << std::left << "Diem ly"; 
        std::cout << std::setw(columnWidth) << std::left << "Diem hoa";
        std::cout << std::setw(columnWidth) << std::left << "Diem trung binh";   
        std::cout << std::endl;
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getID();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getName();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getTuoi();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getGioiTinh();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemToan();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemLy(); 
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemHoa();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemTb();    
        std::cout << std::endl;
        cout << "---------LOOK UP SUCCESSFULLY---------------\n";
    }

    while (1){
        cout << "1.Tiep tuc tim kiem\n0.Quay lai\n";
        cin >> doNext;
        switch (doNext)
        {
        case 1:
            lookupAStudent(databaseSV);
            return;
            break;
        case 0:
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }

}

/*
* Function: sortDiemTb
* Description: This function helps sorting list student informations by diemtb.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void sortDiemTb(vector<SinhVien>& databaseSV){
    for (unsigned int i = 0; i < databaseSV.size(); i++){
        for (unsigned int j = i + 1; j < databaseSV.size(); j++){
            if (databaseSV[i].getDiemTb() < databaseSV[j].getDiemTb()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }

    cout << "---------SORT BY DIEM TB SUCCESSFULLY---------------\n";
}

/*
* Function: sortName
* Description: This function helps sorting list student informations by name.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void sortName(vector<SinhVien>& databaseSV){
    for (unsigned int i = 0; i < databaseSV.size(); i++){
        for (unsigned int j = i + 1; j < databaseSV.size(); j++){
            if (databaseSV[i].getName() > databaseSV[j].getName()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }

    cout << "---------SORT BY NAME SUCCESSFULLY---------------\n";
}

/*
* Function: printList
* Description: This function shows list student informations.
* Input:
*   databaseSV - a vector sinhvien class
* Output:
*   None
*/
void printList(vector<SinhVien> databaseSV){
    int columnWidth = 20;

    // In tiêu đề các cột
    std::cout << std::setw(columnWidth) << std::left << "ID";
    std::cout << std::setw(columnWidth) << std::left << "Ten";
    std::cout << std::setw(columnWidth) << std::left << "Tuoi";
    std::cout << std::setw(columnWidth) << std::left << "Gioi tinh";
    std::cout << std::setw(columnWidth) << std::left << "Diem toan";
    std::cout << std::setw(columnWidth) << std::left << "Diem ly"; 
    std::cout << std::setw(columnWidth) << std::left << "Diem hoa";
    std::cout << std::setw(columnWidth) << std::left << "Diem trung binh";   
    std::cout << std::endl;

    for (unsigned int i = 0; i < databaseSV.size(); i++){
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getID();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getName();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getTuoi();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getGioiTinh();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemToan();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemLy(); 
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemHoa();
        std::cout << std::setw(columnWidth) << std::left << databaseSV[i].getDiemTb();   
        std::cout << std::endl;
    }
}