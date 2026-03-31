
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

Date::Date(int m, int d, int y) { // Constructor with default values
    if (dateValid(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
		month = 1; // Returns to default date if the provided date is invalid
        day = 1;
        year = 1900;
    }
}

void Date::setDate(int m, int d, int y) { // Mutator function to set the date
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

bool Date::dateValid(int m, int d, int y) const { // Function to validate the date
    if (y < 1900 || y > 2100) {
        return false;
    }
    if (m < 1 || m > 12) {
        return false;
    }
    if (d < 1 || d > lastDayOfMonth(m, y)) {
        return false;
    }
    return true;
}

bool Date::isLeapYear() const {
    return isLeapYear(year);
}

bool Date::isLeapYear(int year) const { // Function to check if the year is a leap year
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::lastDayOfMonth() const {
    return lastDayOfMonth(month, year);
}

int Date::lastDayOfMonth(int month, int year) const { // Function to get the last day of a specific month and year
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// Functions to format the date as MM/DD/YYYY, Month Day, Year, and Day Month Year

string Date::formatMMDDYYYY() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

string Date::mmToMonth(int month) {
    const string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return months[month - 1];
}

string Date::formatMonthDayYear() const {
    return mmToMonth(month) + " " + to_string(day) + ", " + to_string(year);
}

string Date::formatDayMonthYear() const {
    return to_string(day) + " " + mmToMonth(month) + " " + to_string(year);
}

Date& Date::operator++() { // Prefix increment operator to advance the date by one day
    day++;
    if (day > lastDayOfMonth()) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}
Date Date::operator++(int) { // Postfix increment operator to advance the date by one day
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator--() { // Prefix decrement operator to move the date back by one day
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = lastDayOfMonth();
    }
    return *this;
}
Date Date::operator--(int) { // Postfix decrement operator to move the date back by one day
    Date temp = *this;
    --(*this);
    return temp;
}

static int toDays(int m, int d, int y) { // Helper function to convert a date to the number of days since 01/01/1900
    int days = d;

    for (int i = 1; i < m; i++) {
		switch (i) { // Switch statement to add the number of days in the months before the given month
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days += 31; break;
        case 4: case 6: case 9: case 11:
            days += 30; break;
        case 2:
            days += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 29 : 28;
            break;
        }
    }

    for (int i = 1; i < y; i++) {
        days += ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365;
    }

    return days;
}
int Date::operator-(const Date& other) const { // Subtraction operator to calculate the difference in days between two dates
    int days1 = toDays(month, day, year);
    int days2 = toDays(other.month, other.day, other.year);
    return days1 - days2;
}

ostream& operator<<(ostream& out, const Date& date) { // Overloaded output operator to print the date in Month Day, Year format
    static const string months[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    out << months[date.month] << " " << date.day << ", " << date.year;
    return out;
}

istream& operator>>(istream& in, Date& date) { // Overloaded input operator to read the date in MM DD YYYY format
    int m, d, y;
    cout << "Enter month day year (MM DD YYYY): ";
    in >> m >> d >> y;

    if (date.dateValid(m, d, y)) {
        date.setDate(m, d, y);
    }
    else {
        cout << "Invalid date. Keeping previous value.\n";
    }

    return in;
}