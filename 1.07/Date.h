//Date.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
public:
	int getYear();
	int getMonth();
	int getDay();
	bool isLeap();
	Date operator+(int days);
	Date operator-(int days);
	Date& operator=(Date date);//присвоєння
	bool operator==(Date date);
	bool operator<(Date date);
	bool operator>(Date date);
	int CountOfDays(Date date);
	void Init(Date date);
	void Init(unsigned int year, unsigned int month, unsigned int day);
	void Init(string date);
	void Read();
	void Display();
};