#ifndef __QUANLINHAHANG_H
#define __QUANLINHAHANG_H

#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//---------------------------------ENUM---------------------------------------------

//Main manager funcitons in the system
typedef enum{
    RETURN      = 0,
    SETTABLE    = 1,
    ADD         = 2,
    UPDATE      = 3,
    DELETE      = 4,
    PRINT       = 5
}typeModeManager;

//Main staff funcitons in the system
typedef enum{
    RETURN_STAFF    = 0,
    ADD_STAFF       = 1,
    UPDATE_STAFF    = 2,
    DELETE_STAFF    = 3,
    PRINT_STAFF     = 4,
    PAY             = 5
}typeModeStaff;


//---------------------------------CLASS---------------------------------------------
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

#endif
