#ifndef __MANAGESECURITY_H
#define __MANAGESECURITY_H

#include "quanlikhachsan.h"

void addAUser(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);
void changePasswordAUser(SecurityManagement& securityManagement);
void deleteAUser(SecurityManagement& securityManagement);
void printListUser(SecurityManagement& securityManagement);
void editUserManagerPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);
void changePasswordManager(SecurityManagement& securityManagement);
void managerPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);
void userPermission(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);


#endif