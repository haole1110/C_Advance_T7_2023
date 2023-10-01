#include "staff_function.h"

void addADishToTable(vector<DishOnMenu> databaseDishOnMenu,vector<Table>& dataTable, int count){
    system("cls");
    string name;
    int price;
    unsigned int i;
    int id, idTemp, quantity;
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n"; 
    for (unsigned int i = 0; i < databaseDishOnMenu.size(); i++){
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getId();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getName();
        cout << setw(columnWidth) << left << databaseDishOnMenu[i].getPrice();
        cout << endl;
    }

    cout << "Nhap ID mon an can them: ";
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
    } else {
        cout << "          Nhap so luong: ";
        cin >> quantity;

        system("cls");
        DishOnTable dishontable = {databaseDishOnMenu[i].getId(), databaseDishOnMenu[i].getName(), databaseDishOnMenu[i].getPrice(), quantity};
        vector<DishOnTable>& listDishOnTable = dataTable[count].getDatabaseDishOnTable();
        listDishOnTable.push_back(dishontable);
        dataTable[count].setStatus(true);
        cout << "BAN " << count + 1 <<"\n\n";
        cout << "          ____Them mon thanh cong____\n";
        cout << setw(columnWidth) << left << "ID";
        cout << setw(columnWidth) << left << "Ten";
        cout << setw(columnWidth) << left << "Gia";
        cout << setw(columnWidth) << left << "SL";
        cout << endl;
        cout << setw(columnWidth) << left << listDishOnTable[listDishOnTable.size() - 1].getId();
        cout << setw(columnWidth) << left << listDishOnTable[listDishOnTable.size() - 1].getName();
        cout << setw(columnWidth) << left << listDishOnTable[listDishOnTable.size() - 1].getPrice();
        cout << setw(columnWidth) << left << listDishOnTable[listDishOnTable.size() - 1].getQuantity();
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
                addADishToTable(databaseDishOnMenu, dataTable, count);
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
}

