#ifndef __XEMAYDIEN_H
#define __XEMAYDIEN_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

extern mutex mtx;
extern condition_variable condVar;


extern string xiNhan;
extern string quat;
extern string vanToc;
extern string nhietDoPin;
extern string phanTramPin;
extern string inputKeyboard;

extern bool trangThaiXe;
extern bool stateInput;

extern int speedBike;

class Battery {
private:
    int temperature;     // Nhiệt độ pin
    int capacity;        // Dung lượng pin
    int maxCapacity;     // Dung lượng pin tối đa
    int minCapacity;     // Dung lượng pin tối thiểu
    bool fan;           // Quạt

public:
    // Constructor
    Battery(){};
    Battery(int initialCapacity, int maxCap, int minCap, int temp, bool fanStatus);

    // Getter và Setter cho các thuộc tính
    int getTemperature();
    void setTemperature(int temp);
    int getCapacity();
    void setCapacity(int cap);
    int getMaxCapacity();
    void setMaxCapacity(int maxCap);
    int getMinCapacity();
    void setMinCapacity(int minCap);
    bool getFanStatus();
    void setFanStatus(bool speed);
    int convertCapacityToPercentage();
};

extern Battery battery;


//-------------------------------FUNCTION-----------------------------------------------
void getInputFromKeyboard();
void controlStateBike();
void controlTurnSignal();
void controlFan();
void controlSpeedBike();
void controlBattery();
void displayScreen();



#endif
