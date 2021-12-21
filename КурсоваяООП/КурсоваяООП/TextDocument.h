#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H
#include "Person.h"
#include "File.h"

class TextDocument  //: public virtual File//, public Person
{
protected:
	std::string keywords;
	std::string placing;
	int archivingDegree;
	File file;
	Person author;
public:
	TextDocument();
	TextDocument(std::string keywords_, std::string placing_, int archivingDegree_, File *file_, Person *author_);
	void setArchivingDegree(int archivingDegree_);
	std::string getKeywords();
	void setKeywords(std::string keywords_);
	std::string getPlacing();
	void setPlacing(std::string placing_);
	void setFile(File *file_);
	void setAuthor(Person *author_);
	void Show();
	File* getFile();
	Person* getPerson();
	int getArchivingDegree();
	~TextDocument();
};
#endif