#include "manage_security_function.h"

void addAUser(SecurityManagement& securityManagement, vector<Employee> databaseEmployee){
    system("cls");
    int i, id;
    int columnWidth = 20;
    int key;
    cout << "----------------Quyen quan li---------------------\n\n";
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Vi tri";
    cout << setw(columnWidth) << left << "Thoi gian bat dau";
    cout << setw(columnWidth) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(columnWidth) << left << databaseEmployee[i].getID();
        cout << setw(columnWidth) << left << databaseEmployee[i].getName();
        cout << setw(columnWidth) << left << databaseEmployee[i].getNumberPhone();
        cout << setw(columnWidth) << left << translatePosition(databaseEmployee[i].getPosition());
        cout << databaseEmployee[i].getTimeStartWorking().hour << ":" << databaseEmployee[i].getTimeStartWorking().minute << ":" << setw(columnWidth) << left << databaseEmployee[i].getTimeStartWorking().second;
        cout << databaseEmployee[i].getTimeEndWorking().hour << ":" << databaseEmployee[i].getTimeEndWorking().minute << ":" << databaseEmployee[i].getTimeEndWorking().second;
        cout << endl;
    }
    cout << endl;

    cout << "Nhap ID nhan vien: ";
    cin >> id;

    if (!id) return;

    for (i = 0; i < databaseEmployee.size(); i++){
        if (databaseEmployee[i].getID() == id) break;
    }
    if (i == databaseEmployee.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }

    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    cout << "Nhap mat khau: ";
    string password;
    //cin.ignore();
    getline(cin, password);
    securityManagement.addUser(id, account, password);

    cout << "THEM USER THANH CONG!!!\n";
    while (1){
        cout << "Nhan 0 de quay lai: ";
        cin >> key;
        if (key == 0){return;}
    }

}

void changePasswordAUser(SecurityManagement& securityManagement){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    vector<User>& databaseUser = securityManagement.getDatabaseUser();

    cout << "----------------Danh sach User---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Tai khoan";
    cout << setw(columnWidth) << left << "Mat khau";
    cout << endl;
    for (i = 0; i < databaseUser.size(); i++){
        cout << setw(columnWidth) << left << databaseUser[i].getID();
        cout << setw(columnWidth) << left << databaseUser[i].getUserName();
        cout << setw(columnWidth) << left << databaseUser[i].getPassword();
        cout << endl;
    }
    cout << endl;

    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    cout << "Nhap mat khau moi: ";
    string password;
    //cin.ignore();
    getline(cin, password);
    cout << "Nhap lai mat khau moi: ";
    string re_password;
    //cin.ignore();
    getline(cin, re_password);
    
    if (password == re_password){
        securityManagement.editUser(account, password);
        cout << "DOI MAT KHAU THANH CONG!!!\n";
    }else{
        cout << "MAT KHAU NHAP KHONG TRUNG KHOP!!!\n";
    }
    while (1){
        cout << "Nhan 0 de quay lai: ";
        cin >> key;
        if (key == 0){return;}
    }
}

