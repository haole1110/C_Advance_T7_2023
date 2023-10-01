/*
* File: manage_employee_function.cpp
* Author: Le Duy Hao
* Date: 28/09/2023
* Description: This is a file which include functions support the implementation of employee management functions.
*/

#include "manage_employee_function.h"


/*
* Function: updateAEmployee
* Description: This function performs the functionality of modifying employee information.
* Input:
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void updateAEmployee(vector<Employee>& databaseEmployee){
    system("cls");
    int i, columnWidth = 20, id, key, key1;
    bool flag = 0;
    string temp;

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

    cout << "Nhap ID nhan vien can chinh sua: ";
    cin >> id;
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
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua vi tri\n4:Thoi gian bat dau\n5:Thoi gian ket thuc\n0: Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[i].setName(temp);
            flag = 1;
            break;
        case 2:
            system("cls");
            cout << "Nhap sdt: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[i].setNumberPhone(temp);
            flag = 1;
            break;
        case 3:
            system("cls");
            cout << "Chon vi tri:\n";
            cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
            int temp1;
            JobPosition position;
            cin >> temp1;
            switch (temp1)
            {
            case 1:
                position = JANITOR;
                break;
            case 2:
                position = RECEPTIONIST;
                break;
            case 3:
                position = LAUNDRY_STAFF;
                break;
            case 4:
                position = LAUNGGAGE_STAFF;
                break;
            case 5:
                position = GRADENER;
                break;
            default:
                break;
            }
            databaseEmployee[i].setPosition(position);
            flag = 1;
            break;
        case 4:
            system("cls");
            typeTime timeStart;
            cout << "Nhap gio: ";
            cin >> timeStart.hour;
            cout << "Nhap phut: ";
            cin >> timeStart.minute;
            timeStart.second = 0;
            databaseEmployee[i].setTimeStartWorking(timeStart);
            flag = 1;
            break;
        case 5:
            system("cls");
            typeTime timeEnd;
            cout << "Nhap gio: ";
            cin >> timeEnd.hour;
            cout << "Nhap phut: ";
            cin >> timeEnd.minute;
            timeEnd.second = 0;
            databaseEmployee[i].setTimeEndWorking(timeEnd);
            flag = 1;
            break;
        case 0:
            manageEmployeeManagerPermission(databaseEmployee);
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
                manageEmployeeManagerPermission(databaseEmployee);
                return;
            }else{
                return;
            }
        }
    }
}

/*
* Function: deleteAEmployee
* Description: This function performs the functionality of deleting employee information.
* Input:
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void deleteAEmployee(vector<Employee>& databaseEmployee){
    system("cls");
    int id, i;
    int columnWidth = 20;
    int key;
    
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

    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
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

    while (1){
        system("cls");
        cout << "          Ban co chac chan khong?\n";
        cout << "          ________________________\n";
        cout << "          1: Co\n          2: Khong\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            databaseEmployee.erase(databaseEmployee.begin() + i);
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
                    deleteAEmployee(databaseEmployee);
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
            deleteAEmployee(databaseEmployee);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

/*
* Function: addAEmployee
* Description: This function performs the functionality of adding employee information.
* Input:
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void addAEmployee(vector<Employee>& databaseEmployee){
    system("cls");
    cout << "----------------Them nhan vien---------------------\n\n";
    cout << "Nhap ten: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Nhap sdt: ";
    string sdt;
    //cin.ignore();
    getline(cin, sdt);
    cout << "Chon vi tri:\n";
    cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
    int temp;
    JobPosition position;
    cin >> temp;
    switch (temp)
    {
    case 1:
        position = JANITOR;
        break;
    case 2:
        position = RECEPTIONIST;
        break;
    case 3:
        position = LAUNDRY_STAFF;
        break;
    case 4:
        position = LAUNGGAGE_STAFF;
        break;
    case 5:
        position = GRADENER;
        break;
    default:
        break;
    }
    typeTime timeStart;
    cout << "Gio bat dau: ";
    cin >> timeStart.hour;
    cout << "Phut bat dau: ";
    cin >> timeStart.minute;
    timeStart.second = 0;

    typeTime timeEnd;
    cout << "Gio ket thuc: ";
    cin >> timeEnd.hour;
    cout << "Phut ket thuc: ";
    cin >> timeEnd.minute;
    timeEnd.second = 0;

    Employee tempEmployee = {name, sdt, position, timeStart, timeEnd};
    databaseEmployee.push_back(tempEmployee);

    cout << "Them thanh cong!!!\n";
    cout << "Nhap phim bat ky de quay lai: ";
    string temp4;
    cin >> temp4;
    return;
}

/*
* Function: printListEmployee
* Description: This function performs the functionality of printing list employee information.
* Input:
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void printListEmployee(vector<Employee> databaseEmployee){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
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
    cout << "Nhap phim bat ky de quay lai: ";
    string temp;
    cin >> temp;
    return;
}

/*
* Function: manageEmployeeManagerPermission
* Description: This function performs the functionality of managing employee information by manager permission.
* Input:
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void manageEmployeeManagerPermission(vector<Employee>& databaseEmployee){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Quan li nhan vien---------------------\n\n";

    cout << "1:Chinh sua nhan vien\n";
    cout << "2:Xoa nhan vien\n";
    cout << "3:Them nhan vien\n";
    cout << "4:In danh sach nhan vien\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            updateAEmployee(databaseEmployee);
            manageEmployeeManagerPermission(databaseEmployee);
            return;
            break;
        case 2:
            deleteAEmployee(databaseEmployee);
            manageEmployeeManagerPermission(databaseEmployee);
            return;
            break;
        case 3:
            addAEmployee(databaseEmployee);
            manageEmployeeManagerPermission(databaseEmployee);
            return;
            break;
        case 4:
            printListEmployee(databaseEmployee);
            manageEmployeeManagerPermission(databaseEmployee);
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

/*
* Function: manageEmployeeUserPermission
* Description: This function performs the functionality of managing employee information by employee permission.
* Input:
*   databaseEmployee - a vector employee class
*   stt - an integer number
* Output:
*   None
*/
void manageEmployeeUserPermission(vector<Employee>& databaseEmployee, int stt){
    int key, key1;
    string temp;
    bool flag = 0;

    cout << "1:Sua ten\n2:Sua sdt\n3:Thoi gian bat dau\n4:Thoi gian ket thuc\n0: Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[stt].setName(temp);
            flag = 1;
            break;
        case 2:
            system("cls");
            cout << "Nhap sdt: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[stt].setNumberPhone(temp);
            flag = 1;
            break;
        case 3:
            system("cls");
            typeTime timeStart;
            cout << "Nhap gio: ";
            cin >> timeStart.hour;
            cout << "Nhap phut: ";
            cin >> timeStart.minute;
            timeStart.second = 0;
            databaseEmployee[stt].setTimeStartWorking(timeStart);
            flag = 1;
            break;
        case 4:
            system("cls");
            typeTime timeEnd;
            cout << "Nhap gio: ";
            cin >> timeEnd.hour;
            cout << "Nhap phut: ";
            cin >> timeEnd.minute;
            timeEnd.second = 0;
            databaseEmployee[stt].setTimeEndWorking(timeEnd);
            flag = 1;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 0){
                return;
            }
        }
    }

}