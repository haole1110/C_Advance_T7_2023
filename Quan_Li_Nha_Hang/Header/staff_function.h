#ifndef __STAFFFUNCTION_H
#define __STAFFFUNCTION_H

#include "quanlinhahang.h"

//----------STAFF FUNCTION----------------
void addADishToTable(vector<DishOnMenu> databaseDishOnMenu,vector<Table>& dataTable, int count);
void updateADishOnTable(vector<Table>& dataTable, int count);
void deleteADishOnTable(vector<Table>& dataTable, int count);
void printListDishesOnTable(vector<Table>& dataTable, int count);
void payDishesOnTable(vector<Table>& dataTable, int count);
void processTable(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& dataTable, int count);
void Staff(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable);

#endif