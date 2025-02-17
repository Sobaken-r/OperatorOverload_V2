#include "Date.h" 
#include <iostream> 
#include <Windows.h> 
using namespace std;

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setAge(int age)
{
    this->age = age;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getAge() const
{
    return age;
}


Date::Date()
{
    day = 0;
    month = 0;
    age = 0;
}

Date::Date(int day, int month, int age) : day{ day }, month{ month }, age{ age } {}

void Date::Print() const
{
    cout << "Дата:" << day << ":" << month << ":" << age << endl;
}

Date& Date::operator++()
{
    day++;
    if (day > 30)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            age++;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--()
{
    day--;
    if (day < 1)
    {
        day = 30;
        month--;
        if (month < 1)
        {
            month = 12;
            age--;
        }
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

Date& Date::operator=(const Date& date)
{
    day = date.day;
    month = date.month;
    age = date.age;
    return *this;
}

Date& Date::operator+=(const Date& date)
{
    int count_month = 0, count_age = 0;
    day += date.day;
    month += date.month;
    age += date.age;
    if (day > 30)
    {
        if (day > 30)
        {
            while (day > 30)
            {
                day -= 30;
                count_month++;
            }
        }
        month += count_month;
        if (month > 12)
        {
            while (month > 12)
            {
                month -= 12;
                count_age++;
            }
        }
        age += count_age;
    }
    return *this;
}

Date& Date::operator-=(const Date& date)
{
    int count_month = 0, count_age = 0;

    day -= date.day;
    month -= date.month;
    age -= date.age;

    if (day < 0) {

        day += 30;
        month--;
    }

    if (month < 0) {
        month += 12;
        age--;
    }
    count_month = month;
    count_age = age;
    return *this;
}

Date& Date::operator()(const Date& date)
{
    day = date.day;
    month = date.month;
    age = date.age;

    if (day > 15)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            age++;
        }
    }
    else
    {
        day = 1;
    }
    return *this;
}


bool operator!=(const Date& date_1, const Date& date_2)
{
    return date_1.day != date_2.day || date_1.month != date_2.month || date_1.age != date_2.age;
}

bool operator==(const Date& date_1, const Date& date_2)
{
    return date_1.day == date_2.day || date_1.month == date_2.month || date_1.age == date_2.age;
}

bool operator<(const Date& date_1, const Date& date_2)
{
    if (date_1.age != date_2.age)
    {
        return date_1.age < date_2.age;
    }
    if (date_1.month != date_2.month)
    {
        return date_1.month < date_2.month;
    }
    return date_1.day < date_2.day;
}

bool operator>(const Date& date_1, const Date& date_2)
{
    if (date_1.age != date_2.age)
    {
        return date_1.age > date_2.age;
    }
    if (date_1.month != date_2.month) {
        return date_1.month > date_2.month;
    }
    return date_1.day > date_2.day;
}


ostream& operator<<(ostream& out, const Date& date)
{
    out << "Дата:" << date.day << ":" << date.month << ":" << date.age << endl;
    return out;
}

istream& operator>>(istream& in, Date& date)
{
    cout << "День: ";
    in >> date.day;
    cout << "Месяц: ";
    in >> date.month;
    cout << "Год: ";
    in >> date.age;
    cout << endl;
    return in;
}