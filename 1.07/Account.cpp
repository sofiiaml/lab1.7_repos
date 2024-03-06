//Account.cpp
#include <iostream>
#include <string>
using namespace std;
#include "Account.h"

void Account::setLastname(string lastname) {
	this->lastname = lastname;
}
void Account::withdraw(double money) {
	if (money <= this->money) {
		this->money -= money;
	}
	else {
		cout << "Not enough money" << endl;
	}
}
void Account::putmoney(double money) {
	this->money += money;
}
double Account::calculateprocent(Date date) {
	this->procent = 0.01 * date.CountOfDays(this->date);
	return money * procent;
}
double Account::ConvertToDollar() {
	return money / 38.45;
}
double Account::ConvertToEuro() {
	return money / 41.78;
}
string Account::toString() {
	string res = to_string((int)money) + " hrn. " + to_string((int)(money * 100) % 100)+" kop. ";
	return res;
}
void Account::Init(string lastname, string number, Date date, double procent, double money) {
	this->lastname = lastname;
	this->number = number;
	this->date = date;
	this->procent = procent;
	this->money = money;
}
void Account::Read()
{
	string lastname, number;
	Date date;
	double procent, money;
	cout << "Input account data:" << endl;
	cout << " Lastname: "; cin >> lastname;
	cout << " Number: "; cin >> number;
	date.Read();
	cout << " Procent = ";cin >> procent;
	cout << " Money = "; cin >> money;
		Init(lastname,number,date,procent,money);
}
void Account::Display()
{
	cout << endl;
	cout << " Lastname: "<< lastname;
	cout << " Number: "<< number;
	date.Display();
	cout << " Procent = " << procent << endl;
	cout << " Money = " << money << endl;
}
