#include <iostream>
#include <string>
#include "Date.h"
#include "Account.h"

using namespace std;

int main() {
	Account a;
	a.Read();
	a.Display();
	cout << " Dollars: " << a.ConvertToDollar() << endl;
	cout << " Euros: " << a.ConvertToEuro() << endl;
	Date date;
	date.Init(2024, 3, 5);
	cout << " Procent money: " << a.calculateprocent(date) << endl;
	cout << " Withdraw 100" << endl;
	a.withdraw(100);
	cout << a.toString() << endl;
	cout << " Put 300" << endl;
	a.putmoney(300);
	cout << a.toString() << endl;
	Date d;
	d.Read();
	cout << "First date:";
	d.Display();cout << endl;
	Date d2;
	d2.Init("2024.03.05");
	Date d3;
	d3.Init(d2);
	cout<<"Second date";
	d3.Display();cout << endl;
	cout << "Date after 45 days:" << endl;
	Date d4 = d + 45;
	d4.Display();cout << endl;
	cout << "Date before 45 days:" << endl;
	Date d5 = d - 45;
	d5.Display();cout << endl;
	cout << "date comparison:" << endl;
	if (d > d3) {
		cout << " d>d3" << endl;
	}
	if (d < d3) {
		cout << " d<d3" << endl;
	}
	if (d == d3) {
		cout<<" d=d3"<<endl;
	}
	cout << endl;
	if (d.isLeap()) {
		cout << "date is leap year" << endl;
	}
	else {
		cout << "date is not leap year" << endl;
	}
	cout << endl;
	cout<<"days between dates:"<<endl;

	cout << " d2-d=" << d2.CountOfDays(d) << endl;
	Date d6 = d5;
	d6.Display();
}
//int getYear();
//int getMonth();
//int getDay();
//bool isLeap();
//Date operator+(int days);
//Date operator-(int days);
//Date& operator=(Date date);//присвоєння
//bool operator==(Date date);
//bool operator<(Date date);
//bool operator>(Date date);
//int CountOfDays(Date date);
//class Date {
//private:
//	int year;
//	int month;
//	int day;
//public:
//	int getYear() { return year; }
//	int getMonth() { return month; }
//	int getDay() { return day; }
//	bool isLeap() {
//		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//	}
//	Date operator+(int days) {
//		Date d;
//		d.year = year;
//		d.month = month;
//		d.day = day;
//		int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		while (days > 0) {
//			if (d.month == 13) {
//				d.month = 1;
//				d.year++;
//			}
//			if (amount[d.month - 1] - d.day < days) {
//				days -= amount[d.month - 1] - d.day;
//				d.month++;
//				d.day = 1;
//			}
//			else {
//				days -= amount[d.month - 1] - d.day;
//				d.day += amount[d.month - 1] - d.day;
//			}
//		}
//		return d;
//	}
//	Date operator-(int days) {
//		Date d;
//		d.year = year;
//		d.month = month;
//		d.day = day;
//		int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		while (days > 0) {
//			if (d.month == -1) {
//				d.month = 12;
//				d.year--;
//			}
//			if (d.day < days) {
//				d.day -= days;
//				days -= amount[d.month - 1] - d.day;
//			}
//			else {
//				days -= d.day;
//				d.day = amount[d.month - 2];
//				month--;
//			}
//		}
//		return d;
//	}
//	Date& operator=(Date date) {
//		year = date.year;
//		month = date.month;
//		day = date.day;
//		return *this;
//	}
//	bool operator==(Date date) {
//		return year == date.year && month == date.month && day == date.day;
//	}
//	bool operator<(Date date) {
//		if (year < date.year) {
//			return true;
//		}
//		else if (year == date.year) {
//			if (month < date.month) {
//				return true;
//			}
//			else if (month == date.month) {
//				if (day < date.day) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	bool operator>(Date date) {
//		return date < *this;
//	}
//	int CountOfDays(Date date) {
//		int days = 0;
//		int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (*this > date) {
//			while (!(*this == date)) {
//				if (date.day == 0) {
//					date.day = amount[(month + 10 % 12)];
//					date.month--;
//				}
//				if (date.month == -1) {
//					date.year--;
//					date.month = 12;
//				}
//				days++;
//				date.day--;
//			}
//		}
//		else if (*this == date) {
//			return 0;
//		}
//		else {
//			while (!(*this == date)) {
//				if (date.day == amount[date.month - 1]) {
//					date.day = 1;
//					date.month++;
//				}
//				if (date.month == 13) {
//					date.year++;
//					date.month = 1;
//				}
//				days++;
//				date.day++;
//			}
//		}
//	}
//};
//class Account {
//private:
//	string lastname;
//	string number;
//	Date date;
//	double procent;
//	double money;
//public:
//	void setLastname(string lastname) {
//		this->lastname = lastname;
//	}
//	void withdraw(double money) {
//		if (money <= this->money) {
//			this->money -= money;
//		}
//		else {
//			cout << "Not enough money" << endl;
//		}
//	}
//	void putmoney(double money) {
//		this->money += money;
//	}
//	double calculateprocent(Date date) {
//		this->procent = 0.01 * date.CountOfDays(this->date);
//		return money * procent;
//	}
//	double ConvertToDollar() {
//		return money / 38.45;
//	}
//	double ConvertToEuro() {
//		return money / 41.78;
//	}
//	string toString() {
//		string str = "";
//		if (money / 1000 == 1) {
//			str += "одна тисяча ";
//		}
//		else if (money / 1000 > 4) {
//			str += to_string(int(money / 1000))+" тисяч ";
//		}
//		else {
//			str += to_string(int(money / 1000)) + " тисячі ";
//		}
//	}
//};