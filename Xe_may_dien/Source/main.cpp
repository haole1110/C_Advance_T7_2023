#include "xemaydien.h"


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
