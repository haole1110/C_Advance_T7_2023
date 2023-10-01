#ifndef __MAINFUNCTION_H
#define __MAINFUNCTION_H

#include "quanlikhachsan.h"
#include "manage_customer_function.h"
#include "manage_employee_function.h"
#include "manage_payment_function.h"
#include "manage_security_function.h"

void bookRoom(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer);
void manageCustomer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer, SecurityManagement securityManagement, vector<Employee> databaseEmployee);
void manageEmployee(SecurityManagement& securityManagement, vector<Employee>& databaseEmployee);
void manageService(Service& service);
void managePayment(vector<Room>& databaseRoom, vector<Customer>& dataCustomer, vector<PayHistory>& databasePayHistory);
void statisticHotel(vector<Room> databaseRoom, vector<PayHistory> databasePayHistory);
void securityManage(SecurityManagement& securityManagement, vector<Employee> databaseEmployee);
void manageFeedback(vector<Feedback>& databaseFeedback);


#endif