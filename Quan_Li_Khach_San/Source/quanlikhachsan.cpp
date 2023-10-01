#include "quanlikhachsan.h"

Room::Room(int number){
    this->roomNumber = number;
    this->isBooked = false;
};
int Room::getRoomNumber(){
    return this->roomNumber;
}
bool Room::isBookRoom(){
    return this->isBooked;
};
void Room::bookRoom(){
    this->isBooked = true;
};
void Room::checkOut(){
    this->isBooked = false;
};

Customer::Customer(){};
Customer::Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom){
    this->name = customerName;
    this->phoneNumber = customerPhone;
    this->address = customerAddress;
    this->idRoom = customerIdRoom;
};
string Customer::getName(){
    return this->name;
}
string Customer::getPhoneNumber(){
    return this->phoneNumber;
}
string Customer::getAddress(){
    return this->address;
}
int Customer::getIDRoom(){
    return this->idRoom;
}
void Customer::setName(string name){
    this->name = name;
}
void Customer::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}
void Customer::setAddress(string address){
    this->address = address;
}


Service::Service(){
    this->RESTAURANT = false;
    this->BAR = false;
    this->POOL = false;
    this->GYM = false;
    this->PARKING = false; 
}
bool Service::getStateRestaurant(){
    return this->RESTAURANT;
}
bool Service::getStateBar(){
    return this->BAR;
}
bool Service::getStatePool(){
    return this->POOL;
}
bool Service::getStateGym(){
    return this->GYM;
}
bool Service::getStateParking(){
    return this->PARKING;
}
void Service::setStateBar(bool bar){
    this->BAR = bar;
}
void Service::setStatePool(bool pool){
    this->POOL = pool;
}
void Service::setStateGym(bool gym){
    this->GYM = gym;
}
void Service::setStateParking(bool parking){
    this->PARKING = parking;
}
void Service::setStateRestaurant(bool restaurant){
    this->RESTAURANT = restaurant;
}
void Service::printAllStateService(){
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


Employee::Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, typeTime timeStartWorking, typeTime timeEndWorking){
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

int Employee::getID(){
    return this->id;
}
string Employee::getName(){
    return this->name; 
}
string Employee::getNumberPhone(){
    return this->numberPhone;
}
JobPosition Employee::getPosition(){
    return this->position;
}
typeTime Employee::getTimeStartWorking(){
    return this->timeStartWorking;
}
typeTime Employee::getTimeEndWorking(){
    return this->timeEndWorking;
}
void Employee::setName(string name){
    this->name = name;
}
void Employee::setNumberPhone(string numberphone){
    this->numberPhone = numberphone;
}
void Employee::setPosition(JobPosition position){
    this->position = position;
}
void Employee::setTimeStartWorking(typeTime timeStartWorking){
    this->timeStartWorking = timeStartWorking;
}
void Employee::setTimeEndWorking(typeTime timeEndWorking){
    this->timeEndWorking = timeEndWorking;
}
void Employee::setStatus(typeStatus status){
    this->status = status;
}


User::User(){
    this->ID = 0;
    this->USERNAME = "";
    this->PASSWORD = "";
}
User::User(int id, string username, string password){
    this->ID = id;
    this->USERNAME = username;
    this->PASSWORD = password;
}
int User::getID(){
    return this->ID;
}
string User::getUserName(){
    return this->USERNAME;
}
string User::getPassword(){
    return this->PASSWORD;
}
void User::setUserName(string username){
    this->USERNAME = username;
}
void User::setPassword(string password){
    this->PASSWORD = password;
}
bool User::authenticate(string inputUserName, string inputPassword){
    bool checkSignUp = (inputUserName == this->USERNAME && inputPassword == this->PASSWORD);
    return checkSignUp;
}

PayHistory::PayHistory(){}
int PayHistory::getPay(){
    return this->PAY;
}
Customer PayHistory::getCustomer(){
    return this->CUSTOMER;
}
void PayHistory::setPay(int pay){
    this->PAY = pay;
}
void PayHistory::setCustomer(Customer customer){
    this->CUSTOMER = customer;
}

SecurityManagement::SecurityManagement(){
    this->USER.setUserName("manager");
    this->USER.setPassword("admin");
}
void SecurityManagement::addUser(int id, string inputUserName, string inputPassword){
    User user = {id, inputUserName, inputPassword};
    this->databaseUser.push_back(user);
};
void SecurityManagement::eraseUser(string inputUserName){
    for (auto i = databaseUser.begin(); i < databaseUser.end(); i++){
        if(i->getUserName() == inputUserName) databaseUser.erase(i);
    }
};
void SecurityManagement::editUser(string inputUserName, string inputPassword){
    for (int i = 0; i < databaseUser.size(); i++){
        if (databaseUser[i].getUserName() == inputUserName) databaseUser[i].setPassword(inputPassword);
    }
};
void SecurityManagement::setPasswordManager(string inputPassword){
    this->USER.setPassword(inputPassword);
};
bool SecurityManagement::getCheckSignUp(string inputUserName, string inputPassword){
    return this->USER.authenticate(inputUserName, inputPassword);
};
vector<User>& SecurityManagement::getDatabaseUser(){
    return this->databaseUser;
};

Feedback::Feedback(){
    this->USERNAME = "";
    this->FEEDBACK = "";
    this->RATING = 0;
}
Feedback::Feedback(string name, string feedback, int rating){
    this->USERNAME = name;
    this->FEEDBACK = feedback;
    this->RATING = rating;
}
string Feedback::getUserName(){
    return this->USERNAME;
}
string Feedback::getFeedback(){
    return this->FEEDBACK;
}
int Feedback::getRating(){
    return this->RATING;
}

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