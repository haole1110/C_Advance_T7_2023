/*
* File: main_function.cpp
* Author: Le Duy Hao
* Date: 28/09/2023
* Description: This is a file which include main functions in the system, include: bookRoom,
*              manageCustomer, manageEmployee, manageService, managePayment, statisticHotel,
*              securityManage, manageFeedback.
*/


#include "main_function.h"


/*
* Function: bookRoom
* Description: This function performs the room reservation functionality in the system, 
*              which includes two functions: setting the number of rooms and proceeding with the reservation.
* Input:
*   databaseRoom - a vector room class
*   databaseCustomer - a vector customer class
* Output:
*   None
*/
void bookRoom(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
    int i;
    int columnWidth = 20;
    string out_prog;
    while (1){
        int key = -1;
        cout << "----------------Dat phong---------------------\n\n";
        cout << "1:Thiet lap so phong\n";
        cout << "2:Tien hanh dat phong\n";
        cout << "0:Quay lai\n\n";
        cout << "Nhap lua chon: ";

        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap so phong: ";
            int numberRoomTemp;
            cin >> numberRoomTemp;
            {
                Room roomTemp = {numberRoomTemp};
                databaseRoom.push_back(roomTemp);
            }
            cout << "Thiet lap so phong thanh cong!!!\n";
            while (1){
                cout << "Nhan so bat ky de quay lai: ";
                int key1;
                cin >> key1;
                break;
            }
            break;
        case 2:
            system("cls");
            cout << "----------------Tien hanh dat phong---------------------\n\n";
            if (databaseRoom.size() == 0){
                cout << "Hien tai khong co phong\n";
                while (1){
                    cout << "Nhan so bat ky de quay lai: ";
                    int key1;
                    cin >> key1;
                    break;
                }
            }else{
                cout << setw(columnWidth) << left << "So phong";
                cout << setw(columnWidth) << left << "Trang thai";
                cout << endl;
                for (i = 0; i < databaseRoom.size(); i++){
                    cout << setw(columnWidth) << left << databaseRoom[i].getRoomNumber();
                    cout << setw(columnWidth) << left << databaseRoom[i].isBookRoom();
                    cout << endl;
                }

                cout << endl;
                cout << "1:Dat phong\n";
                cout << "0:Quay lai\n\n";
                int key3;
                while (1){
                    cout << "Nhap lua chon: ";
                    cin >> key3;
                    switch (key3)
                    {
                    case 1:
                        system("cls");
                        cout << "Nhap so phong: ";
                        int numberRoomTemp;
                        cin >> numberRoomTemp;
                        for (i = 0; i , databaseRoom.size(); i++){
                            if (numberRoomTemp == databaseRoom[i].getRoomNumber()){break;}
                        }
                        if (databaseRoom[i].isBookRoom()){
                            system("cls");
                            cout << "Phong nay da duoc dat!!!\n";
                            cout << "Nhan phim bat ky de quay lai: ";
                            cin >> out_prog;

                        }else{
                            system("cls");
                            cout << "----------------Tien hanh dat phong---------------------\n\n";
                            cout << "Nhap ten: ";
                            string name;
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhap sdt: ";
                            string sdt;
                            //cin.ignore();
                            getline(cin, sdt);
                            cout << "Nhap dia chi: ";
                            string address;
                            //cin.ignore();
                            getline(cin, address);
                            Customer customerTemp(name, sdt, address, numberRoomTemp);
                            databaseCustomer.push_back(customerTemp);
                            databaseRoom[i].bookRoom();
                            system("cls");
                            cout << "----------------Dat phong thanh cong---------------------\n\n";
                            cout << "1:Tiep tuc dat phong\n";
                            cout << "0:Quay lai\n\n";
                            while (1)
                            {
                                cout << "Nhap lua chon: ";
                                int key4;
                                cin >> key4;
                                switch (key4)
                                {
                                case 1:
                                    bookRoom(databaseRoom, databaseCustomer);
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
                        break;
                    case 0:
                        return;
                        break;
                    default:
                        break;
                    }
                }
            }
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
* Function: manageCustomer
* Description: This function verifies the user's access rights to the customer management feature (management 
*              and reception). If the access is granted successfully, it allows the user to perform functions 
*              such as editing and deleting customer information. 
* Input:
*   databaseRoom - a vector room class
*   databaseCustomer - a vector customer class
*   securityManagement  - a object of SecurityManagement class
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void manageCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer, SecurityManagement securityManagement, vector<Employee> databaseEmployee){
    system("cls");
    int key1;
    bool flag = 0;
    //Dang nhap tai khoan quan li hoac nhan vien le tan
    cout << "----------------Quan li khach hang---------------------\n\n";
    cout << "Nhap tai khoan: ";
    string account;
    cin.ignore();
    getline(cin, account);
    cout << "Nhap mat khau: ";
    string password;
    //cin.ignore();
    getline(cin, password);
    vector<User> databaseUser = securityManagement.getDatabaseUser();
    if (securityManagement.getCheckSignUp(account, password)) flag = 1;
    for (int i = 0; i < databaseUser.size(); i++){
        if (databaseUser[i].authenticate(account, password)){
            for (int j = 0; j < databaseEmployee.size(); j++){
                if (databaseUser[i].getID() == databaseEmployee[j].getID()){
                    if (databaseEmployee[j].getPosition() == RECEPTIONIST) flag = 1;
                    break;
                }
            }
            break;
        }
    }

    if (!flag) {
        cout << "KHONG CHO PHEP TRUY CAP VAO CHUC NANG NAY!!!/n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key1;
            if (key1 == 0){return;}
        }
    }

    //Thuc hien cac chuc nang trong quan li khach hang
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Quan li khach hang---------------------\n\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID Phong";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Dia chi";
    cout << endl;
    for (i = 0; i < databaseCustomer.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << databaseCustomer[i].getIDRoom();
        cout << setw(columnWidth) << left << databaseCustomer[i].getName();
        cout << setw(columnWidth) << left << databaseCustomer[i].getPhoneNumber();
        cout << setw(columnWidth) << left << databaseCustomer[i].getAddress();
        cout << endl;
    }

    cout << endl;
    cout << "1:Chinh sua thong tin\n";
    cout << "2:Xoa thong tin\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            editInfoCustomer(databaseRoom, databaseCustomer);
            manageCustomer(databaseRoom, databaseCustomer, securityManagement, databaseEmployee);
            return;
            break;
        case 2:
            deleteInfoCustomer(databaseRoom, databaseCustomer);
            manageCustomer(databaseRoom, databaseCustomer, securityManagement, databaseEmployee);
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
* Function: manageEmployee
* Description: This function verifies the user's access rights to the employee management feature, 
*              allowing login with either managerial or staff privileges, each having different functionalities. 
* Input:
*   securityManagement  - a object of SecurityManagement class
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void manageEmployee(SecurityManagement& securityManagement, vector<Employee>& databaseEmployee){
    system("cls");
    int i, j;
    int columnWidth = 20;
    int key, key1;
    string account, password;
    vector<User>& databaseUser = securityManagement.getDatabaseUser();
    bool flag = 0;

    cout << "----------------Quan li nhan vien---------------------\n\n";

    cout << "1:Quyen quan li\n";
    cout << "2:Quyen nhan vien\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            int key;
            system("cls");
            cout << "----------------Quyen quan li---------------------\n\n";
            cout << "Nhap tai khoan: ";
            cin.ignore();
            getline(cin, account);
            cout << "Nhap mat khau: ";
            //cin.ignore();
            getline(cin, password);
            if (securityManagement.getCheckSignUp(account, password)){
                manageEmployeeManagerPermission(databaseEmployee);
            }else{
                cout << "SAI TAI KHOAN HOAC MAT KHAU!!!\n";
                while (1){
                    cout << "Nhan 0 de quay lai: ";
                    cin >> key1;
                    if (key1 == 0){return;}
                }
            }
            manageEmployee(securityManagement, databaseEmployee);
            return;
            break;
        case 2:
            system("cls");
            cout << "----------------Quyen nhan vien---------------------\n\n";
            cout << "Nhap tai khoan: ";
            cin.ignore();
            getline(cin, account);
            cout << "Nhap mat khau: ";
            //cin.ignore();
            getline(cin, password);

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

                cout << "----------------Quyen nhan vien---------------------\n\n";
                cout << setw(columnWidth) << left << databaseEmployee[j].getID();
                cout << setw(columnWidth) << left << databaseEmployee[j].getName();
                cout << setw(columnWidth) << left << databaseEmployee[j].getNumberPhone();
                cout << setw(columnWidth) << left << translatePosition(databaseEmployee[j].getPosition());
                cout << databaseEmployee[i].getTimeStartWorking().hour << ":" << databaseEmployee[j].getTimeStartWorking().minute << ":" << setw(columnWidth) << left << databaseEmployee[i].getTimeStartWorking().second;
                cout << databaseEmployee[i].getTimeEndWorking().hour << ":" << databaseEmployee[j].getTimeEndWorking().minute << ":" << databaseEmployee[i].getTimeEndWorking().second;
                cout << endl;
                cout << endl;
                manageEmployeeUserPermission(databaseEmployee, j);
            }else{
                cout << "Tai khoan User nay khong ton tai\n";
                while (1){
                    cout << "Nhan 0 de quay lai: ";
                    cin >> key1;
                    if (key1 == 0){return;}
                }
            }
            manageEmployee(securityManagement, databaseEmployee);
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
* Function: manageService
* Description: This function performs the management of service in the hotel. 
* Input:
*   service  - a object of Service class
* Output:
*   None
*/
void manageService(Service& service){
    system("cls");
    int i, key1;
    int columnWidth = 20;
    int key;
    bool temp;
    cout << "----------------Dich vu---------------------\n\n";

    cout << "1:Dat trang thai cac dich vu trong khach san\n";
    cout << "2:In trang thai cac dich vu trong khach san\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nha hang: ";
            cin >> temp;
            service.setStateRestaurant(temp);
            cout << "Quay bar: ";
            cin >> temp;
            service.setStateBar(temp);
            cout << "Ho boi: ";
            cin >> temp;
            service.setStatePool(temp);
            cout << "Phong gym: ";
            cin >> temp;
            service.setStateGym(temp);
            cout << "Bai do xe: ";
            cin >> temp;
            service.setStateParking(temp);
            cout << "DAT TRANG THAI DICH VU THANH CONG!!!\n";
            while (1){
                cout << "Nhan 0 de quay lai: ";
                cin >> key1;
                if (key1 == 0){return;}
            }
            return;
            break;
        case 2:
            system("cls");
            service.printAllStateService();
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
}

/*
* Function: managePayment
* Description: This function performs the management of payment in the hotel, include: payment and history payment. 
* Input:
*   databaseRoom - a vector room class
*   databaseCustomer - a vector customer class
*   databasePayHistory - a vector pay history class
* Output:
*   None
*/
void managePayment(vector<Room>& databaseRoom, vector<Customer>& dataCustomer, vector<PayHistory>& databasePayHistory){
    system("cls");
    int i, key1, idRoom;
    int columnWidth = 20;
    int key;
    bool temp;
    cout << "----------------Thanh toan---------------------\n\n";

    cout << "1:Thanh toan\n";
    cout << "2:Lich su thanh toan\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            payment(databaseRoom, dataCustomer, databasePayHistory);
            managePayment(databaseRoom, dataCustomer, databasePayHistory);
            return;
            break;
        case 2:
            system("cls");
            cout << "Danh sach thanh toan:\n";
            for (auto payment : databasePayHistory) {
                cout << "Nguoi dung: " << payment.getCustomer().getName() << endl;
                cout << "So dien thoai: " << payment.getCustomer().getPhoneNumber() << endl;
                cout << "Dia chi: " << payment.getCustomer().getAddress() << endl;
                cout << "So phong: " << payment.getCustomer().getIDRoom() << endl;
                cout << "Tong tien: " << payment.getPay() << endl;
                cout << "------------------------------------\n";
            }
            while (1){
                cout << "Nhan 0 de quay lai: ";
                cin >> key;
                if (key == 0){return;}
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
}

/*
* Function: statisticHotel
* Description: This function statistic data in hotel. 
* Input:
*   databaseRoom - a vector room class
*   databasePayHistory - a vector pay history class
* Output:
*   None
*/
void statisticHotel(vector<Room> databaseRoom, vector<PayHistory> databasePayHistory){
    system("cls");
    int sumPayment = 0, numberOfRoomIsBooked = 0, numberOfBooking = 0, key;
    vector<Room> tempDatabaseRoom = databaseRoom;

    for (int i = 0; i < databaseRoom.size(); i++){
        if (databaseRoom[i].isBookRoom()) numberOfBooking++;
    }
    for (int i = 0; i < databasePayHistory.size(); i++){
        sumPayment += databasePayHistory[i].getPay();
        for (int j = 0; j < tempDatabaseRoom.size(); j++){
            if (tempDatabaseRoom[j].getRoomNumber() == databasePayHistory[i].getCustomer().getIDRoom()){
                tempDatabaseRoom[j].bookRoom();
                break;
            }
        }
    }

    for (int i = 0; i < tempDatabaseRoom.size(); i++){
        if (tempDatabaseRoom[i].isBookRoom()) numberOfRoomIsBooked++;
    }

     cout << "----------------Thong ke---------------------\n\n";
    cout << "Doanh thu: " << sumPayment << endl;
    cout << "Ty le lap day: " << numberOfRoomIsBooked << '/' << tempDatabaseRoom.size() << endl;
    cout << "So luong dat phong: " << numberOfBooking + databasePayHistory.size() << endl;
    while (1){
        cout << "Nhan 0 de quay lai: ";
        cin >> key;
        if (key == 0){return;}
    }
}

/*
* Function: securityManage
* Description: This function handles the security and access control management in the hotel.
* Input:
*   securityManagement - a object security management class
*   databaseEmployee - a vector employee class
* Output:
*   None
*/
void securityManage(SecurityManagement& securityManagement, vector<Employee> databaseEmployee){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Bao mat va quyen truy cap---------------------\n\n";

    cout << "1:Quyen quan li\n";
    cout << "2:Quyen nhan vien\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            managerPermission(securityManagement, databaseEmployee);
            securityManage(securityManagement, databaseEmployee);
            return;
            break;
        case 2:
            userPermission(securityManagement, databaseEmployee);
            securityManage(securityManagement, databaseEmployee);
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
* Function: manageFeedback
* Description: This function manages feedback of hotel.
* Input:
*   databaseFeedback - a vector feedback class
* Output:
*   None
*/
void manageFeedback(vector<Feedback>& databaseFeedback){
    int key, key1;
    system("cls");
    cout << "1. Them phan hoi\n";
    cout << "2. Hien thi danh sach phan hoi\n";
    cout << "3. Quay lai\n";
    cout << "Chon thao tac: ";
    cin >> key;

    switch (key) {
        case 1: {
            system("cls");
            string username, feedback;
            int rating;

            cout << "Nhap ho va ten: ";
            cin.ignore();
            getline(cin, username);

            cout << "Nhap phan hoi: ";
            getline(cin, feedback);

            cout << "Nhap danh gia (tu 1-5): ";
            cin >> rating;

            Feedback newFeedback(username, feedback, rating);
            databaseFeedback.push_back(newFeedback);

            cout << "PHAN HOI DA DUOC LUU THANH CONG!!!\n";
            while (1){
                cout << "Nhan 0 de quay lai: ";
                cin >> key1;
                if (key1 == 0){return;}
            }
            break;
        }
        case 2:
            system("cls");
            if (databaseFeedback.empty()) {
                cout << "DANH SACH PHAN HOI TRONG\n";
            } else {
                cout << "Danh sach phan hoi:\n";
                for (auto feedback : databaseFeedback) {
                    cout << "Nguoi dung: " << feedback.getUserName() <<endl;
                    cout << "Phan hoi: " << feedback.getFeedback() << endl;
                    cout << "Danh gia: " << feedback.getRating() << endl;
                    cout << "------------------------------------\n";
                }
            }
            while (1){
                cout << "Nhan 0 de quay lai: ";
                cin >> key1;
                if (key1 == 0){return;}
            }
            break;
        case 0: {
            break;
        }
        default: {
            cout << "Vui long nhap lai\n";
            break;
        }
    }
}