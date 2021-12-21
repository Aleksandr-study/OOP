#include "ArchiveElement.h"
#include <iostream>

ArchiveElement::ArchiveElement() : Date()
{
	quantity = 3;
}

ArchiveElement::ArchiveElement(int day_, int month_, int year_, TextDocument* documents_, int quantity_) : Date(day_, month_, year_)
{
	this->documents = documents_;
	quantity = quantity_;
}

void ArchiveElement::setDocuments(TextDocument* documents_, int quantity_)
{
	quantity = quantity_;
	this->documents = documents_;
}

void ArchiveElement::setDate(int day_, int month_, int year_)
{
	Date::setDay(day_);
	Date::setMonth(month_);
	Date::setYear(year_);
}

void ArchiveElement::setQuantity(int quantity_)
{
	quantity = quantity_;
}

int ArchiveElement::getQuantity()
{
	return quantity;
}

void ArchiveElement::Show()
{
	for (int j = 0; j < quantity; j++)
	{
		documents[j].Show();
	}
}

TextDocument* ArchiveElement::getDocument()
{
	return documents;
}

int ArchiveElement::getDay()
{
	return Date::getDay();
}
int ArchiveElement::getMonth()
{
	return Date::getMonth();
}
int ArchiveElement::getYear()
{
	return Date::getYear();
}


ArchiveElement::~ArchiveElement()
{
	if (!documents)
	{
		delete[] documents;
	}
}