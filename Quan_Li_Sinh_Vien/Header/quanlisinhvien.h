#ifndef __QUANLISINHVIEN_H
#define __QUANLISINHVIEN_H

#include<iostream>
#include<vector>
#include<string>
#include <iomanip>

using namespace std;

//---------------------------------ENUM-----------------------------------

//Main funcitons in the system
typedef enum{
    ADD = 1,
    UPDATE = 2,
    ERASE = 3,
    LOOKUP = 4,
    SORTDIEMTB = 5,
    SORTNAME = 6,
    PRINTLIST = 7,
    EXIST = 8
}typeMode;

typedef enum{
    GIOI,
    KHA,
    TB,
    YEU
}typeHocLuc;

typedef enum{
    NAM = 1,
    NU = 2
}typeGioiTinh;

//--------------------------------CLASS--------------------------------

static int id = 0; //Tang trong suot chuong trinh

class SinhVien{
    private:
        int ID;
        string NAME;
        int TUOI;
        typeGioiTinh GIOITINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
    public:
        SinhVien();
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);

        void setName(string name);
        void setTuoi(int tuoi);
        void setGioiTinh(typeGioiTinh gioitinh);
        void setDiemToan(double diem_toan);
        void setDiemLy(double diem_ly);
        void setDiemHoa(double diem_hoa);

        int getID();
        string getName();
        int getTuoi();
        typeGioiTinh getGioiTinh();
        double getDiemToan();
        double getDiemLy();
        double getDiemHoa();
        double getDiemTb();
        typeHocLuc getHocLuc();
};


//--------------------------FUNCTION------------------------------------
void addAStudent(vector<SinhVien>& databaseSV);
void updateInfoStudent(vector<SinhVien>& databaseSV);
void eraseAStudent(vector<SinhVien>& databaseSV);
void lookupAStudent(vector<SinhVien> databaseSV);
void sortDiemTb(vector<SinhVien>& databaseSV);
void sortName(vector<SinhVien>& databaseSV);
void printList(vector<SinhVien> databaseSV);



#endif
