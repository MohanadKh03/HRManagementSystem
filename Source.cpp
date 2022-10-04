#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#include "ExtraFunctions.h"
#include "Employee.h"
#include "SystemController.h"

int main() {
	SystemController System;
	int choice;
	char again;

	do {
		do {
			cout << "Enter 1 to add an employee " << endl;
			cout << "Enter 2 to update an employee " << endl;
			cout << "Enter 3 to remove an employee " << endl;
			cout << "Enter 4 to show all employees' data " << endl;
			dashes();

			cin >> choice;
		} while (choice < 1 || choice > 4);
		if (choice == 1)
			System.AddEmployee();
		if (choice == 2)
			System.UpdateEmployee();
		if (choice == 3)
			System.RemoveEmployee();
		if (choice == 4)
			System.ShowAllEmployeesData();
		dashes();
		cout << "Do you want another operation: "; cin >> again;
	} while (again == 'y' || again == 'Y');

	return 0;
}