//Date.cpp
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int Date::getYear() { return year; }
int Date::getMonth() { return month; }
int Date::getDay() { return day; }

bool Date::isLeap() {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
Date Date::operator+(int days) {
	Date d;
	d.year = year;
	d.month = month;
	d.day = day;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (days > 0) {
		if (d.month == 13) {
			d.month = 1;
			d.year++;
		}
		if (d.day==amount[d.month - 1]) {
			
			d.month++;
			d.day = 1;
		}
		d.day++;
		days--;
	}
	return d;
}
Date Date::operator-(int days) {
	Date d;
	d.year = year;
	d.month = month;
	d.day = day;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (days > 0) {
		

		if (d.day == 0) {
		
			d.day = amount[(d.month+10)%12];
			d.month--;
		}
		if (d.month == 0) {
			d.month = 12;
			d.year--;
		}
		d.day--;
		days--;
	}
	return d;
}
Date& Date::operator=(Date date) {
	year = date.year;
	month = date.month;
	day = date.day;
	return *this;
}
bool Date::operator==(Date date) {
	return year == date.year && month == date.month && day == date.day;
}
bool Date::operator<(Date date) {
	if (year < date.year) {
		return true;
	}
	else if (year == date.year) {
		if (month < date.month) {
			return true;
		}
		else if (month == date.month) {
			if (day < date.day) {
				return true;
			}
		}
	}
	return false;
}
bool Date::operator>(Date date) {
	return date < *this;
}
int Date::CountOfDays(Date date) {
	int days = 0;
	int amount[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (*this > date) {
		while (!(*this == date)) {
			if (date.day == amount[month-1]) {
				date.day = 1;
				date.month++;
			}
			if (date.month == 12) {
				date.year++;
				date.month = 1;
			}
			days++;
			date.day++;
		}
	}
	else  {
		return 0;
	}
	/*else {
		return date.CountOfDays(*this)
	}*/
	return days;
}
void Date::Init(Date date) {
	year = date.year;
	month = date.month;
	day = date.day;

}
void Date::Init(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
void Date::Init(string date) {
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8, 2));
}
void Date::Read()
{
	unsigned int year, month, day;
	cout << "Input date:" << endl;
	cout << " Year = "; cin >> year;
	cout << " Month = "; cin >> month;
	cout << " Day = "; cin >> day;
		Init(year,month,day);
}
void Date::Display()
{
	cout << endl;
	cout << " Year = " << year << endl;
	cout << " Month = " << month << endl;
	cout << " Day = " << day << endl;
}
