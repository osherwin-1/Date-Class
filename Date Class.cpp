// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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

string mmToMonth(int month) {
    const string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return months[month - 1];
}

string Date::formatMonthDayYear() const {
    return mmToMonth(month) + " " + to_string(day) + ", " + to_string(year);
}

string Date::formatDayMonthYear() const {
    return to_string(day) + " " + mmToMonth(month) + " " + to_string(year);
}

// Main function to demonstrate the Date class

int main()
{
   
	Date test1(2, 29, 2020); // Valid leap year date
	cout << "Test 1, valid leap year: " << test1.formatMMDDYYYY() << " | " << test1.formatMonthDayYear() << " | " << test1.formatDayMonthYear() << endl;

	Date test2(2, 29, 2019); // Invalid leap year date, should default to 01/01/1900
	cout << "Test 2, invalid leap year: " << test2.formatMMDDYYYY() << " | " << test2.formatMonthDayYear() << " | " << test2.formatDayMonthYear() << endl;
    
	Date test3(4, 20, 2021); // Valid date
	cout << "Test 3, valid date: " << test3.formatMMDDYYYY() << " | " << test3.formatMonthDayYear() << " | " << test3.formatDayMonthYear() << endl;
    
    Date test4(1, 33, 2000); // Invalid date, should default to 01/01/1900
	cout << "Test 4, invalid date: " << test4.formatMMDDYYYY() << " | " << test4.formatMonthDayYear() << " | " << test4.formatDayMonthYear() << endl;

	Date test5(13, 15, 2020); // Invalid month, should default to 01/01/1900
	cout << "Test 5, invalid month: " << test5.formatMMDDYYYY() << " | " << test5.formatMonthDayYear() << " | " << test5.formatDayMonthYear() << endl;

	Date test6(11, 31, 2001); // Invalid month length, should default to 01/01/1900
    cout << "Test 6, invalid month length: " << test6.formatMMDDYYYY() << " | " << test6.formatMonthDayYear() << " | " << test6.formatDayMonthYear() << endl;
	return 0;
}