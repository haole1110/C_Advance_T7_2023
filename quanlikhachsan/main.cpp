#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;


//---------------------------------ENUM------------------------------------
typedef enum{
    EXIT                    = 0,
    BOOK_ROOM               = 1,
    CUSTOMER_MANAGE         = 2,
    STAFF_MANAGE            = 3,
    SERVICE                 = 4,
    PAYMENT                 = 5,
    SECURITY                = 6,
    STATISTIC               = 7,
    EVALUATE                = 8
}typeModeManager;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUNGGAGE_STAFF,
    GRADENER
}JobPosition;
//---------------------------------STRUCT------------------------------------
typedef struct{
    int second;
    int minute;
    int hour;
}typeTime;

typedef struct {
    int day;
    int month;
    int year;
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
    Customer(){}
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

class Service{
    private:
        bool RESTAURANT;
        bool BAR;
        bool POOL;
        bool GYM;
        bool PARKING;
    public:
        Service(){
            this->RESTAURANT = false;
            this->BAR = false;
            this->POOL = false;
            this->GYM = false;
            this->PARKING = false; 
        }
        bool getStateRestaurant(){
            return this->RESTAURANT;
        }
        bool getStateBar(){
            return this->BAR;
        }
        bool getStatePool(){
            return this->POOL;
        }
        bool getStateGym(){
            return this->GYM;
        }
        bool getStateParking(){
            return this->PARKING;
        }
        void setStateBar(bool bar){
            this->BAR = bar;
        }
        void setStatePool(bool pool){
            this->POOL = pool;
        }
        void setStateGym(bool gym){
            this->GYM = gym;
        }
        void setStateParking(bool parking){
            this->PARKING = parking;
        }
        void setStateRestaurant(bool restaurant){
            this->RESTAURANT = restaurant;
        }
        void printAllStateService(){
            if (this->RESTAURANT){
                cout << "Nha hang: co phuc vu\n";
            }else{
                cout << "Nha hang: khong phuc vu\n";
            }
            if (this->BAR){
                cout << "Quay bar: co phuc vu\n";
            }else{
                cout << "Quay bar: khong phuc vu\n";
            }
            if (this->POOL){
                cout << "Ho boi: co phuc vu\n";
            }else{
                cout << "Ho boi: khong phuc vu\n";
            }
            if (this->GYM){
                cout << "Phong gym: co phuc vu\n";
            }else{
                cout << "Phong gym: khong phuc vu\n";
            }
            if (this->PARKING){
                cout << "Bai do xe: co phuc vu\n";
            }else{
                cout << "Bai do xe: khong phuc vu\n";
            }
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
        int id;
        string name;
        string numberPhone;
        JobPosition position;
        typeTime timeStartWorking;
        typeTime timeEndWorking;
        typeStatus status;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, typeTime timeStartWorking, typeTime timeEndWorking){
            static int id = 100;
            id++;
            this->id = id;
            this->name = nameEmployee;
            this->numberPhone = phoneNumberEmployee;
            this->position = positionEmployee;
            this->timeStartWorking = timeStartWorking;
            this->timeEndWorking = timeEndWorking;
            this->status = OUT;
        }

        int getID(){
            return this->id;
        }
        string getName(){
           return this->name; 
        }
        string getNumberPhone(){
            return this->numberPhone;
        }
        JobPosition getPosition(){
            return this->position;
        }
        typeTime getTimeStartWorking(){
            return this->timeStartWorking;
        }
        typeTime getTimeEndWorking(){
            return this->timeEndWorking;
        }
        void setName(string name){
            this->name = name;
        }
        void setNumberPhone(string numberphone){
            this->numberPhone = numberphone;
        }
        void setPosition(JobPosition position){
            this->position = position;
        }
        void setTimeStartWorking(typeTime timeStartWorking){
            this->timeStartWorking = timeStartWorking;
        }
        void setTimeEndWorking(typeTime timeEndWorking){
            this->timeEndWorking = timeEndWorking;
        }
        void setStatus(typeStatus status){
            this->status = status;
        }
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

class User{   
    private:
        int ID;
        string USERNAME;
        string PASSWORD;
    public:
        User(){
            this->ID = 0;
            this->USERNAME = "";
            this->PASSWORD = "";
        }
        User(int id, string username, string password){
            this->ID = id;
            this->USERNAME = username;
            this->PASSWORD = password;
        }
        int getID(){
            return this->ID;
        }
        string getUserName(){
            return this->USERNAME;
        }
        string getPassword(){
            return this->PASSWORD;
        }
        void setUserName(string username){
            this->USERNAME = username;
        }
        void setPassword(string password){
            this->PASSWORD = password;
        }
        bool authenticate(string inputUserName, string inputPassword){
            bool checkSignUp = (inputUserName == this->USERNAME && inputPassword == this->PASSWORD);
            return checkSignUp;
        }
};

class PayHistory{
    private:
        int PAY;
        Customer CUSTOMER;
    public:
        PayHistory(){}
        int getPay(){
            return this->PAY;
        }
        Customer getCustomer(){
            return this->CUSTOMER;
        }
        void setPay(int pay){
            this->PAY = pay;
        }
        void setCustomer(Customer customer){
            this->CUSTOMER = customer;
        }
};

class SecurityManagement{
    private:
        User USER;
        vector<User> databaseUser;
        bool checkSignUp;
    public:
        SecurityManagement(){
            this->USER.setUserName("manager");
            this->USER.setPassword("admin");
        }
        void addUser(int id, string inputUserName, string inputPassword){
            User user = {id, inputUserName, inputPassword};
            this->databaseUser.push_back(user);
        };
        void eraseUser(string inputUserName){
            for (auto i = databaseUser.begin(); i < databaseUser.end(); i++){
                if(i->getUserName() == inputUserName) databaseUser.erase(i);
            }
        };
        void editUser(string inputUserName, string inputPassword){
            for (int i = 0; i < databaseUser.size(); i++){
                if (databaseUser[i].getUserName() == inputUserName) databaseUser[i].setPassword(inputPassword);
            }
        };
        void setPasswordManager(string inputPassword){
            this->USER.setPassword(inputPassword);
        };
        bool getCheckSignUp(string inputUserName, string inputPassword){
            return this->USER.authenticate(inputUserName, inputPassword);
        };
        vector<User>& getDatabaseUser(){
            return this->databaseUser;
        };
};

class Feedback{
    private:
        string USERNAME;
        string FEEDBACK;
        int RATING;
    public:
        Feedback(){
            this->USERNAME = "";
            this->FEEDBACK = "";
            this->RATING = 0;
        }
        Feedback(string name, string feedback, int rating){
            this->USERNAME = name;
            this->FEEDBACK = feedback;
            this->RATING = rating;
        }
        string getUserName(){
            return this->USERNAME;
        }
        string getFeedback(){
            return this->FEEDBACK;
        }
        int getRating(){
            return this->RATING;
        }
};
//-----------------------------DECLARE FUNCTION--------------------------------
void manageCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer, SecurityManagement securityManagement, vector<Employee> databaseEmployee);
void printListEmployee(vector<Employee> databaseEmployee);
void manageEmployeeManagerPermission(vector<Employee>& databaseEmployee);
void editUserManagerPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);

//---------------------------------FUNCTION------------------------------------
string translatePosition(JobPosition job){
    switch (job)
    {
    case JANITOR:
        /* code */
        return "JANITOR";
        break;
    case RECEPTIONIST:
        /* code */
        return "RECEPTIONIST";
        break;
    case LAUNDRY_STAFF:
        /* code */
        return "LAUNDRY_STAFF";
        break;
    case LAUNGGAGE_STAFF:
        /* code */
        return "LAUNGGAGE_STAFF";
        break;
    case GRADENER:
        /* code */
        return "GRADENER";
        break;
    default:
        break;
    }
    return "";
}
//Manage Customer Function---------------------------------
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

//Manage Employee Function---------------------------------
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
//Manage Security Function---------------------------------
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

//Manage Payment Function -------------------------------------
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

//-----------------------------------------Main Function-----------------------------------
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


//-------------------------------MAIN--------------------------------------------
int main(){
    vector<Room> databaseRoom;
    vector<Customer> databaseCustomer;
    vector<Employee> databaseEmployee;
    SecurityManagement securityManagement;
    Service service;
    vector<Feedback> databaseFeedback;
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