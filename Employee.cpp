#include "Employee.h"
#include "ExtraFunctions.h"

int Employee::ID = 0;

Employee::Employee() {
	EmployeeID = ++ID;
	cin.ignore();
	cout << "Enter employee's name: "; getline(cin, Name);
	cout << "Enter employee's age: "; cin >> Age;
	cout << "Enter employee's salary: "; cin >> Salary;
}

void Employee::PrintData() {
	cout << "ID: " << EmployeeID << endl;
	cout << "Name: " << Name << endl;
	cout << "Age: " << Age << endl;
	cout << "Salary: " << Salary << endl;
}

int Employee::GetID() {
	return this->EmployeeID;
}

void Employee::SetName(string Name) {
	this->Name = Name;
}
string Employee::GetName() {
	return this->Name;
}

void Employee::SetAge(int Age) {
	this->Age = Age;
}
int Employee::GetAge() {
	return this->Age;
}

void Employee::SetSalary(double Salary) {
	this->Salary = Salary;
}
double Employee::GetSalary() {
	return this->Salary;
}