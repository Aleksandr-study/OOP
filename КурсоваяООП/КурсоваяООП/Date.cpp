#include <iostream>
#include "Date.h"
//базовий клас: Дата (Рік, Місяць, День); 

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}
Date::Date(int day_, int month_, int year_)
{
	day = day_;
	month = month_;
	year = year_;
}

Date::Date(const Date& T)
{
	day = T.day;
	month = T.month;
	year = T.year;
}

int Date::getDay()
{
	return day;
}
void Date::setDay(int day_)
{
	if (day_ < 0 || day_ > 31)
	{
		std::cout << "Invalid day : " << day_ << ". Parameter changed to default value: 1.\n";
		day = 1;
	}
	else
		day = day_;
}
int Date::getMonth()
{
	return month;
}
void Date::setMonth(int month_)
{
	if (month_ < 0 || month_ > 13)
	{
		std::cout << "Invalid month: " << month_ << ". Parameter changed to default value: 1.\n";
		month = 1;
	}
	else
		month = month_;
}
int Date::getYear()
{
	return  year;
}
void Date::setYear(int year_)
{
	if (year_ < 1950 || year_ > 2020)
	{
		
		std::cout << "Invalid year: "<< year_ << ". Parameter changed to default value: 2000.\n";
		year = 2000;
	}
	else
		year = year_;
}
void Date::Show()
{
	std::cout << day << "." << month << "." << year;
}

void Date::setDate(int day_, int month_, int year_)
{
	setDay(day_);
	setMonth(month_);
	setYear(year_);
}

Date::~Date()
{

}
