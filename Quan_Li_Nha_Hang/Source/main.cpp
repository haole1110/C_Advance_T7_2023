#include "quanlinhahang.h"
#include "manager_function.h"
#include "staff_function.h"


int main(){
    system("cls");
    //Storage dish on menu informations in the hotel
    vector<DishOnMenu> databaseMenu;
    //Storage table informations in the hotel
    vector<Table> databaseTable;

    do{
        int key;
        cout << "________________________\n";
        cout << "1: Manager\n2: Staff\n\n";
        cout << "________________________\n";
        cout << "Nhap lua chon: ";
        cin >> key;

        if (key == 1) Manager(databaseMenu, databaseTable);
        else if (key == 2) Staff(databaseMenu, databaseTable);
        else cout << "Warning!!. Nhap lai: ";
    }while (1);

    return 0;

}
