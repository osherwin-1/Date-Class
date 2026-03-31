// Source.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;
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