#include "SystemController.h"
#include "ExtraFunctions.h"

int SystemController::MenuOfChanges() {
	int Choice;
	cout << "For updating " << endl;
	cout << "Name , choose 1" << endl;
	cout << "Age , choose 2" << endl;
	cout << "Salary , choose 3" << endl;
	dashes();
	cin >> Choice;
	return Choice;
}

void SystemController::ShowAllEmployeesData() {
	if (!_employees.size()) {
		cout << "No employees found" << endl;
		return;
	}
	list<Employee*> Temporary = _employees;
	while (!Temporary.empty()) {
		Temporary.back()->PrintData();
		dashes();
		Temporary.pop_back();
	}
}

void SystemController::AddEmployee() {
	Employee* NewEmployee = new Employee();
	_employees.push_back(NewEmployee);
}

//Read
Employee* SystemController::GetEmployee(string Name) {
	for (auto temporary : _employees) {
		if (temporary->GetName() == Name)
			return temporary;
	}
	return NULL;
}
Employee* SystemController::GetEmployee(int ID) {
	for (auto temporary : _employees) {
		if (temporary->GetID() == ID)
			return temporary;
	}
	return NULL;
}

//Update
void SystemController::UpdateEmployee() {
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
void SystemController::RemoveEmployee() {
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

SystemController::~SystemController() {
	if (_employees.size()) {
		for (auto temporary : _employees) {
			delete temporary;
			temporary = NULL;
		}
	}
}