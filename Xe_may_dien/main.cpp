#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

std::mutex mtx;
std::condition_variable condVar;

class Battery {
private:
    int temperature;     // Nhiệt độ pin
    int capacity;        // Dung lượng pin
    int maxCapacity;     // Dung lượng pin tối đa
    int minCapacity;     // Dung lượng pin tối thiểu
    bool fan;           // Quạt

public:
    // Constructor
    Battery(int initialCapacity, int maxCap, int minCap, int temp, bool fanStatus) {
        capacity = initialCapacity;
        maxCapacity = maxCap;
        minCapacity = minCap;
        temperature = temp;
        fan = fanStatus;
    }

    // Getter và Setter cho các thuộc tính
    int getTemperature() const {
        return temperature;
    }

    void setTemperature(int temp) {
        temperature = temp;
    }

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int cap) {
        capacity = cap;
    }

    int getMaxCapacity() const {
        return maxCapacity;
    }

    void setMaxCapacity(int maxCap) {
        maxCapacity = maxCap;
    }

    int getMinCapacity() const {
        return minCapacity;
    }

    void setMinCapacity(int minCap) {
        minCapacity = minCap;
    }

    bool getFanStatus() const {
        return fan;
    }

    void setFanStatus(bool speed) {
        fan = speed;
    }

    int convertCapacityToPercentage(){
        return int(capacity*100/maxCapacity);
    }
};


Battery battery(0, 70, 0, 0, 0);

string xiNhan = "-------";
string quat = "-------";
string vanToc = "-------";
string nhietDoPin = "-------";
string phanTramPin = "-------";
string inputKeyboard = "";

bool trangThaiXe = 0;
bool stateInput = 0;

int speedBike = 0;



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

int main() {
    thread t1(getInputFromKeyboard);
    thread t2(controlStateBike);
    thread t3(controlTurnSignal);
    thread t4(controlFan);
    thread t5(controlSpeedBike);
    thread t6(controlBattery);
    thread t7(displayScreen);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();


    return 0;
}