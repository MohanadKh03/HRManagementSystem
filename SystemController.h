#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#include "Employee.h"


class SystemController {
	list<Employee*> _employees;
	//Request _request;

	int MenuOfChanges();

public:

	void ShowAllEmployeesData();

	//Create
	void AddEmployee();

	//Read
	Employee* GetEmployee(string Name);
	Employee* GetEmployee(int ID);
	//Update
	void UpdateEmployee();

	//Delete
	void RemoveEmployee();

	~SystemController();
};