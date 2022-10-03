#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void dashes() {
	cout << "---------------------------------" << endl;
}


class Request {
	int RequestID;
public:
	Request() 
	{
		RequestID = 0;
	}
	Request(int RequestID) {
		this->RequestID = RequestID;
	}
	void SubmitRequest() {

	}
};


class Employee {
	static int ID;
	int EmployeeID;
	string Name;
	int Age;
	double Salary;
public:
	Employee() {
		EmployeeID = ++ID;
		cin.ignore();
		cout << "Enter employee's name: "; getline(cin, Name);
		cout << "Enter employee's age: "; cin >> Age;
		cout << "Enter employee's salary: "; cin >> Salary;
	}

	void PrintData() {
		cout << "ID: " << EmployeeID << endl;
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
		cout << "Salary: " << Salary << endl;
	}

	int GetID() {
		return this->EmployeeID;
	}

	void SetName(string Name) {
		this->Name = Name;
	}
	string GetName() {
		return this->Name;
	}

	void SetAge(int Age) {
		this->Age = Age;
	}
	int GetAge() {
		return this->Age;
	}

	void SetSalary(double Salary) {
		this->Salary = Salary;
	}
	double GetSalary() {
		return this->Salary;
	}
};

int Employee::ID;

class SystemController {
	list<Employee*> _employees;
	Request _request;

	int MenuOfChanges() {
		int Choice;
		cout << "For updating " << endl;
		cout << "Name , choose 1" << endl;
		cout << "Age , choose 2" << endl;
		cout << "Salary , choose 3" << endl;
		dashes();
		cin >> Choice;
		return Choice;
	}

public:

	void ShowAllEmployeesData() {
		if (!_employees.size()) {
			cout << "No employees found" << endl;
			return;
		}
		list<Employee*> Temporary = _employees;
		while (!Temporary.empty()){
			Temporary.back()->PrintData();
			dashes();
			Temporary.pop_back();
		}
	}

	//Create
		void AddEmployee() {
			Employee* NewEmployee = new Employee();
			_employees.push_back(NewEmployee);
		}

	//Read
		Employee* GetEmployee(string Name) {
			for (auto temporary : _employees) {
				if (temporary->GetName() == Name)
					return temporary;
			}
			return NULL;
		}
		Employee* GetEmployee(int ID) {
			for (auto temporary : _employees) {
				if (temporary->GetID() == ID)
					return temporary;
			}
			return NULL;
		}

	//Update
		void UpdateEmployee() {
			if (!_employees.size()) {
				cout << "No employees found" << endl;
				return;
			}
			Employee* UpdatedEmployee = NULL;
			do {
				cout << "Enter 1 for searching by name, 2 for searching by ID." << endl;
				dashes();
				int choice;
				cin >> choice;
				if (choice == 1) {
					string Name;
					cout << "Enter employee's name: ";
					cin >> Name;
					UpdatedEmployee = GetEmployee(Name);
				}
				else {
					int ID;
					cout << "Enter employee's ID: ";
					cin >> ID;
					UpdatedEmployee = GetEmployee(ID);
				}
			} while (!UpdatedEmployee);

			int Change = MenuOfChanges();
			do {
				Change = MenuOfChanges();
			} while (Change < 1 || Change > 3);

			if (Change == 1) {
				string UpdatedName;
				cout << "Enter the updated name" << endl;
				cin >> UpdatedName;
				UpdatedEmployee->SetName(UpdatedName);
			}
			else if (Change == 2) {
				int UpdatedAge;
				cin >> UpdatedAge;
				cout << "Enter the updated age" << endl;
				UpdatedEmployee->SetAge(UpdatedAge);
			}
			else if (Change == 3) {
				double UpdatedSalary;
				cout << "Enter the updated salary" << endl;
				cin >> UpdatedSalary;
				UpdatedEmployee->SetSalary(UpdatedSalary);
			}

		}

	//Delete
		void RemoveEmployee() {
			if (!_employees.size()) {
				cout << "No employees found" << endl;
				return;
			}
			Employee* RemovedEmployee = NULL;
			do {
				cout << "Enter 1 for searching by name, 2 for searching by ID." << endl;
				int choice;
				cin >> choice;
				if (choice == 1) {
					string Name;
					cout << "Enter employee's name: ";
					cin >> Name;
					RemovedEmployee = GetEmployee(Name);
				}
				else {
					int ID;
					cout << "Enter employee's ID: ";
					cin >> ID;
					RemovedEmployee = GetEmployee(ID);
				}
			} while (!RemovedEmployee);
			auto iterator = find(_employees.begin(), _employees.end(), RemovedEmployee);
			_employees.erase(iterator);
		}

	~SystemController(){
		if (_employees.size()) {
			for (auto temporary : _employees) {
				delete temporary;
				temporary = NULL;
			}
		}
	}
};

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