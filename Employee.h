#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Employee {
	static int ID;
	int EmployeeID;
	string Name;
	int Age;
	double Salary;
public:
	Employee();

	void PrintData();

	int GetID();

	void SetName(string Name);
	string GetName();

	void SetAge(int Age);
	int GetAge();

	void SetSalary(double Salary);
	double GetSalary();
};
