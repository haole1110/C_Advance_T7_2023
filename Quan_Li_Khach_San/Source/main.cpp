#include "main_function.h"

int main(){
    //Storage room informations in the hotel
    vector<Room> databaseRoom;
    //Storage customer informations in the hotel
    vector<Customer> databaseCustomer;
    //Storage employee informations in the hotel
    vector<Employee> databaseEmployee;
    //Storage security informations in the hotel
    SecurityManagement securityManagement;
    //Storage service informations in the hotel
    Service service;
    //Storage feedback informations in the hotel
    vector<Feedback> databaseFeedback;
    //Storage pay history informations in the hotel
    vector<PayHistory> databasePayHistory;
    int key = 0;


    while(1){
        system("cls");
        cout << "----------------WELCOME---------------------\n";
        cout << "1:Dat phong\n2:Quan li khach hang\n3:Quan li nhan vien\n4:Dich vu va tien ich\n";
        cout << "5.Thanh toan\n6:Bao mat va quyen truy cap\n7:Bao cao va thong ke\n";
        cout << "8:Quan li va phan hoi danh gia\n0:Thoat\n\n";
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key){
            case BOOK_ROOM:
                bookRoom(databaseRoom, databaseCustomer);
                break;
            case CUSTOMER_MANAGE:
                manageCustomer(databaseRoom, databaseCustomer, securityManagement, databaseEmployee);
                break;
            case STAFF_MANAGE:
                manageEmployee(securityManagement, databaseEmployee);
                break;
            case SERVICE:
                manageService(service);
                break;
            case PAYMENT:
                managePayment(databaseRoom, databaseCustomer, databasePayHistory);
                break;
            case SECURITY:
                securityManage(securityManagement, databaseEmployee);
                break;
            case STATISTIC:
                statisticHotel(databaseRoom, databasePayHistory);
                break;
            case EVALUATE:
                manageFeedback(databaseFeedback);
                break;
            case EXIT:
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}