void updateADishOnTable(vector<Table>& dataTable, int count){
    system("cls");
    unsigned int i;
    int id, quantity;
    vector<DishOnTable>& dishontable = dataTable[count].getDatabaseDishOnTable();
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n" ;
    cout << "          ______________Danh sach mon an______________\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << setw(columnWidth) << left << "So luong";
    cout << endl;
    for (unsigned int i = 0; i < dishontable.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << dishontable[i].getId();
        cout << setw(columnWidth) << left << dishontable[i].getName();
        cout << setw(columnWidth) << left << dishontable[i].getPrice();
        cout << setw(columnWidth) << left << dishontable[i].getQuantity();
        cout << endl;
    }

    cout << "Nhap ID mon an can chinh sua: ";
    cin >> id;
    for (i = 0; i < dishontable.size(); i++){
        if (dishontable[i].getId() == id) break;
    }
    if (i == dishontable.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }

    system("cls");
    cout << "Nhap so luong: ";
    cin >> quantity;
    dishontable[i].setQuantity(quantity);
    system("cls");
    cout << "STAFF\n\n";
    cout << "          __________Sua mon thanh cong___________\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << setw(columnWidth) << left << "So luong";
    cout << endl;
    cout << setw(columnWidth) << left << dishontable[i].getId();
    cout << setw(columnWidth) << left << dishontable[i].getName();
    cout << setw(columnWidth) << left << dishontable[i].getPrice();
    cout << setw(columnWidth) << left << dishontable[i].getQuantity();
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
             updateADishOnTable(dataTable, count);
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

void deleteADishOnTable(vector<Table>& dataTable, int count){
    system("cls");
    unsigned int i;
    int id, idTemp, price, quantity;
    string name;
    vector<DishOnTable>& dishontable = dataTable[count].getDatabaseDishOnTable();
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n" ;
    cout << "          ______________Danh sach mon an______________\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << setw(columnWidth) << left << "So luong";
    cout << endl;
    for (unsigned int i = 0; i < dishontable.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << dishontable[i].getId();
        cout << setw(columnWidth) << left << dishontable[i].getName();
        cout << setw(columnWidth) << left << dishontable[i].getPrice();
        cout << setw(columnWidth) << left << dishontable[i].getQuantity();
        cout << endl;
    }

    cout << "Nhap ID mon an can xoa: ";
    cin >> id;
    for (i = 0; i < dishontable.size(); i++){
        if (dishontable[i].getId() == id) break;
    }
    if (i == dishontable.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }

    while (1){
        system("cls");
        cout << "STAFF\n\n";
        cout << "          Ban co chac chan khong?\n";
        cout << "          ________________________\n";
        cout << "          1: Co\n          2: Khong\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            idTemp = dishontable[i].getId();
            name = dishontable[i].getName();
            price = dishontable[i].getPrice();
            quantity = dishontable[i].getQuantity();
            dishontable.erase(dishontable.begin() + i);
            system("cls");
            cout << "STAFF\n\n";
            cout << "          __________Xoa thanh cong___________\n";
            cout << setw(columnWidth) << left << "ID";
            cout << setw(columnWidth) << left << "Ten";
            cout << setw(columnWidth) << left << "Gia";
            cout << setw(columnWidth) << left << "So luong";
            cout << endl;
            cout << setw(columnWidth) << left << id;
            cout << setw(columnWidth) << left << name;
            cout << setw(columnWidth) << left << price;
            cout << setw(columnWidth) << left << quantity;
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
                    deleteADishOnTable(dataTable, count);
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
            deleteADishOnTable(dataTable, count);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

void printListDishesOnTable(vector<Table>& dataTable, int count){
    system("cls");
    vector<DishOnTable> dishontable = dataTable[count].getDatabaseDishOnTable();
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n" ;
    cout << "          ______________Danh sach mon an______________\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << setw(columnWidth) << left << "So luong";
    cout << endl;
    for (unsigned int i = 0; i < dishontable.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << dishontable[i].getId();
        cout << setw(columnWidth) << left << dishontable[i].getName();
        cout << setw(columnWidth) << left << dishontable[i].getPrice();
        cout << setw(columnWidth) << left << dishontable[i].getQuantity();
        cout << endl;
    }
    while (1){
        cout << "Quay lai (1/0): ";
        cin >> key;
        if (key == 1) return; 
    }
}

void payDishesOnTable(vector<Table>& dataTable, int count){
    system("cls");
    int id, i, sumPrice = 0;
    vector<DishOnTable>& dishontable = dataTable[count].getDatabaseDishOnTable();
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n" ;
    cout << "          ______________Danh sach mon an______________\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ten";
    cout << setw(columnWidth) << left << "Gia";
    cout << setw(columnWidth) << left << "So luong";
    cout << endl;
    for (unsigned int i = 0; i < dishontable.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << dishontable[i].getId();
        cout << setw(columnWidth) << left << dishontable[i].getName();
        cout << setw(columnWidth) << left << dishontable[i].getPrice();
        cout << setw(columnWidth) << left << dishontable[i].getQuantity();
        cout << endl;
        sumPrice += dishontable[i].getPrice() * dishontable[i].getQuantity();
    }

    cout << "Tong gia tien: " << sumPrice << "\n";
    while (1){
        cout << "          ________________________\n";
        cout << "          1: Thanh toan\n";
        cout << "          0: Quay lai\n\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "THANH TOAN THANH CONG\n";
            dataTable[count].setStatus(false);
            dishontable.clear();
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

void processTable(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& dataTable, int count){
    system("cls");
    if  ((count > dataTable.size()) || (count < 1)){
        cout << "So ban khong hop le\n";
        return;
    }
    int key = -1;
    cout << "BAN " << count <<"\n\n" ;
    cout << "          ________________________\n";
    cout << "          1: Them mon\n";
    cout << "          2: Sua mon\n";
    cout << "          3: Xoa mon\n";
    cout << "          4: Danh sach mon\n";
    cout << "          5: Thanh toan\n";
    cout << "          0: Quay lai\n\n";
    cout << "          ________________________\n";
    cout << "          Nhap lua chon: ";

    cin >> key;
    switch (key)
    {
    case ADD_STAFF:
        addADishToTable(databaseDishOnMenu, dataTable, count - 1);
        break;
    case UPDATE_STAFF:
        updateADishOnTable(dataTable, count - 1);
        break;
    case DELETE_STAFF:
        deleteADishOnTable(dataTable, count - 1);
        break;
    case PRINT_STAFF:
        printListDishesOnTable(dataTable, count - 1);
        break;
    case PAY:
        payDishesOnTable(dataTable, count - 1);
        break;
    case RETURN_STAFF:
        return;
        break; 
    default:
        break;
    }
}

void Staff(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable){
    system("cls");
    int key = -1;
    int tempTable = -1;
    while (1){
        if (databaseTable.empty()){
            cout << "Manager chua nhap so luong ban\n";
            return;
        }
        int columnWidth = 5;
        cout << "STAFF\n\n";
        cout << "          ____Danh sach ban____\n";
        cout << setw(15) << left << "  So ban";
        for (unsigned int i = 0; i < databaseTable.size(); i++){
            cout << setw(columnWidth) << left << databaseTable[i].getNumbertable();
        }
        cout << endl;
        cout << setw(15) << left << "  Status";
        for (unsigned int i = 0; i < databaseTable.size(); i++){
            cout << setw(columnWidth) << left << databaseTable[i].getStatus();
        }
        cout << endl;

        cout << "  Nhap so ban: ";
        cin >> tempTable;
        processTable(databaseDishOnMenu, databaseTable, tempTable);
    }
}