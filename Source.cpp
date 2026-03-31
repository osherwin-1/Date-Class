// Source.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include "Date.h"
using namespace std;
// Main function to demonstrate the Date class

int main()
{
	Date test0;	// Test for proper object construction
	cout << "Test 0, default date: " << test0.formatMMDDYYYY() << " | " << test0.formatMonthDayYear() << " | " << test0.formatDayMonthYear() << endl;
	
	Date test1(2, 29, 2020); // Valid leap year date
	cout << "Test 1, valid leap year: " << test1.formatMMDDYYYY() << " | " << test1.formatMonthDayYear() << " | " << test1.formatDayMonthYear() << endl;

	Date test2(2, 29, 2009); // Invalid leap year date, should default to 01/01/1900
	cout << "Test 2, invalid leap year: " << test2.formatMMDDYYYY() << " | " << test2.formatMonthDayYear() << " | " << test2.formatDayMonthYear() << endl;

	Date test3(4, 20, 2021); // Valid date
	cout << "Test 3, valid date: " << test3.formatMMDDYYYY() << " | " << test3.formatMonthDayYear() << " | " << test3.formatDayMonthYear() << endl;

	Date test4(1, 33, 2000); // Invalid date, should default to 01/01/1900
	cout << "Test 4, invalid date: " << test4.formatMMDDYYYY() << " | " << test4.formatMonthDayYear() << " | " << test4.formatDayMonthYear() << endl;

	Date test5(13, 45, 2018); // Invalid month, should default to 01/01/1900
	cout << "Test 5, invalid month: " << test5.formatMMDDYYYY() << " | " << test5.formatMonthDayYear() << " | " << test5.formatDayMonthYear() << endl;

	Date test6(4, 31, 2000); // Invalid month length, should default to 01/01/1900
	cout << "Test 6, invalid month length: " << test6.formatMMDDYYYY() << " | " << test6.formatMonthDayYear() << " | " << test6.formatDayMonthYear() << endl;
	
	// Modified tests

	cout << "Subtraction Operator Tests" << endl; // Tests for the subtraction operator to calculate the difference in days between two dates
	Date d1(4, 18, 2014);
	Date d2(4, 10, 2014);
	cout << d1.formatMMDDYYYY() << " - " << d2.formatMMDDYYYY()
		<< " = " << (d1 - d2) << " days (should result in 8)" << endl;
	Date d3(2, 2, 2006);
	Date d4(11, 10, 2003);
	cout << d3.formatMMDDYYYY() << " - " << d4.formatMMDDYYYY()
		<< " = " << (d3 - d4) << " days (should result in 815)" << endl;
	
	cout << "Increment & Decrement Tests - Leap Year" << endl; // Tests for the increment and decrement operators to ensure they correctly handle leap years and year boundaries
	Date leapY(2, 29, 2008);
	cout << "Original date: " << leapY << endl;
	cout << "Prefix ++: " << ++leapY << endl;   // 3/1/2008
	cout << "Prefix --: " << --leapY << endl;   // 2/29/2008
	cout << "Postfix ++: " << leapY++ << endl;  // 2/29/2008
	cout << "After postfix, date: " << leapY << endl; // 3/1/2008
	cout << "Postfix --: " << leapY-- << endl;  // 3/1/2008
	cout << "After postfix, date: " << leapY << endl; // 2/29/2008
	
	
	cout << "Increment & Decrement Tests - Year Boundary" << endl;
	Date yearEnd(12, 31, 2024);
	cout << "Original date: " << yearEnd << endl;
	cout << "Postfix ++: " << yearEnd++ << endl;   // 12/31/2024
	cout << "After postfix, date: " << yearEnd << endl; // 1/1/2025
	cout << "Postfix --: " << yearEnd-- << endl;   // 1/1/2025
	cout << "After postfix, date: " << yearEnd << endl; // 12/31/2024

	cout << "Prefix ++: " << ++yearEnd << endl;    // 1/1/2025
	cout << "Prefix --: " << --yearEnd << endl;    // 12/31/2024

	Date inputDate; // Test for the overloaded input operator to read a date from the user
	cin >> inputDate;
	cout << "Date entered:" << inputDate << endl;
	cout << "Formatted date (MM/DD/YYYY): " << inputDate.formatMMDDYYYY() << endl;
	cout << "Formatted date (Month Day, Year): " << inputDate.formatMonthDayYear() << endl;
	cout << "Formatted date (Day Month Year): " << inputDate.formatDayMonthYear() << endl;

	return 0;
}