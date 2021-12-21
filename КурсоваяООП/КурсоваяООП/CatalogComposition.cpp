#include <iostream>
#include "CatalogComposition.h"

CatalogComposition::CatalogComposition()
{
	this->elements = NULL;
	quality = 0;
}

CatalogComposition::CatalogComposition(ArchiveElement* elements_, int quality_)
{
	this->elements = elements_;
	quality = quality_;
}

void CatalogComposition::setElements(ArchiveElement* elements_, int quality_)
{
	this->elements = elements_;
	quality = quality_;
}

ArchiveElement* CatalogComposition::getElement()
{
	return elements;
}

void CatalogComposition::Show()
{
	for (int j = 0; j < quality; j++)
	{
		elements[j].Show();
	}
}

ArchiveElement& CatalogComposition::operator[](const int index)
{
	return elements[index];
}

int CatalogComposition::getQuality()
{
	return quality;
}

CatalogComposition::~CatalogComposition()
{
	if (!elements)
	{
		delete[] elements;
	}
}
