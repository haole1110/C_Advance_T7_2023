#include "quanlinhahang.h"

//---------------------------------CLASS---------------------------------------------
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
