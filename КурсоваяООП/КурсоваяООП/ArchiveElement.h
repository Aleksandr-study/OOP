#ifndef ARCHIVEELEMENT_H
#define ARCHIVEELEMENT_H
#include "Date.h"
#include "TextDocument.h"
class ArchiveElement: virtual public Date, public TextDocument
{
protected:
	TextDocument* documents /*= new TextDocument*/;
	int quantity;
public:
	ArchiveElement();
	ArchiveElement(int day_, int month_, int year_, TextDocument* documents_, int quantity_);
	void setDocuments(TextDocument* documents_, int quantity_);
	void setDate(int day_, int month_, int year_);
	void setQuantity(int quantity_);
	int getQuantity();
	TextDocument* getDocument();
	int getDay();
	int getMonth();
	int getYear();
	void Show();
	~ArchiveElement();
};
#endif