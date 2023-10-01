#include<iostream>
#include<vector>
#include<string>
#include <iomanip>

using namespace std;

//---------------------------------ENUM-----------------------------------

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

SinhVien::SinhVien(){
    static int id = 0;
    this->ID = 0;

    this->NAME = "";
    this->TUOI = 0;
    this->GIOITINH = NAM;
    this->DIEM_TOAN = 0;
    this->DIEM_LY = 0;
    this->DIEM_HOA = 0;
}

SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa){
    static int id = 1000;
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
    this->DIEM_TOAN = diem_ly;
}

void SinhVien::setDiemHoa(double diem_hoa){
    this->DIEM_TOAN = diem_hoa;
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

// typeHocLuc SinhVien::getHocLuc(){

// }

//--------------------------FUNCTION------------------------------------

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
    int i;

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
            databaseSV[i].setTuoi(diemHoa);
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

void eraseAStudent(vector<SinhVien>& databaseSV){
    int id;
    int i;
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

void lookupAStudent(vector<SinhVien> databaseSV){
    string name;
    int i;
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

void sortDiemTb(vector<SinhVien>& databaseSV){
    for (int i = 0; i < databaseSV.size(); i++){
        for (int j = i + 1; j < databaseSV.size(); j++){
            if (databaseSV[i].getDiemTb() < databaseSV[j].getDiemTb()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }

    cout << "---------SORT BY DIEM TB SUCCESSFULLY---------------\n";
}

void sortName(vector<SinhVien>& databaseSV){
    for (int i = 0; i < databaseSV.size(); i++){
        for (int j = i + 1; j < databaseSV.size(); j++){
            if (databaseSV[i].getName() > databaseSV[j].getName()){
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }

    cout << "---------SORT BY NAME SUCCESSFULLY---------------\n";
}

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

    for (int i = 0; i < databaseSV.size(); i++){
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

//--------------------------MAIN----------------------------------------
int main(){
    vector<SinhVien> databaseSV;

    int key = 0;

    while(1){
        cout << "----------------CHUC NANG---------------------\n";
        cout << "1. Them sinh vien\n2.Cap nhat thong tin sinh vien\n3.Xoa sinh vien bang ID\n";
        cout << "4.Tim kiem sinh vien bang ten\n5.Sap xep sinh vien theo diem trung binh\n6.Sap xep sinh vien theo ten\n";
        cout << "7.Hien thi danh sach sinh vien\n8.Thoat chuong trinh\n";
        cin >> key;
        switch (key){
            case ADD:
                addAStudent(databaseSV);
                break;
            case UPDATE:
                updateInfoStudent(databaseSV);
                break;
            case ERASE:
                eraseAStudent(databaseSV);
                break;
            case LOOKUP:
                lookupAStudent(databaseSV);
                break;
            case SORTDIEMTB:
                sortDiemTb(databaseSV);
                break;
            case SORTNAME:
                sortName(databaseSV);
                break;
            case PRINTLIST:
                printList(databaseSV);
                break;
            case EXIST:
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}