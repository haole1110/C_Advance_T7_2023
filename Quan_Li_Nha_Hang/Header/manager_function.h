#ifndef __MANAGERFUNCTION_H
#define __MANAGERFUNCTION_H

#include "quanlinhahang.h"

//----------MANAGER FUNCTION----------------
void setTable(vector<Table>& databaseTable);
void addADishToMenu(vector<DishOnMenu>& databaseDishOnMenu);
void updateADish(vector<DishOnMenu>& databaseDishOnMenu);
void deleteADishOnMenu(vector<DishOnMenu>& databaseDishOnMenu);
void printListDishOnMenu(vector<DishOnMenu> databaseDishOnMenu);
void Manager(vector<DishOnMenu>& databaseDishOnMenu, vector<Table>& databaseTable);

#endif