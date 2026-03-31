#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Date::Date(int m, int d, int y) {
    if (dateValid(m, d, y)) {
        month = m;
        day = d;
        year = y;
    }
    else {
        month = 1;
        day = 1;
        year = 1900;
    }
}

// Validation 
bool Date::dateValid(int m, int d, int y) const {
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > lastDayOfMonth(m, y)) return false;
    return true;
}

bool Date::isLeapYear() const { return isLeapYear(year); }

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Last Day of Month
int Date::lastDayOfMonth() const { return lastDayOfMonth(month, year); }

int Date::lastDayOfMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

// Set
void Date::setDate(int m, int d, int y) {
    if (dateValid(m, d, y)) {
        month = m; day = d; year = y;
    }
    else {
        month = 1; day = 1; year = 1900;
    }
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

// Format
static string mmToMonth(int m) {
    const string months[] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    return months[m - 1];
}

string Date::formatMMDDYYYY() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::formatMonthDayYear() const {
    return mmToMonth(month) + " " + to_string(day) + ", " + to_string(year);
}

string Date::formatDayMonthYear() const {
    return to_string(day) + " " + mmToMonth(month) + " " + to_string(year);
}

// Increment / Decrement
Date& Date::operator++() { // prefix
    day++;
    if (day > lastDayOfMonth()) {
        day = 1;
        month++;
        if (month > 12) { month = 1; year++; }
    }
    return *this;
}

Date Date::operator++(int) { // postfix
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() { // prefix
    day--;
    if (day < 1) {
        month--;
        if (month < 1) { month = 12; year--; }
        day = lastDayOfMonth();
    }
    return *this;
}

Date Date::operator--(int) { // postfix
    Date temp = *this;
    --(*this);
    return temp;
}

//  Subtraction
static int toDays(int m, int d, int y) {
    int days = d;
    for (int i = 1; i < m; i++) {
        switch (i) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: days += 31; break;
        case 4: case 6: case 9: case 11: days += 30; break;
        case 2: days += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 29 : 28; break;
        }
    }
    for (int i = 1; i < y; i++)
        days += ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365;
    return days;
}

int Date::operator-(const Date& other) const {
    return toDays(month, day, year) - toDays(other.month, other.day, other.year);
}

//  Stream Operators
ostream& operator<<(ostream& out, const Date& date) {
    out << mmToMonth(date.month) << " " << date.day << ", " << date.year;
    return out;
}

istream& operator>>(istream& in, Date& date) {
    int m, d, y;
    cout << "Enter month day year (MM DD YYYY): ";
    in >> m >> d >> y;
    if (date.dateValid(m, d, y)) date.setDate(m, d, y);
    else cout << "Invalid date. Keeping previous value.\n";
    return in;
}