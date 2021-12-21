#include <iostream>
#include <cmath>
#include "Person.h"
//похідний клас: Особа (Прізвище, Ім’я, Дата (народження));

Person::Person() : Date()
{
	name = '-';
	surname = '-';
}

Person::Person(std::string name_, std::string surname_) : Date()
{
	name = name_;
	surname = surname_;
}
Person::Person(int day_, int month_, int year_, std::string name_, std::string surname_) : Date(day_, month_, year_)
{
	name = name_;
	surname = surname_;
}

Person::Person(const Person& T)
{
	name = T.name;
	surname = T.surname;
}

std::string Person::getName()
{
	return name;
}
void Person::setName(std::string name_)
{
	if (name_.length() < 2)
	{
		std::cout << "Invalid name: " << name_ <<". Parameter changed to default value: Ivan.\n";
		name = "Ivan";
	}
	else
		name = name_;
}
std::string Person::getSurname()
{
	return surname;
}
void Person::setSurname(std::string surname_)
{
	if (surname_.length() < 2)
	{
		std::cout << "Invalid surname: " << surname_ << ". Parameter changed to default value: Ivanov.\n";
		surname = "Ivanov";
	}
	else
		surname = surname_;
}


void Person::Show()
{
	std::cout << getName() << "\t" << getSurname() << "\t";
	//Date::Show();
}

int Person::getDay()
{
	return Date::getDay();
}
int Person::getMonth()
{
	return Date::getMonth();
}
int Person::getYear()
{
	return Date::getYear();
}

void Person::setDate(int day_, int month_, int year_)
{
	Date::setDay(day_);
	Date::setMonth(month_);
	Date::setYear(year_);
}

Person::~Person()
{

}
