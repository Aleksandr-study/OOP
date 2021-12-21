#include <iostream>
#include "TextDocument.h"

TextDocument::TextDocument()
{
	keywords = "-";
	placing = "-";
	archivingDegree = 0;
}

TextDocument::TextDocument(std::string keywords_, std::string placing_, int archivingDegree_, File *file_, Person *author_)
{
	keywords = keywords_;
	placing = placing_;
	archivingDegree = archivingDegree_;
	file = *file_;
	author = *author_;
}

void TextDocument::setArchivingDegree(int archivingDegree_)
{
	if (archivingDegree_ < 1)
	{
		archivingDegree = 1;
		std::cout << "Invalid degree of archiving: " << archivingDegree_ << ". Parameter changed to default value: 1.\n";
	}
	else
		archivingDegree = archivingDegree_;
}

std::string TextDocument::getKeywords()
{ 	return keywords;
}

void TextDocument::setKeywords(std::string keywords_)
{
	if (keywords_.length() < 2)
	{
		keywords = "flame";
		std::cout << "Invalid keywords: : " <<  keywords_ << ". Parameter changed to default value: flame.\n";
	}
	else
		keywords = keywords_;
}

std::string TextDocument::getPlacing()
{
	return placing;
}

void TextDocument::setPlacing(std::string placing_)
{
	if (placing_.length() < 2)
	{
		placing = "C:";
		std::cout << "Invalid placing: " << placing_ << ". Parameter changed to default value: C:\n";
	}
	else
		placing = placing_;
}

void TextDocument::setFile(File *file_)
{
	file = *file_;
}

void TextDocument::setAuthor(Person *author_)
{
	author = *author_;
}


void TextDocument::Show()
{
	author.Show();
	std::cout << "\t";
	file.Show();
	std::cout << getPlacing();
	std::cout << std::endl;
}

File* TextDocument::getFile()
{
	return &file;
}

Person* TextDocument::getPerson()
{
	return &author;
}

int TextDocument::getArchivingDegree()
{
	return archivingDegree;
}

TextDocument::~TextDocument()
{

}