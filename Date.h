#pragma once
#define DATE_H
#include <iostream>

class Date {
private:
	int month;
	int day;
	int year;
	bool dateValid(int m, int d, int y) const;

public:
	
	Date(int m = 1, int d = 1, int y = 1900); // Constructor with default values

	Date& operator++(); // prefix increment operator to advance the date by one day
	Date& operator--(); // prefix decrement operator to move the date back by one day

	Date operator++(int); // postfix increment operator to advance the date by one day
	Date operator--(int); // postfix decrement operator to move the date back by one day

	int operator-(const Date& other) const; // Subtraction operator to calculate the difference in days between two dates

	friend std::ostream& operator<<(std::ostream& os, const Date& date); // Overloaded output operator to print the date in MM/DD/YYYY format
	friend std::istream& operator>>(std::istream& is, Date& date); // Overloaded input operator to read the date in MM/DD/YYYY format

	void setDate(int m, int d, int y); // Mutator function to set the date

	int getMonth() const; // Accessor function to get the month
	int getDay() const; // Accessor function to get the day
	int getYear() const; // Accessor function to get the year

	bool isLeapYear() const; // Function to check if the year is a leap year
	bool isLeapYear(int y) const; // Overloaded function to check if a specific year is a leap year

	int lastDayOfMonth() const; // Function to get the last day of the month
	int	lastDayOfMonth(int m, int y) const; // Overloaded function to get the last day of a specific month and year

	string formatMMDDYYYY() const; // Function to format the date as MM/DD/YYYY
	string formatMonthDayYear() const; // Function to format the date as Month Day, Year
	string formatDayMonthYear() const; // Function to format the date as Day Month Year
};
