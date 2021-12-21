#ifndef FILE_H
#define FILE_H
#include "Date.h"

class File : public virtual Date {
protected:
    std::string nameOfFile;
    std::string extension;
   
public:
    int size;
    File();
    File(std::string nameOfFile_, std::string extension_, int size_);
    File(int day_, int month_, int year_, std::string nameOfFile_, std::string extension_, int size_);
    File(const File& T);
    void setDate(int day_, int month_, int year_);
    std::string getNameOfFile();
    void setNameOfFile(std::string nameOfFile_);
    std::string getExtension();
    void setExtension(std::string extension_);
    int getSize();
    void setSize(int size_);
    int getDay();
    int getMonth();
    int getYear();
    void Show();
    ~File();
};
#endif