#ifndef __MANAGEEMPLOYEE_H
#define __MANAGEEMPLOYEE_H

#include "quanlikhachsan.h"

void updateAEmployee(vector<Employee>& databaseEmployee);
void deleteAEmployee(vector<Employee>& databaseEmployee);
void addAEmployee(vector<Employee>& databaseEmployee);
void printListEmployee(vector<Employee> databaseEmployee);
void manageEmployeeManagerPermission(vector<Employee>& databaseEmployee);
void manageEmployeeUserPermission(vector<Employee>& databaseEmployee, int stt);

#endif