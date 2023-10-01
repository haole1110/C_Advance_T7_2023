/*
* File: manage_payment_function.cpp
* Author: Le Duy Hao
* Date: 28/09/2023
* Description: This is a file which include functions support the implementation of payment management functions.
*/


#include "manage_payment_function.h"


/*
* Function: payment
* Description: This function performs the functionality of printing the payment invoice and checking out 
*              a room that has been paid for.
* Input:
*   databaseRoom - a vector room class
*   dataCustomer - a vector customer class
*   databasePayHistory - a vector pay history class
* Output:
*   None
*/
void payment(vector<Room>& databaseRoom, vector<Customer>& dataCustomer, vector<PayHistory>& databasePayHistory){
    system("cls");
    int i, idRoom, columnWidth = 20, key, key1;
    bool flag = 0;
    PayHistory aPayment;
    cout << "----------------Thanh toan---------------------\n\n";
    cout << "Nhap so phong: \n";
    cin >> idRoom;
    for (i = 0; i < dataCustomer.size(); i++){
        if (idRoom == dataCustomer[i].getIDRoom()) {
            flag = 1;
            break;
        }
    }

    if (!flag) return;
    
    cout << setw(columnWidth) << left << dataCustomer[i].getIDRoom();
    cout << setw(columnWidth) << left << dataCustomer[i].getName();
    cout << setw(columnWidth) << left << dataCustomer[i].getPhoneNumber();
    cout << setw(columnWidth) << left << dataCustomer[i].getAddress();
    cout << endl;

    cout << "1:Thanh toan\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            aPayment.setPay(100);
            aPayment.setCustomer(dataCustomer[i]);
            cout << "Ten khach hang: " << dataCustomer[i].getName() << endl;
            cout << "So dien thoai: " << dataCustomer[i].getPhoneNumber() << endl;
            cout << "Dia chi: " << dataCustomer[i].getAddress() << endl << endl << endl;
            cout << "Tong cong: " << aPayment.getPay() << " nghin dong\n\n";
            cout << "Chon phuong thuc thanh toan:\n1:The tin dung\n2:Internet Banking\n0:Quay lai\n";
            cin >> key1;
            if ((key1 == 1) || (key1 == 2)){
                databasePayHistory.push_back(aPayment);
                for (int j = 0; j  < databaseRoom.size(); j++){
                    if (databaseRoom[j].getRoomNumber() == idRoom){
                        databaseRoom[j].checkOut();
                        break;
                    }
                }
                dataCustomer.erase(dataCustomer.begin() + i);
                cout << "THANH TOAN THANH CONG!!!\n";
                while (1){
                    cout << "Nhan 0 de quay lai: ";
                    cin >> key;
                    if (key == 0){return;}
                }
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