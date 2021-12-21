#include <iostream>
#include <cmath>
#include "File.h"
//похідний клас: Особа (Прізвище, Ім’я, Дата (народження));

File::File() : Date()
{
	nameOfFile = '-';
	extension = '-';
	size = 0;
}

File::File(std::string nameOfFile_, std::string extension_, int size_) : Date()
{
	nameOfFile = nameOfFile_;
	extension = extension_;
	size = size_;
}
File::File(int day_, int month_, int year_, std::string nameOfFile_, std::string extension_, int size_) : Date(day_, month_, year_)
{
	nameOfFile = nameOfFile_;
	extension = extension_;
	size = size_;
}

File::File(const File& T)
{
	nameOfFile = T.nameOfFile;
	extension = T.extension;
}

void File::setDate(int day_, int month_, int year_)
{
	Date::setDay(day_);
	Date::setMonth(month_);
	Date::setYear(year_);
}

std::string File::getNameOfFile()
{
	return nameOfFile;
}
void File::setNameOfFile(std::string nameOfFile_)
{
	if (nameOfFile_.length() < 2)
	{
		nameOfFile = "File";
		std::cout << "Invalid name of file. Parameter changed to default value: File.\n";
	}
	else
		nameOfFile = nameOfFile_;
}
std::string File::getExtension()
{
	return extension;
}
void File::setExtension(std::string extension_)
{
	if (extension_.length() < 2)
	{
		extension = "txt";
		std::cout << "Invalid extension. Parameter changed to default value: txt.\n";
	}
	else
		extension = extension_;
}
int File::getSize()
{
	return size;
}
void File::setSize(int size_)
{
	if (size_ < 0)
	{
		size = 1;
		std::cout << "Invalid size. Parameter changed to default value: 1.\n";
	}
	else
		size = size_;
}
int File::getDay()
{
	return Date::getDay();
}
int File::getMonth()
{
	return Date::getMonth();
}
int File::getYear()
{
	return Date::getYear();
}

void File::Show()
{
	std::cout << getNameOfFile() << "\t\t" << getExtension() << "\t\t" << getSize() << "\t";
	//Date::Show();
}

File::~File()
{

}
