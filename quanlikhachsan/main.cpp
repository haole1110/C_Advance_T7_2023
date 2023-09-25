#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;
//---------------------------------ENUM------------------------------------
typedef enum{
    EXIT                    = 0,
    BOOK_ROOM               = 1,
    CUSTOMER_MANAGE         = 2,
    STAFF_MANAGE            = 3,
    PAYMENT                 = 4,
    SECURITY                = 5,
    STATISTIC               = 6,
    EVALUATE                = 7
}typeModeManager;

typedef enum{
    IN,
    OUT
}typeStatus;

//---------------------------------STRUCT------------------------------------
typedef struct{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}typeTime;

typedef struct {
    uint8_t day;
    uint8_t month;
    uint8_t year;
}typeDate;


typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}bookingHistory;

typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}Schedule;

typedef struct{

}JobPosition;

//---------------------------------CLASS------------------------------------
class Room{
    private:
        int roomNumber;
        bool isBooked;
    public:
        Room(int number){
            this->roomNumber = number;
            this->isBooked = false;
        };
        int getRoomNumber(){
            return this->roomNumber;
        }
        bool isBookRoom(){
            return this->isBooked;
        };
        void bookRoom(){
            this->isBooked = true;
        };
        void checkOut(){
            this->isBooked = false;
        };
};


class Customer{
private:
    int idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistorys;
public:
    Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom){
        this->name = customerName;
        this->phoneNumber = customerPhone;
        this->address = customerAddress;
        this->idRoom = customerIdRoom;
    };
};


// class CustomerManager{
//     private:
//         vector<Customer> databaseCustomer;
//     public:
//         //Them khach hang
//         //Sua
//         //Xoa
//         vector<Customer>& getdatabaseCustomer(){return databaseCustomer;}
// };

class Employee{
    private:
        string name;
        string numberPhone;
        JobPosition position;
        Schedule schedule;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee);
};

class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        //Them khach hang
        //Sua
        //Xoa
        vector<Employee>& getdatabaseEmployee(){return databaseEmployee;}
};

//---------------------------------FUNCTION------------------------------------
void bookRoom(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
    int i;
    int columnWidth = 20;
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
                cout << "Hien tai khong co phong, vui long nhan 0 de quay lai thiet lap phong\n";
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
                cout << "1:Nhap so phong\n";
                cout << "0:Quay lai\n\n";
                int key3;
                cin >> key3;
                while (1){
                    cout << "Nhap lua chon: ";
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
                        }else{
                            system("cls");
                            cout << "----------------Tien hanh dat phong---------------------\n\n";
                            cout << "Nhap ten: ";
                            string name;
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhap sdt: ";
                            string sdt;
                            cin.ignore();
                            getline(cin, sdt);
                            cout << "Nhap dia chi: ";
                            string address;
                            cin.ignore();
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


int main(){
    system("cls");
    vector<Room> databaseRoom;
    vector<Customer> databaseCustomer;

    int key = 0;

    while(1){
        cout << "----------------WELCOME---------------------\n";
        cout << "1:Dat phong\n2:Quan li khach hang\n3:Quan li nhan vien\n";
        cout << "4.Thanh toan\n5:Bao mat va quyen truy cap\n6:Bao cao va thong ke\n";
        cout << "7:Quan li va phan hoi danh gia\n0:Thoat\n\n";
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key){
            case BOOK_ROOM:
                bookRoom(databaseRoom, databaseCustomer);
                break;
            case CUSTOMER_MANAGE:
                
                break;
            case STAFF_MANAGE:
                
                break;
            case PAYMENT:
                
                break;
            case SECURITY:
                
                break;
            case STATISTIC:
                
                break;
            case EVALUATE:
                
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