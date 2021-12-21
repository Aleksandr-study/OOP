#ifndef CATALOGCOMPOSITION_H
#define CATALOGCOMPOSITION_H
#include "ArchiveElement.h"
class CatalogComposition
{
protected:
	int quality;
	ArchiveElement* elements/* = new ArchiveElement*/;
public:
	CatalogComposition();
	CatalogComposition(ArchiveElement* elements, int quality_);
	void setElements(ArchiveElement* elements_, int quality_);
	ArchiveElement* getElement();

	ArchiveElement& operator[] (int index);
	int getQuality();
	void Show();
	~CatalogComposition();
};
#endif