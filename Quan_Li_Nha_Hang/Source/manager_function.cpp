#include "manager_function.h"

void setTable(vector<Table>& databaseTable){
    system("cls");
    int key;

    while (1){
        cout << "MANAGER\n\n";
        cout << "          ________________________\n";
        cout << "          1: Chon so luong ban\n";
        cout << "          0: Quay lai\n\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            int temp;
            cout << "Nhap so luong: ";
            cin >> temp;
            for (int i = 0; i < temp; i++){
                Table tb = {i+1};
                databaseTable.push_back(tb);
            }
            return;
            break;
        case 0:
            return;
            break;
        default:
            system("cls");
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

void addADishToMenu(vector<DishOnMenu>& databaseDishOnMenu){
    system("cls");
    string name;
    int price, key;
    int columnWidth = 20;
    cout << "MANAGER\n\n";
    cout << "          Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "          Nhap gia: ";
    cin >> price;
    
    DishOnMenu dishonmenu = {name, price};
    databaseDishOnMenu.push_back(dishonmenu);
    cout << "MANAGER\n\n";
    cout << "          ____Them mon thanh cong____\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << endl;
    cout << setw(columnWidth) << left << databaseDishOnMenu[databaseDishOnMenu.size() - 1].getId();
    cout << setw(columnWidth) << left << databaseDishOnMenu[databaseDishOnMenu.size() - 1].getName();
    cout << setw(columnWidth) << left << databaseDishOnMenu[databaseDishOnMenu.size() - 1].getPrice();
    cout << endl << endl;

    while (1){
        cout << "          ________________________\n";
        cout << "          1: Tiep tuc them\n";
        cout << "          0: Quay lai\n\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            addADishToMenu(databaseDishOnMenu);
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

}

void updateADish(vector<DishOnMenu>& databaseDishOnMenu){
    system("cls");
    int columnWidth = 20;
    unsigned int i;
    int id, key, price;
    string name;
    cout << "MANAGER\n\n";
    for (unsigned int i = 0; i < databaseDishOnMenu.size(); i++){
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
        cout << endl;
    }

    cout << "Nhap ID mon an can chinh sua: ";
    cin >> id;
    for (i = 0; i < databaseDishOnMenu.size(); i++){
        if (databaseDishOnMenu[i].getId() == id) break;
    }
    if (i == databaseDishOnMenu.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }
    while (1){
        system("cls");
        cout << "MANAGER\n\n";
        cout << "          ________________________\n";
        cout << "          1: Sua ten\n          2: Sua gia\n          0: Quay lai\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, name);
            databaseDishOnMenu[i].setName(name);
            system("cls");
            cout << "MANAGER\n\n";
            cout << "          __________Sua mon thanh cong___________\n";
            cout << setw(columnWidth) << left << "ID";
            cout << setw(columnWidth) << left << "Ten";
            cout << setw(columnWidth) << left << "Gia";
            cout << endl;
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
            cout << endl << endl;
            while (1){
                cout << "          ________________________\n";
                cout << "          1: Tiep tuc sua\n";
                cout << "          0: Quay lai\n\n";
                cout << "          ________________________\n";
                cout << "          Nhap lua chon: ";
                cin >> key;
                switch (key)
                {
                case 1:
                    updateADish(databaseDishOnMenu);
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
            system("cls");
            cout << "Nhap gia: ";
            cin >> price;
            databaseDishOnMenu[i].setPrice(price);
            system("cls");
            cout << "MANAGER\n\n";
            cout << "          __________Sua mon thanh cong___________\n";
            cout << setw(columnWidth) << left << "ID";
            cout << setw(columnWidth) << left << "Ten";
            cout << setw(columnWidth) << left << "Gia";
            cout << endl;
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
            cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
            cout << endl << endl;
            while (1){
                cout << "          ________________________\n";
                cout << "          1: Tiep tuc sua\n";
                cout << "          0: Quay lai\n\n";
                cout << "          ________________________\n";
                cout << "          Nhap lua chon: ";
                cin >> key;
                switch (key)
                {
                case 1:
                    updateADish(databaseDishOnMenu);
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
        case 0:
            updateADish(databaseDishOnMenu);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

void deleteADishOnMenu(vector<DishOnMenu>& databaseDishOnMenu){
    system("cls");
    string name;
    int price;
    unsigned int i;
    int id, idTemp;
    int columnWidth = 20;
    int key;
    cout << "MANAGER\n\n";
    for (unsigned int i = 0; i < databaseDishOnMenu.size(); i++){
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
        cout << endl;
    }

    cout << "Nhap ID mon an can xoa: ";
    cin >> id;
    for (i = 0; i < databaseDishOnMenu.size(); i++){
        if (databaseDishOnMenu[i].getId() == id) break;
    }
    if (i == databaseDishOnMenu.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }
    while (1){
        system("cls");
        cout << "MANAGER\n\n";
        cout << "          Ban co chac chan khong?\n";
        cout << "          ________________________\n";
        cout << "          1: Co\n          2: Khong\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            idTemp = databaseDishOnMenu[i].getId();
            name = databaseDishOnMenu[i].getName();
            price = databaseDishOnMenu[i].getPrice();
            databaseDishOnMenu.erase(databaseDishOnMenu.begin() + i);
            system("cls");
            cout << "MANAGER\n\n";
            cout << "          __________Xoa thanh cong___________\n";
            cout << setw(columnWidth) << left << "ID";
            cout << setw(columnWidth) << left << "Ten";
            cout << setw(columnWidth) << left << "Gia";
            cout << endl;
            cout << setw(columnWidth) << left << id;
            cout << setw(columnWidth) << left << name;
            cout << setw(columnWidth) << left << price;
            cout << endl << endl;
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
                    deleteADishOnMenu(databaseDishOnMenu);
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
            deleteADishOnMenu(databaseDishOnMenu);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }

}

void printListDishOnMenu(vector<DishOnMenu> databaseDishOnMenu){
    system("cls");
    int columnWidth = 20;
    int key;
    cout << "MANAGER\n\n";
    cout << "          ______________MENU______________\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << endl;
    for (unsigned int i = 0; i < databaseDishOnMenu.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
        cout << endl;
    }
    while (1){
        cout << "Quay lai (1/0): ";
        cin >> key;
        if (key == 1) return; 
    }
}

void Manager(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable){
    system("cls");
    while(1){
        cout << "MANAGER\n\n";
        cout << "          ________________________\n";
        cout << "          1: Set so ban\n";
        cout << "          2: Them mon vao menu\n";
        cout << "          3: Sua mon\n";
        cout << "          4: Xoa mon\n";
        cout << "          5: Danh sach mon\n";
        cout << "          0: Quay lai\n\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        
        int key = -1;
        cin >> key;
        switch (key)
        {
        case SETTABLE:
            setTable(databaseTable);
            break;
        case ADD:
            addADishToMenu(databaseDishOnMenu);
            break;
        case UPDATE:
            updateADish(databaseDishOnMenu);
            break;
        case DELETE:
            deleteADishOnMenu(databaseDishOnMenu);
            break;
        case PRINT:
            printListDishOnMenu(databaseDishOnMenu);
            break;
        case RETURN:
            return;
            break;
        
        default:
            break;
        }
    }
}