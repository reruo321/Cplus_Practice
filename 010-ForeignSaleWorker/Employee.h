#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace RISK_LEVEL {
	enum {
		RISK_A = 3,
		RISK_B = 2,
		RISK_C = 1
	};
}

class Employee
{
	char name[100];

public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	
	void ShowYourName() const{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker :public Employee {
	int salary;
public:
	PermanentWorker(const char * name, int money): Employee(name), salary(money){}
	int GetPay() const{
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker:public Employee{
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char * name, int pay): Employee(name), workTime(0), payPerHour(pay){}

	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker :public PermanentWorker {
	int salesResult;
	double bonusRatio;

public:
	SalesWorker(const char * name, int money, double ratio):PermanentWorker(name, money),salesResult(0), bonusRatio(ratio){}
	void AddSalesResult(int value){
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

/* TODO: Add ForeignSalesWorker Class */

class ForeignSalesWorker :public SalesWorker {
	int risklevel;

public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risklevel):SalesWorker(name, money, ratio), risklevel(risklevel){}
	int GetPay() const {
		return (int)(SalesWorker::GetPay() * risklevel * 0.1);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

/* End of TODO */

class EmployeeHandler {
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() :empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};