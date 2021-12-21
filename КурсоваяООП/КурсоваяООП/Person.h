#ifndef PERSON_H
#define PERSON_H
#include "Date.h"

class Person : public virtual Date {
protected:
    std::string name;
    std::string surname;
public:
    Person();
    Person(std::string name_, std::string surname_);
    Person(int day_, int month_, int year_, std::string name_, std::string surname_);
    Person(const Person& T);
    std::string getName();
    void setName(std::string name_);
    std::string getSurname();
    void setSurname(std::string surname_);
    void Show();
    int getDay();
    int getMonth();
    int getYear();
    void setDate(int day_, int month_, int year_);
    ~Person();
};
#endif