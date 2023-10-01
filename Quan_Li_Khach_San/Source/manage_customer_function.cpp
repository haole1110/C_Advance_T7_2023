#include "manage_customer_function.h"

void editInfoCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
    int stt;
    int key, key1;
    bool flag = 0;
    bool continueEdit = 1;
    string temp;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua dia chi\n0: Quay lai\n\n";
    while (continueEdit){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].setName(temp);
            flag = 1;
            break;
        case 2:
            system("cls");
            cout << "Nhap sdt: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].setPhoneNumber(temp);
            flag = 1;
            break;
        case 3:
            system("cls");
            cout << "Nhap dia chi: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].setAddress(temp);
            flag = 1;
            break;
        case 0:
            //manageCustomer(databaseRoom, databaseCustomer);
            return;
            break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "1: Tiep tuc\n0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 1){
                editInfoCustomer(databaseRoom, databaseCustomer);
                return;
            }else{
                //manageCustomer(databaseRoom, databaseCustomer);
                return;
            }
        }
    }

}

void deleteInfoCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){

    system("cls");
    int stt, i;
    int key;
    string key1;
    bool flag = 0;
    bool continueEdit = 1;
    string temp;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    cout << "1:Chan chan xoa\n0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: \n";
        cin >> key;
        switch (key)
        {
        case 1:
            for (i = 0; i < databaseRoom.size(); i++){
                if (databaseRoom[i].getRoomNumber() == databaseCustomer[stt].getIDRoom()) break;
            }
            databaseRoom[i].checkOut();
            databaseCustomer.erase(databaseCustomer.begin() + stt - 1);
            system("cls");
            cout << "Xoa thong tin thanh cong!!!\n";
            cout << "Nhan phim bat ki de quay lai\n";
            cin >> key1;
            return;
            break;
        case 0:
            deleteInfoCustomer(databaseRoom, databaseCustomer);
            return;
            break;
        default:
            break;
        }
    }

    
}