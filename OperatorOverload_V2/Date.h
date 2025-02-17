#pragma once 
#include <iostream> 
using namespace std;
class Date
{
    int day;
    int month;
    int age;
public:
    void setDay(int day);
    void setMonth(int month);
    void setAge(int age);

    int getDay() const;
    int getMonth() const;
    int getAge() const;

    Date();
    Date(int day, int month, int age);

    void Print() const;

    Date& operator++();
    Date operator++(int);

    Date& operator--();
    Date operator--(int);

    Date& operator=(const Date& date);
    Date& operator+=(const Date& date);
    Date& operator-=(const Date& date);
    Date& operator()(const Date& date);

    friend bool operator!=(const Date& date_1, const Date& date_2);
    friend bool operator==(const Date& date_1, const Date& date_2);
    friend bool operator>(const Date& date_1, const Date& date_2);
    friend bool operator<(const Date& date_1, const Date& date_2);

    friend ostream& operator<<(ostream& out, const Date& date);
    friend istream& operator>>(istream& in, Date& date);

};