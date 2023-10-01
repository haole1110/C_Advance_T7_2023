/*
* File: xemaydien.cpp
* Author: Le Duy Hao
* Date: 01/10/2023
* Description: This is a file which implements the methods of the classes and function the program.
*/
#include "xemaydien.h"

mutex mtx;
condition_variable condVar;

//Initial value when starting the bike
string xiNhan = "-------";
string quat = "-------";
string vanToc = "-------";
string nhietDoPin = "-------";
string phanTramPin = "-------";
string inputKeyboard = "";

bool trangThaiXe = 0;
bool stateInput = 0;

int speedBike = 0;

Battery battery(0, 70, 0, 0, 0);


Battery::Battery(int initialCapacity, int maxCap, int minCap, int temp, bool fanStatus) {
    capacity = initialCapacity;
    maxCapacity = maxCap;
    minCapacity = minCap;
    temperature = temp;
    fan = fanStatus;
}

// Getter và Setter cho các thuộc tính
int Battery::getTemperature(){
    return temperature;
}

void Battery::setTemperature(int temp) {
    temperature = temp;
}

int Battery::getCapacity(){
    return capacity;
}

void Battery::setCapacity(int cap) {
    capacity = cap;
}

int Battery::getMaxCapacity(){
    return maxCapacity;
}

void Battery::setMaxCapacity(int maxCap) {
    maxCapacity = maxCap;
}

int Battery::getMinCapacity(){
    return minCapacity;
}

void Battery::setMinCapacity(int minCap) {
    minCapacity = minCap;
}

bool Battery::getFanStatus(){
    return fan;
}

void Battery::setFanStatus(bool speed) {
    fan = speed;
}

int Battery::convertCapacityToPercentage(){
    return int(capacity*100/maxCapacity);
}


//--------------------------------------------FUNCTION---------------------------------
/*
* Function: getInputFromKeyboard
* Description: This function get character input from keyboard and storage in inputKeyboard variable.
* Input:
    None
* Output:
*   None
*/
void getInputFromKeyboard(){
    while (1){
        char ch = _getch();

        if (ch == 0 || ch == -32) {
            ch = _getch();
            switch (ch) {
                case 72: // Mũi tên lên
                    stateInput = 1;
                    inputKeyboard = "Up arrow";
                    break;
                case 80: // Mũi tên xuống
                    stateInput = 1;
                    inputKeyboard = "Down arrow";
                    break;
                case 77: // Mũi tên sang phải
                    stateInput = 1;
                    inputKeyboard = "Right arrow";
                    break;
                case 75: // Mũi tên sang trái
                    stateInput = 1;
                    inputKeyboard =  "Left arrow";
                    break;
                default:
                    inputKeyboard = "Unknow";
                    break;
            }
        }

        if (ch == '0') {
            stateInput = 1; 
            inputKeyboard = "0";
        }
    }
}

/*
* Function: controlStateBike
* Description: This function control state bike.
* Input:
    None
* Output:
*   None
*/
void controlStateBike() {
    // this_thread::sleep_for(chrono::seconds(2)); 
    while (1){
        this_thread::sleep_for(chrono::milliseconds(100)); 
        if (!trangThaiXe){
            lock_guard<mutex> lock(mtx);
        }

        if (trangThaiXe){
            condVar.notify_all();
        }

        if (inputKeyboard == "0" && stateInput == 1){
            stateInput = 0;
            trangThaiXe = !trangThaiXe;
            if (trangThaiXe){
                xiNhan = "Khong";
                quat = "Tat";
                speedBike = 0;
                vanToc = to_string(speedBike);
                phanTramPin = "100";
                nhietDoPin = "30";
            } else {
                xiNhan = "-------";
                quat = "-------";
                vanToc = "-------";
                phanTramPin = "-------";
                nhietDoPin = "-------";

            }
        }
    }
}

/*
* Function: controlStateBike
* Description: This function control turn signal.
* Input:
    None
* Output:
*   None
*/
void controlTurnSignal() {
    while (1){
        this_thread::sleep_for(chrono::milliseconds(100)); 
        unique_lock<mutex> lock(mtx);
        condVar.wait(lock, []{ return trangThaiXe; });

        if (inputKeyboard == "Left arrow" && stateInput == 1) {
            stateInput = 0;
            xiNhan = "Trai";
        }

        if (inputKeyboard == "Right arrow" && stateInput == 1) {
            stateInput = 0;
            xiNhan = "Phai";
        }
    }

}

/*
* Function: controlStateBike
* Description: This function control fan.
* Input:
    None
* Output:
*   None
*/
void controlFan() {
    while (1){
        this_thread::sleep_for(chrono::milliseconds(100)); 
        unique_lock<mutex> lock(mtx);
        condVar.wait(lock, []{ return trangThaiXe; });

        if (battery.getTemperature() > 50){
            quat = "Bat";
        }else {
            quat = "Tat";
        }
    }

}

/*
* Function: controlStateBike
* Description: This function speed bike.
* Input:
    None
* Output:
*   None
*/
void controlSpeedBike() {
    while (1){
        this_thread::sleep_for(chrono::milliseconds(100)); 
        unique_lock<mutex> lock(mtx);
        condVar.wait(lock, []{ return trangThaiXe; });

        if (inputKeyboard == "Up arrow" && stateInput == 1) {
            stateInput = 0;
            speedBike++;
            vanToc = to_string(speedBike);
        }

        if (inputKeyboard == "Down arrow" && stateInput == 1) {
            stateInput = 0;
            speedBike--;
            if (speedBike < 0) speedBike = 0;
            vanToc = to_string(speedBike);
        }
    }

}

/*
* Function: controlStateBike
* Description: This function control battery.
* Input:
    None
* Output:
*   None
*/
void controlBattery() {
    while (1){
        this_thread::sleep_for(chrono::seconds(5)); 
        unique_lock<mutex> lock(mtx);
        condVar.wait(lock, []{ return trangThaiXe; });

        srand(time(NULL));

        battery.setCapacity(rand() % (battery.getMaxCapacity() - battery.getMinCapacity() + 1) + battery.getMinCapacity());
        phanTramPin = to_string(battery.convertCapacityToPercentage());

        battery.setTemperature(rand() % (80 - 20 + 1) + 20);
        nhietDoPin = to_string(battery.getTemperature());
    }

}

/*
* Function: controlStateBike
* Description: This function display screen for user
* Input:
    None
* Output:
*   None
*/
void displayScreen(){
    while (1){
        this_thread::sleep_for(chrono::milliseconds(100)); 
        system("cls");
        cout << "Xi nhan: " << xiNhan << endl;
        cout << "Quat: " << quat << endl;
        cout << "Van toc: " << vanToc << "Km/h" << endl;
        cout << "Phan tram pin: " << phanTramPin << endl;
        cout << "Nhiet do pin: " << nhietDoPin << endl;
        cout << "-------------------------------------------\n";
        cout << "Trang thai xe: " << trangThaiXe << endl;
    }
}