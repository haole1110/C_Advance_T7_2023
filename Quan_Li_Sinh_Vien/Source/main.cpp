#include "quanlisinhvien.h"

//--------------------------MAIN----------------------------------------
int main(){
    //Storage room informations in the hotel
    vector<SinhVien> databaseSV;

    int key = 0;

    while(1){
        cout << "----------------CHUC NANG---------------------\n";
        cout << "1.Them sinh vien\n2.Cap nhat thong tin sinh vien\n3.Xoa sinh vien bang ID\n";
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