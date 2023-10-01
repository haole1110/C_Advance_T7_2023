#ifndef __QUANLIKHACHSAN_H
#define __QUANLIKHACHSAN_H

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
        Room(int number);
        int getRoomNumber();
        bool isBookRoom();
        void bookRoom();
        void checkOut();
};


class Customer{
private:
    int idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistorys;
public:
    Customer();
    Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom);
    string getName();
    string getPhoneNumber();
    string getAddress();
    int getIDRoom();
    void setName(string name);
    void setPhoneNumber(string phoneNumber);
    void setAddress(string address);
};

class Service{
    private:
        bool RESTAURANT;
        bool BAR;
        bool POOL;
        bool GYM;
        bool PARKING;
    public:
        Service();
        bool getStateRestaurant();
        bool getStateBar();
        bool getStatePool();
        bool getStateGym();
        bool getStateParking();
        void setStateBar(bool bar);
        void setStatePool(bool pool);
        void setStateGym(bool gym);
        void setStateParking(bool parking);
        void setStateRestaurant(bool restaurant);
        void printAllStateService();
};

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
        Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, typeTime timeStartWorking, typeTime timeEndWorking);

        int getID();
        string getName();
        string getNumberPhone();
        JobPosition getPosition();
        typeTime getTimeStartWorking();
        typeTime getTimeEndWorking();
        void setName(string name);
        void setNumberPhone(string numberphone);
        void setPosition(JobPosition position);
        void setTimeStartWorking(typeTime timeStartWorking);
        void setTimeEndWorking(typeTime timeEndWorking);
        void setStatus(typeStatus status);
};

class User{   
    private:
        int ID;
        string USERNAME;
        string PASSWORD;
    public:
        User();
        User(int id, string username, string password);
        int getID();
        string getUserName();
        string getPassword();
        void setUserName(string username);
        void setPassword(string password);
        bool authenticate(string inputUserName, string inputPassword);
};

class PayHistory{
    private:
        int PAY;
        Customer CUSTOMER;
    public:
        PayHistory();
        int getPay();
        Customer getCustomer();
        void setPay(int pay);
        void setCustomer(Customer customer);
};

class SecurityManagement{
    private:
        User USER;
        vector<User> databaseUser;
        bool checkSignUp;
    public:
        SecurityManagement();
        void addUser(int id, string inputUserName, string inputPassword);
        void eraseUser(string inputUserName);
        void editUser(string inputUserName, string inputPassword);
        void setPasswordManager(string inputPassword);
        bool getCheckSignUp(string inputUserName, string inputPassword);
        vector<User>& getDatabaseUser();
};

class Feedback{
    private:
        string USERNAME;
        string FEEDBACK;
        int RATING;
    public:
        Feedback();
        Feedback(string name, string feedback, int rating);
        string getUserName();
        string getFeedback();
        int getRating();
};

//-----------------------------------FUNCTION------------------------------------
string translatePosition(JobPosition job);



#endif
