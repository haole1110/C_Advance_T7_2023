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
    string getName(){
        return this->name;
    }
    string getPhoneNumber(){
        return this->phoneNumber;
    }
    string getAddress(){
        return this->address;
    }
    int getIDRoom(){
        return this->idRoom;
    }
    void setName(string name){
        this->name = name;
    }
    void setPhoneNumber(string phoneNumber){
        this->phoneNumber = phoneNumber;
    }
    void setAddress(string address){
        this->address = address;
    }
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

//-----------------------------DECLARE FUNCTION--------------------------------
void manageCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer);

//---------------------------------FUNCTION------------------------------------
void editInfoCustomer(vector<Room>& databaseRoom, vector<Customer> databaseCustomer){
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
            manageCustomer(databaseRoom, databaseCustomer);
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
                manageCustomer(databaseRoom, databaseCustomer);
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
//Main Function---------------------------------------------------------------
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
                cout << "1:Nhap so phong\n";
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

void manageCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
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
            return;
            break;
        case 2:
            deleteInfoCustomer(databaseRoom, databaseCustomer);
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
                manageCustomer(databaseRoom, databaseCustomer);
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