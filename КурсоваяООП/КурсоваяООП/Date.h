#ifndef DATE_H
#define DATE_H
#include <string>
//базовий клас: Дата (Рік, Місяць, День); 

class Date {
protected:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day_, int month_, int year_);
    Date(const Date& T);
    virtual int getDay();
    void setDay(int day_);
    virtual  int getMonth();
    void setMonth(int month_);
    virtual int getYear();
    void setYear(int year_);
    virtual void Show();
    virtual void setDate(int day_, int month_, int year_);
    //virtual void ShowYear();
    virtual ~Date();
};
#endif