#include <iostream> 
#include <Windows.h> 
#include "Date.h" 
using namespace std;

int main()
{
    setlocale(0, "");

    Date d1 = { 15,10,2021 };
    Date d2 = { 10, 10, 2010 };
    Date d4 = { 1,1,1 };
    d1.Print();

    d1++;
    d1.Print();

    d1--;
    d1.Print();

    bool valid = d1 != d2;
    cout << valid << endl;

    bool valid_1 = d1 == d2;
    cout << valid << endl;

    bool valid_2 = d1 > d2;
    cout << valid << endl;

    bool valid_3 = d1 < d2;
    cout << valid << endl;

    Date d3 = d2;
    d3.Print();

    d2 -= d4;
    d2.Print();

    cout << d2;
    Date temp;
    cin >> temp;
    temp.Print();

    Date date{ 20,10,2003 };
    date(date);
    date.Print();

    Date temp1{ 20,12,3000 };
    Date temp2{ 20,12,100 };
    bool t = temp2 < temp1;
    cout << t;
}