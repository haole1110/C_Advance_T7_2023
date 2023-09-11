#include<iostream>
#include<vector>
#include<string>
#include <iomanip>

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
        string NAME;
        int PRICE;
    public:
        DishOnMenu(string name, int price);
        void setName(string name);
        void setPrice(int price);
        string getName();
        int getPrice();
};

DishOnMenu::DishOnMenu(string name, int price){
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


//DishOnTable Class -----------------------------------------------------------------------------

class DishOnTable{
    private:
        string NAME;
        int PRICE;
        int QUANTITY;
    public:
        DishOnTable(string name, int price, int quantity);
        void setName(string name);
        void setPrice(int price);
        void setQuantity(int quantity);
        string getName();
        int getPrice();
        int getQuantity();
};

DishOnTable::DishOnTable(string name, int price, int quantity){
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

void processTable(int count){
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
        
        break;
    case UPDATE_STAFF:
        
        break;
    case DELETE_STAFF:
        
        break;
    case PRINT_STAFF:
        
        break;
    case PAY:
        
        break;
    case RETURN_STAFF:
        return;
        break; 
    default:
        break;
    }
}

void Staff(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable){
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
            cout << setw(columnWidth) << left << i+1;
        }
        cout << endl;
        cout << setw(15) << left << "  Status";
        for (int i = 0; i < databaseTable.size(); i++){
            cout << setw(columnWidth) << left << databaseTable[i].getStatus();
        }
        cout << endl;

        cout << "  Nhap so ban: ";
        cin >> tempTable;
        processTable(tempTable);
    }
}


//Manager---------------------------------------------------------------------------------
void setTable(vector<Table>& databaseTable){
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
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}


void Manager(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable){
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
            
            break;
        case UPDATE:
            
            break;
        case DELETE:
            
            break;
        case PRINT:
            
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