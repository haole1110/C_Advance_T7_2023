#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//---------------------------------ENUM---------------------------------------------
typedef enum{
    RETURN      = 0,
    SETTABLE    = 1,
    ADD         = 2,
    UPDATE      = 3,
    DELETE      = 4,
    PRINT       = 5
}typeModeManager;

typedef enum{
    RETURN_STAFF    = 0,
    ADD_STAFF       = 1,
    UPDATE_STAFF    = 2,
    DELETE_STAFF    = 3,
    PRINT_STAFF     = 4,
    PAY             = 5
}typeModeStaff;

//---------------------------------CLASS---------------------------------------------

//DishOnMenu Class -----------------------------------------------------------------------------
class DishOnMenu{
    private:
        int ID;
        string NAME;
        int PRICE;
    public:
        DishOnMenu(string name, int price);
        void setName(string name);
        void setPrice(int price);
        int getId();
        string getName();
        int getPrice();
};

DishOnMenu::DishOnMenu(string name, int price){
    static int id = 100;
    id++;
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
}

void DishOnMenu::setName(string name){
    this->NAME = name;
}

void DishOnMenu::setPrice(int price){
    this->PRICE = price;
}

string DishOnMenu::getName(){
    return this->NAME;
}

int DishOnMenu::getPrice(){
    return this->PRICE;
}

int DishOnMenu::getId(){
    return this->ID;
}


//DishOnTable Class -----------------------------------------------------------------------------

class DishOnTable{
    private:
        int ID;
        string NAME;
        int PRICE;
        int QUANTITY;
    public:
        DishOnTable(int id, string name, int price, int quantity);
        void setName(string name);
        void setPrice(int price);
        void setQuantity(int quantity);
        int getId();
        string getName();
        int getPrice();
        int getQuantity();
};

DishOnTable::DishOnTable(int id, string name, int price, int quantity){
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
    this->QUANTITY = quantity;
}

void DishOnTable::setName(string name){
    this->NAME = name;
}

void DishOnTable::setPrice(int price){
    this->PRICE = price;
}

void DishOnTable::setQuantity(int quantity){
    this->QUANTITY = quantity;
}

string DishOnTable::getName(){
    return this->NAME;
}

int DishOnTable::getPrice(){
    return this->PRICE;
}

int DishOnTable::getQuantity(){
    return this->QUANTITY;
}

int DishOnTable::getId(){
    return this->ID;
}


//Table Class -----------------------------------------------------------------------------
class Table{
    private:
        vector<DishOnTable> databaseDishOnTable;
        int NUMBERTABLE;
        bool STATUS;
    public:
        Table(int numbertable);
        void setNumbertable(int numbertable);
        void setStatus(bool status);
        int getNumbertable();
        bool getStatus();
        vector<DishOnTable>& getDatabaseDishOnTable();
};

Table::Table(int numbertable){
    this->NUMBERTABLE = numbertable;
    this->STATUS = false;
}

void Table::setNumbertable(int numbertable){
    this->NUMBERTABLE = numbertable;
}

void Table::setStatus(bool status){
    this->STATUS = status;
}

int Table::getNumbertable(){
    return this->NUMBERTABLE;
}

bool Table::getStatus(){
    return this->STATUS;
}

vector<DishOnTable>& Table::getDatabaseDishOnTable(){
    return this->databaseDishOnTable;
}

//---------------------------------FUNCTION-----------------------------------------

void addADishToTable(vector<DishOnMenu> databaseDishOnMenu,vector<Table>& dataTable, int count){
    system("cls");
    string name;
    int price;
    int id, i, idTemp, quantity;
    int columnWidth = 20;
    int key;
    cout << "BAN " << count + 1 <<"\n\n"; 
    for (int i = 0; i < databaseDishOnMenu.size(); i++){
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
    int id, i, quantity;
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
    for (int i = 0; i < dishontable.size(); i++){
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
    int id, i, idTemp, price, quantity;
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
    for (int i = 0; i < dishontable.size(); i++){
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
    for (int i = 0; i < dishontable.size(); i++){
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
    for (int i = 0; i < dishontable.size(); i++){
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
        for (int i = 0; i < databaseTable.size(); i++){
            cout << setw(columnWidth) << left << databaseTable[i].getNumbertable();
        }
        cout << endl;
        cout << setw(15) << left << "  Status";
        for (int i = 0; i < databaseTable.size(); i++){
            cout << setw(columnWidth) << left << databaseTable[i].getStatus();
        }
        cout << endl;

        cout << "  Nhap so ban: ";
        cin >> tempTable;
        processTable(databaseDishOnMenu, databaseTable, tempTable);
    }
}


//Manager---------------------------------------------------------------------------------
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
    int i, id, key, price;
    string name;
    cout << "MANAGER\n\n";
    for (int i = 0; i < databaseDishOnMenu.size(); i++){
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
    int id, i, idTemp;
    int columnWidth = 20;
    int key;
    cout << "MANAGER\n\n";
    for (int i = 0; i < databaseDishOnMenu.size(); i++){
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
    for (int i = 0; i < databaseDishOnMenu.size(); i++){
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

int main(){
    system("cls");
    vector<DishOnMenu> databaseMenu;
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