void deleteAUser(SecurityManagement& securityManagement){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    vector<User>& databaseUser = securityManagement.getDatabaseUser();

    cout << "----------------Danh sach User---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Tai khoan";
    cout << setw(columnWidth) << left << "Mat khau";
    cout << endl;
    for (i = 0; i < databaseUser.size(); i++){
        cout << setw(columnWidth) << left << databaseUser[i].getID();
        cout << setw(columnWidth) << left << databaseUser[i].getUserName();
        cout << setw(columnWidth) << left << databaseUser[i].getPassword();
        cout << endl;
    }
    cout << endl;

    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    
    while (1){
        system("cls");
        cout << "Ban co chac chan khong?\n";
        cout << "________________________\n";
        cout << "1: Co          2: Khong\n";
        cout << "________________________\n";
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            securityManagement.eraseUser(account);
            system("cls");
            cout << "          __________Xoa thanh cong___________\n";
            while (1){
                cout << "          ________________________\n";
                cout << "          1: Tiep tuc xoa\n";
                cout << "          0: Quay lai\n\n";
                cout << "          ________________________\n";
                cout << "          Nhap lua chon: ";
                cin >> key;
                switch (key)
                {
                case 1:
                    deleteAUser(securityManagement);
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
            return;
            break;
        case 2:
            deleteAUser(securityManagement);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
   
    while (1){
        cout << "Nhan 0 de quay lai: ";
        cin >> key;
        if (key == 0){return;}
    }
}

void printListUser(SecurityManagement& securityManagement){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    vector<User> databaseUser = securityManagement.getDatabaseUser();

    cout << "----------------Danh sach User---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Tai khoan";
    cout << setw(columnWidth) << left << "Mat khau";
    cout << endl;
    for (i = 0; i < databaseUser.size(); i++){
        cout << setw(columnWidth) << left << databaseUser[i].getID();
        cout << setw(columnWidth) << left << databaseUser[i].getUserName();
        cout << setw(columnWidth) << left << databaseUser[i].getPassword();
        cout << endl;
    }
    cout << endl;
    cout << "Nhap phim bat ky de quay lai: ";
    string temp;
    cin >> temp;
    return;
}

void editUserManagerPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee){
    continueEditUser:
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Quyen quan li---------------------\n\n";

    cout << "1:Them user\n";
    cout << "2:Doi mat khau\n";
    cout << "3:Xoa user\n";
    cout << "4:In danh sach user\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            addAUser(securityManagement, databaseEmployee);
            editUserManagerPermission(securityManagement, databaseEmployee);
            return;
            break;
        case 2:
            changePasswordAUser(securityManagement);
            editUserManagerPermission(securityManagement, databaseEmployee);
            return;
            break;
        case 3:
            deleteAUser(securityManagement);
            editUserManagerPermission(securityManagement, databaseEmployee);
            return;
            break;
        case 4:
            printListUser(securityManagement);
            editUserManagerPermission(securityManagement, databaseEmployee);
            return;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void changePasswordManager(SecurityManagement& securityManagement){
    system("cls");
    int key;
    cout << "----------------Quyen quan li---------------------\n\n";
    cout << "Nhap mat khau moi: ";
    string password;
    cin.ignore();
    getline(cin, password);
    cout << "Nhap lai mat khau moi: ";
    string re_password;
    //cin.ignore();
    getline(cin, re_password);
    if (password == re_password){
        securityManagement.setPasswordManager(password);
        cout << "THAY DOI MAT KHAU THANH CONG!!!\n";
    }else{
        cout << "MAT KHAU KHONG TRUNG KHOP!!!/n";
    }
    while (1){
        cout << "Nhan 0 de quay lai: ";
        cin >> key;
        if (key == 0){return;}
    }
}

void managerPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee){
    int key;
    system("cls");
    cout << "----------------Quyen quan li---------------------\n\n";
    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    cout << "Nhap mat khau: ";
    string password;
    //cin.ignore();
    getline(cin, password);
    if (securityManagement.getCheckSignUp(account, password)){
        system("cls");
        cout << "----------------Quyen quan li---------------------\n\n";
        cout << "1:Edit User\n";
        cout << "2:Doi mat khau\n";
        cout << "0:Quay lai\n\n";
        while (1){
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key)
            {
            case 1:
                editUserManagerPermission(securityManagement, databaseEmployee);
                return;
                break;
            case 2:
                changePasswordManager(securityManagement);
                return;
                break;
            case 0:
                return;
                break;
            default:
                break;
            }
        }
    }else{
        cout << "SAI TAI KHOAN HOAC MAT KHAU!!!\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }
}

void userPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee){
    int key, key1, i, j, columnWidth = 20;
    bool flag = 0;
    string password_new, re_password_new;
    system("cls");
    cout << "----------------Quyen nhan vien---------------------\n\n";
    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    cout << "Nhap mat khau: ";
    string password;
    //cin.ignore();
    getline(cin, password);

    vector<User>& databaseUser = securityManagement.getDatabaseUser();
    for (i = 0; i < databaseUser.size(); i++){
        if (databaseUser[i].authenticate(account, password)) {
            flag = 1;
            break;
        }
    }
    if (flag){
        for (j = 0; j < databaseEmployee.size(); j++){
            if (databaseEmployee[j].getID() == databaseUser[i].getID()) break;
        }

        cout << setw(columnWidth) << left << databaseEmployee[j].getID();
        cout << setw(columnWidth) << left << databaseEmployee[j].getName();
        cout << setw(columnWidth) << left << databaseEmployee[j].getNumberPhone();
        cout << setw(columnWidth) << left << translatePosition(databaseEmployee[j].getPosition());
        cout << databaseEmployee[i].getTimeStartWorking().hour << ":" << databaseEmployee[j].getTimeStartWorking().minute << ":" << setw(columnWidth) << left << databaseEmployee[i].getTimeStartWorking().second;
        cout << databaseEmployee[i].getTimeEndWorking().hour << ":" << databaseEmployee[j].getTimeEndWorking().minute << ":" << databaseEmployee[i].getTimeEndWorking().second;
        cout << endl;

        cout << "----------------Quyen nhan vien---------------------\n\n";

        cout << "1:Doi mat khau\n";
        cout << "0:Quay lai\n\n";
        while (1){
            cout << "Nhap lua chon: ";
            cin >> key;
            switch (key)
            {
            case 1:
                system("cls");
                cout << "----------------Quyen nhan vien---------------------\n\n";
                cout << "Nhap mat khau moi: ";
                // string password_new;
                cin.ignore();
                getline(cin, password_new);
                cout << "Nhap lai mat khau moi: ";
                // string re_password_new;
                //cin.ignore();
                getline(cin, re_password_new);
                if (password_new == re_password_new){
                    databaseUser[i].setPassword(password_new);
                    cout << "THAY DOI MAT KHAU THANH CONG!!!\n";
                }else{
                    cout << "MAT KHAU KHONG TRUNG KHOP!!!/n";
                }
                while (1){
                    cout << "Nhan 0 de quay lai: ";
                    cin >> key1;
                    if (key1 == 0){return;}
                }
                return;
                break;
            case 0:
                return;
                break;
            default:
                break;
            }
        }
    }else{
        cout << "Tai khoan User nay khong ton tai\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key1;
            if (key1 == 0){return;}
        }
    }



}