//Account.h
#pragma once
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	string lastname;
	string number;
	Date date;
	double procent;
	double money;
public:
	double getMoney() { return money; }
	void setLastname(string lastname);
	void withdraw(double money);
	void putmoney(double money);
	double calculateprocent(Date date);
	double ConvertToDollar();
	double ConvertToEuro();
	string toString();
	void Init(string lastname, string number, Date date, double procent, double money);
	void Read();
	void Display();
};